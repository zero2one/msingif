<?php
/**
 * @file
 * msingif_carousel.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function msingif_carousel_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'msingif_carousel';
  $context->description = 'Adds a carousel to the home page';
  $context->tag = 'Carousel';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-msingif_carousel-front' => array(
          'module' => 'views',
          'delta' => 'msingif_carousel-front',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds a carousel to the home page');
  t('Carousel');
  $export['msingif_carousel'] = $context;

  return $export;
}
