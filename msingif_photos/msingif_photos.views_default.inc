<?php
/**
 * @file
 * msingif_photos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function msingif_photos_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'photo_albums';
  $view->description = 'Overview of all photo albums';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo albums';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photos';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'title';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Content: Album (field_photo_album) - reverse */
  $handler->display->display_options['relationships']['reverse_field_photo_album_node']['id'] = 'reverse_field_photo_album_node';
  $handler->display->display_options['relationships']['reverse_field_photo_album_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_photo_album_node']['field'] = 'reverse_field_photo_album_node';
  $handler->display->display_options['relationships']['reverse_field_photo_album_node']['required'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo_photo']['id'] = 'field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['table'] = 'field_data_field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['field'] = 'field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['relationship'] = 'reverse_field_photo_album_node';
  $handler->display->display_options['fields']['field_photo_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_photo_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_photo_photo']['group_column'] = 'title';
  $handler->display->display_options['fields']['field_photo_photo']['field_api_classes'] = 0;
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
    'photo_album' => 'photo_album',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['relationship'] = 'reverse_field_photo_album_node';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Album overview */
  $handler = $view->new_display('page', 'Album overview', 'page');
  $handler->display->display_options['path'] = 'photos';
  $translatables['photo_albums'] = array(
    t('Master'),
    t('Photos'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_photo_album'),
    t('node/[nid]'),
    t('Album overview'),
  );
  $export['photo_albums'] = $view;

  return $export;
}