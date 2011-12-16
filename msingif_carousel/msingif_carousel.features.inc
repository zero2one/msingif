<?php
/**
 * @file
 * msingif_carousel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function msingif_carousel_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function msingif_carousel_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function msingif_carousel_node_info() {
  $items = array(
    'carousel' => array(
      'name' => t('Carousel item'),
      'base' => 'node_content',
      'description' => t('Use <em>carousel items</em> to add highlighted items to the front page carousel.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
