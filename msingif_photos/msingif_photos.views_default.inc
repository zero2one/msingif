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
  $view->name = 'photo_album';
  $view->description = 'Overview of all photo\'s belonging to an album';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo album';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo_photo']['id'] = 'field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['table'] = 'field_data_field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['field'] = 'field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['make_link'] = 0;
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
    'image_style' => 'photo_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_photo_photo']['field_api_classes'] = 0;
  /* Sort criterion: Weight: Weight (weight) */
  $handler->display->display_options['sorts']['weight_value']['id'] = 'weight_value';
  $handler->display->display_options['sorts']['weight_value']['table'] = 'field_data_weight';
  $handler->display->display_options['sorts']['weight_value']['field'] = 'weight_value';
  /* Contextual filter: Content: Album (field_photo_album) */
  $handler->display->display_options['arguments']['field_photo_album_nid']['id'] = 'field_photo_album_nid';
  $handler->display->display_options['arguments']['field_photo_album_nid']['table'] = 'field_data_field_photo_album';
  $handler->display->display_options['arguments']['field_photo_album_nid']['field'] = 'field_photo_album_nid';
  $handler->display->display_options['arguments']['field_photo_album_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_photo_album_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_photo_album_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_photo_album_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_photo_album_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_photo_album_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_photo_album_nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_photo_album_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_photo_album_nid']['validate_options']['types'] = array(
    'photo_album' => 'photo_album',
  );
  $handler->display->display_options['arguments']['field_photo_album_nid']['validate_options']['access'] = '1';
  $handler->display->display_options['arguments']['field_photo_album_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_photo_album_nid']['not'] = 0;
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
    'photo' => 'photo',
  );

  /* Display: Album photos */
  $handler = $view->new_display('block', 'Album photos', 'overview');

  /* Display: Manage album photos */
  $handler = $view->new_display('page', 'Manage album photos', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage album photos';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit own photo_album content';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_photo_photo' => 'field_photo_photo',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_photo_photo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo_photo']['id'] = 'field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['table'] = 'field_data_field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['field'] = 'field_photo_photo';
  $handler->display->display_options['fields']['field_photo_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['field_photo_photo']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_photo_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_photo_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_photo_photo']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 1;
  /* Field: Weight: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'field_data_weight';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['label'] = 'Order';
  $handler->display->display_options['fields']['weight']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['external'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['html'] = 0;
  $handler->display->display_options['fields']['weight']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['weight']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['weight']['hide_empty'] = 0;
  $handler->display->display_options['fields']['weight']['empty_zero'] = 0;
  $handler->display->display_options['fields']['weight']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['weight']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'node/%/manage-photos';
  $translatables['photo_album'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Album photos'),
    t('Manage album photos'),
    t('Photo'),
    t('Title'),
    t('Actions'),
    t('Order'),
  );
  $export['photo_album'] = $view;

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
  $handler->display->display_options['title'] = 'Photo albums';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
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
    'image_style' => 'photo_thumb',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_photo_photo']['group_column'] = 'title';
  $handler->display->display_options['fields']['field_photo_photo']['field_api_classes'] = 0;
  /* Sort criterion: Content: Date (field_photo_album_date) */
  $handler->display->display_options['sorts']['field_photo_album_date_value']['id'] = 'field_photo_album_date_value';
  $handler->display->display_options['sorts']['field_photo_album_date_value']['table'] = 'field_data_field_photo_album_date';
  $handler->display->display_options['sorts']['field_photo_album_date_value']['field'] = 'field_photo_album_date_value';
  $handler->display->display_options['sorts']['field_photo_album_date_value']['order'] = 'DESC';
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
  /* Filter criterion: Content: Album photo (field_photo_album_front) */
  $handler->display->display_options['filters']['field_photo_album_front_value']['id'] = 'field_photo_album_front_value';
  $handler->display->display_options['filters']['field_photo_album_front_value']['table'] = 'field_data_field_photo_album_front';
  $handler->display->display_options['filters']['field_photo_album_front_value']['field'] = 'field_photo_album_front_value';
  $handler->display->display_options['filters']['field_photo_album_front_value']['relationship'] = 'reverse_field_photo_album_node';
  $handler->display->display_options['filters']['field_photo_album_front_value']['value'] = array(
    1 => '1',
  );

  /* Display: Album overview */
  $handler = $view->new_display('page', 'Album overview', 'page_overview');
  $handler->display->display_options['path'] = 'photos';

  /* Display: Album overview Block */
  $handler = $view->new_display('block', 'Album overview Block', 'block_overview');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photo albums';
  $handler->display->display_options['display_description'] = 'A list of all photo album names';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $translatables['photo_albums'] = array(
    t('Master'),
    t('Photo albums'),
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
    t('Album overview Block'),
    t('A list of all photo album names'),
  );
  $export['photo_albums'] = $view;

  return $export;
}
