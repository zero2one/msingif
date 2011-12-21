<?php
/**
 * @file
 * 
 * Holds all the multi photo upload logic
 */

 
/**
 * Form to upload multiple photo's at once for the given photo album
 * 
 * @param  $form
 * @param  $form_state
 * @param  $photo_album
 *     The photo album node
 * 
 * @return array
 * 
 * @see msingif_photos_multi_upload_form()
 * @see msingif_photos_multi_upload_form_submit()
 * @ingroup forms
 */
function _msingif_photos_multi_upload_form(&$form, $form_state, $photo_album) {
  
  $form['photo_album'] = array(
    '#type'        => 'value',
    '#value'       => $photo_album,
  );
  
  // @todo: get the alowed file types from the photo node file field
  $form['photos'] = array(
    '#type'              => 'plupload',
    '#title'             => t('Photos'),
    '#description'       => t('Upload one or more photos.'),
    '#required'          => TRUE,
    '#upload_validators' => array('file_validate_extensions' => array(
      'png jpg gif'
    )),
    '#id'                => 'photo-album-photos',
  );
  
  $form['submit'] = array(
    '#type'              => 'submit',
    '#value'             => t('Upload'),
  );
  
  return $form;
}

/**
 * Submit the multi upload form
 * 
 * @param  $form
 * @param  $form_state
 * 
 * @return void
 * 
 * @see msingif_photos_multi_upload_form()
 */
function _msingif_photos_multi_upload_form_submit($form, &$form_state) {
  // get the values
  $values      = $form_state['values'];
  $photo_album = $values['photo_album'];
  $language    = LANGUAGE_NONE;
  
  // create a Photo node object
  $default = new StdClass();
  $default->type = 'photo';
  $default->language = $photo_album->language;
  node_object_prepare($default);
  
  // Album id
  $default->field_photo_album[$language][0]['nid'] = (int)$photo_album->nid;
  
  // Prepare the file directory
  // @todo: get the file path from the photo node field settings
  $path = array('://msingif', 'photo', (int)$photo_album->nid);
  $path = implode('/', $path); 

  $scheme = file_default_scheme();
  $destination_path = $scheme . $path;
  file_prepare_directory(
    $destination_path, 
    FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS
  );
  
  // Loop through the photo's, create a node for each photo
  $count = 0;
  foreach($values['photos'] AS $key => $photo) {
    if($photo['status'] != 'done') {
      form_set_error('photo', t(
        'Upload of %photo failed', array('%photo' => $photo['name'])
      ));
      continue;
    }
    
    $source = $photo['tmppath'];
    $destination = file_stream_wrapper_uri_normalize($destination_path . '/' . $photo['name']);
    // Rename it to its original name, and put it in its final home.
    // Note - not using file_move here because if we call file_get_mime
    // (in file_uri_to_object) while it has a .tmp extension, it horks.
    $destination = file_unmanaged_move($source, $destination, FILE_EXISTS_RENAME);
    $file = file_uri_to_object($destination);
    
    file_save($file);
    
    $node = clone $default;
    $node->title = $photo['name'];
    $node->field_photo_photo[$language][0] = (array)$file;
    
    node_save($node);
    $count++;
  }
  
  drupal_set_message(format_plural(
    $count, 
    '1 photo uploaded.', 
    "@count photo's uploaded",
    array('@count' => $count)
  ));
  
  $form_state['redirect'] = 'node/' . $photo_album->nid;
}
