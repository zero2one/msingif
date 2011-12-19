<?php
/**
 * @file
 * msingif_photos.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function msingif_photos_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'msingif_photo_album';
  $context->description = 'Photo album photos';
  $context->tag = 'Photos';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'photo_album' => 'photo_album',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-photo_album-overview' => array(
          'module' => 'views',
          'delta' => 'photo_album-overview',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Photo album photos');
  t('Photos');
  $export['msingif_photo_album'] = $context;

  return $export;
}
