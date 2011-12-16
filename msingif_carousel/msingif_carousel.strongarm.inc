<?php
/**
 * @file
 * msingif_carousel.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function msingif_carousel_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_carousel';
  $strongarm->value = '0';
  $export['language_content_type_carousel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_carousel';
  $strongarm->value = array();
  $export['menu_options_carousel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_carousel';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_carousel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_carousel';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_carousel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_carousel';
  $strongarm->value = '1';
  $export['node_preview_carousel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_carousel';
  $strongarm->value = 0;
  $export['node_submitted_carousel'] = $strongarm;

  return $export;
}
