<?php
/**
 * @file
 * Admin page callbacks for the carousel module.
 */

/**
 * Form constructor for the carousel configuration
 *
 * @see msingif_carousel_settings_form_validate()
 * @see msingif_carousel_settings_form_submit()
 * @ingroup forms
 */
function msingif_carousel_settings_form($form, &$form_state) {
  // configure the carousel image size
  $form['image'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Carousel image style'),
  );
  $form['image']['info'] = array(
    '#markup'        => '<p>' . t('Configure the image size for display on the home page.<br />The image will be scaled and cropped.') . '</p>',
  );
  $form['image']['msingif_carousel_image_width'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Image width'),
    '#description'   => t('Define the display width'),
    '#default_value' => variable_get('msingif_carousel_image_width'),
    '#size'          => 4,
    '#maxlength'     => 4,
  );
  $form['image']['msingif_carousel_image_height'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Image height'),
    '#description'   => t('Define the display height'),
    '#default_value' => variable_get('msingif_carousel_image_height'),
    '#size'          => 4,
    '#maxlength'     => 4,
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type'          => 'submit',
    '#value'         => t('Save configuration'),
  );
  
  return $form;
}

/**
 * Validator for the msingif_carousel_settings_form()
 * 
 * @see msingif_carousel_settings_form_submit()
 */
function msingif_carousel_settings_form_validate($form, &$form_state) {
  // image size
  $image_size = array(
    'msingif_carousel_image_width', 
    'msingif_carousel_image_height'
  );
  foreach($image_size AS $size) {
    $value = $form_state['values'][$size];
    
    if(!empty($value) && !is_numeric($value)) {
      form_set_error($size, t('The value should be a numeric value.'));
    }
  }
 
}

/**
 * Submit handler for the msingif_carousel_settings_form()
 * 
 * @see msingif_carousel_settings_form_validate()
 */
function msingif_carousel_settings_form_submit($form, $form_state) {
  $values = $form_state['values'];

  // image size
  $image_size = array(
    'msingif_carousel_image_width', 
    'msingif_carousel_image_height'
  );
  foreach($image_size AS $size) {
    if(empty($values[$size])) {
      variable_set($size, NULL);
    }
    else {
      variable_set($size, (int)$values[$size]);
    }
  }
  
  // flush the image styles cache
  cache_clear_all('image_styles', 'cache');
  
  // flush the already created media
  $style = image_style_load('carousel');
  image_style_flush($style);
  
  // some nice feedback
  drupal_set_message(t('Configuration saved.'));
}


