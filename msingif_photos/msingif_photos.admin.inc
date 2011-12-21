<?php
/**
 * @file
 * 
 * Admin page callbacks for the photos module.
 */

/**
 * Form constructor for the photos configuration
 *
 * @see msingif_photos_settings_form_validate()
 * @see msingif_photos_settings_form_submit()
 * @ingroup forms
 */
function msingif_photos_settings_form($form, &$form_state) {
  $infos = array(
    'photo_thumb' => array(
      'title' => t('Thumbnail image style'),
      'info'  => t('Configure the image size for display on the album page.'),
    ),
    'photo_block' => array(
      'title' => t('Block image style'),
      'info'  => t('Configure the image size for display in a block.'),
    ),
    'photo_view' => array(
      'title' => t('View image style'),
      'info'  => t('Configure the image size for display on a photo node page.'),
    ),
  );
  
  $styles = msingif_photos_image_default_styles();
  foreach($styles AS $name => $style) {
    $title = (empty($infos[$name]['title'])) 
      ? $name
      : $infos[$name]['title'];
    $info  = (empty($infos[$name]['info']))
      ? t('Configure the %style style.', array('%style' => $name))
      : $infos[$name]['info'];
      
    $form[$name] = array(
      '#type'          => 'fieldset',
      '#title'         => $title,
    );
    $form[$name]['info'] = array(
      '#markup'        => '<p>' . $info . '</p>',
    );
    $form[$name]['msingif_photos_style_' . $name . '_width'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Image width'),
      '#description'   => t('Define the display width'),
      '#default_value' => _msingif_photos_style_get_size($name, 'width'),
      '#size'          => 4,
      '#maxlength'     => 4,
    );
    $form[$name]['msingif_photos_style_' . $name . '_height'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Image height'),
      '#description'   => t('Define the display height'),
      '#default_value' => _msingif_photos_style_get_size($name, 'height'),
      '#size'          => 4,
      '#maxlength'     => 4,
    );
  }
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type'          => 'submit',
    '#value'         => t('Save configuration'),
  );
  
  return $form;
}

/**
 * Validator for the msingif_photos_settings_form()
 * 
 * @see msingif_photos_settings_form_submit()
 */
function msingif_photos_settings_form_validate($form, &$form_state) {
  // image size
  $image_size = _msingif_photos_settings_styles_keys();
  foreach($image_size AS $size) {
    $value = $form_state['values'][$size];
    
    if(!empty($value) && !is_numeric($value)) {
      form_set_error($size, t('The value should be a numeric value.'));
    }
  }
 
}

/**
 * Submit handler for the msingif_photos_settings_form()
 * 
 * @see msingif_photos_settings_form_validate()
 */
function msingif_photos_settings_form_submit($form, $form_state) {
  $values = $form_state['values'];

  // image size
  $image_size = _msingif_photos_settings_styles_keys();
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
  $styles = msingif_photos_image_default_styles();
  foreach($styles AS $name => $settings) {
    $style = image_style_load($name);
    image_style_flush($style);
  }
  
  // some nice feedback
  drupal_set_message(t('Configuration saved.'));
}


/**
 * Get all the possible image size variable keys
 * 
 * @param  void
 * 
 * @return array
 */
function _msingif_photos_settings_styles_keys() {
  $keys = array();
  
  if(empty($keys)) {
    $styles = msingif_photos_image_default_styles();
    
    foreach($styles AS $name => $style) {
      $keys[] = 'msingif_photos_style_' . $name . '_width';
      $keys[] = 'msingif_photos_style_' . $name . '_height';
    }
  }
  
  return $keys;
}
