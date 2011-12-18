<?php
/**
 * @file
 * msingif_carousel.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function msingif_carousel_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'msingif_carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'counter' => 'counter',
    'field_carousel_link' => 0,
    'field_carousel_image' => 0,
    'title' => 0,
    'field_carousel_description' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_carousel_link' => 0,
    'field_carousel_image' => 0,
    'title' => 0,
    'field_carousel_description' => 0,
    'counter' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['fixed_height'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_carousel_link']['id'] = 'field_carousel_link';
  $handler->display->display_options['fields']['field_carousel_link']['table'] = 'field_data_field_carousel_link';
  $handler->display->display_options['fields']['field_carousel_link']['field'] = 'field_carousel_link';
  $handler->display->display_options['fields']['field_carousel_link']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_carousel_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_carousel_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_carousel_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_carousel_link']['field_api_classes'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_carousel_image']['id'] = 'field_carousel_image';
  $handler->display->display_options['fields']['field_carousel_image']['table'] = 'field_data_field_carousel_image';
  $handler->display->display_options['fields']['field_carousel_image']['field'] = 'field_carousel_image';
  $handler->display->display_options['fields']['field_carousel_image']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['path'] = '[field_carousel_link]';
  $handler->display->display_options['fields']['field_carousel_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_carousel_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_carousel_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_carousel_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_carousel_image']['settings'] = array(
    'image_style' => 'carousel',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_carousel_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_carousel_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_carousel_description']['id'] = 'field_carousel_description';
  $handler->display->display_options['fields']['field_carousel_description']['table'] = 'field_data_field_carousel_description';
  $handler->display->display_options['fields']['field_carousel_description']['field'] = 'field_carousel_description';
  $handler->display->display_options['fields']['field_carousel_description']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_carousel_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_carousel_description']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_carousel_description']['field_api_classes'] = 0;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['external'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['html'] = 0;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['counter']['hide_empty'] = 0;
  $handler->display->display_options['fields']['counter']['empty_zero'] = 0;
  $handler->display->display_options['fields']['counter']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'carousel' => 'carousel',
  );

  /* Display: Front */
  $handler = $view->new_display('block', 'Front', 'front');
  $handler->display->display_options['display_description'] = 'Front page carousel';
  $translatables['msingif_carousel'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[field_carousel_link]'),
    t('Front'),
    t('Front page carousel'),
  );
  $export['msingif_carousel'] = $view;

  return $export;
}
