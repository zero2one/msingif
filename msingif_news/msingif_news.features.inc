<?php
/**
 * @file
 * msingif_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function msingif_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function msingif_news_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function msingif_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('Nieuws'),
      'base' => 'node_content',
      'description' => t('Gebruik een <em>nieuws</em> item om datum gerelateerde verhalen te plaatsen.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
