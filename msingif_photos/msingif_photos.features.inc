<?php
/**
 * @file
 * msingif_photos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function msingif_photos_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function msingif_photos_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function msingif_photos_node_info() {
  $items = array(
    'photo' => array(
      'name' => t('Photo'),
      'base' => 'node_content',
      'description' => t('Add one ore more <em>photo\'s</em> to a photo album.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'photo_album' => array(
      'name' => t('Photo album'),
      'base' => 'node_content',
      'description' => t('Use <em>photo album</em> to group one or more photo\'s.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
