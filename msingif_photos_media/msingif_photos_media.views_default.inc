<?php
/**
 * @file
 * msingif_photos_media.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function msingif_photos_media_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'photo_media_browser';
  $view->description = 'Media browser for photo\'s';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Photo Media browser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Foto\'s';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Terug zetten';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'media_browser';
  /* Relatie: File Usage: Inhoud */
  $handler->display->display_options['relationships']['file_to_node']['id'] = 'file_to_node';
  $handler->display->display_options['relationships']['file_to_node']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['file_to_node']['field'] = 'file_to_node';
  $handler->display->display_options['relationships']['file_to_node']['required'] = 0;
  /* Veld: Bestand: Naam */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['html'] = 0;
  $handler->display->display_options['fields']['filename']['hide_empty'] = 0;
  $handler->display->display_options['fields']['filename']['empty_zero'] = 0;
  $handler->display->display_options['fields']['filename']['link_to_file'] = 1;
  /* Sorteercriterium: Volgorde: Weight (weight) */
  $handler->display->display_options['sorts']['weight_value']['id'] = 'weight_value';
  $handler->display->display_options['sorts']['weight_value']['table'] = 'field_data_weight';
  $handler->display->display_options['sorts']['weight_value']['field'] = 'weight_value';
  $handler->display->display_options['sorts']['weight_value']['relationship'] = 'file_to_node';
  $handler->display->display_options['sorts']['weight_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['weight_value']['expose']['label'] = 'Volgorde';
  /* Sorteercriterium: Bestand: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Upload date';
  /* Sorteercriterium: Inhoud: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'file_to_node';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Naam';
  /* Filtercriterium: Bestand: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 0;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'file_to_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'photo' => 'photo',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filtercriterium: Bestand: Naam */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 0;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Naam';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['required'] = 0;
  $handler->display->display_options['filters']['filename']['expose']['multiple'] = FALSE;
  /* Filtercriterium: Inhoud: Album (field_photo_album) */
  $handler->display->display_options['filters']['field_photo_album_nid']['id'] = 'field_photo_album_nid';
  $handler->display->display_options['filters']['field_photo_album_nid']['table'] = 'field_data_field_photo_album';
  $handler->display->display_options['filters']['field_photo_album_nid']['field'] = 'field_photo_album_nid';
  $handler->display->display_options['filters']['field_photo_album_nid']['relationship'] = 'file_to_node';
  $handler->display->display_options['filters']['field_photo_album_nid']['group'] = 0;
  $handler->display->display_options['filters']['field_photo_album_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_photo_album_nid']['expose']['operator_id'] = 'field_photo_album_nid_op';
  $handler->display->display_options['filters']['field_photo_album_nid']['expose']['label'] = 'Album';
  $handler->display->display_options['filters']['field_photo_album_nid']['expose']['operator'] = 'field_photo_album_nid_op';
  $handler->display->display_options['filters']['field_photo_album_nid']['expose']['identifier'] = 'field_photo_album_nid';
  $handler->display->display_options['filters']['field_photo_album_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_photo_album_nid']['expose']['reduce'] = 0;

  /* Display: Photos */
  $handler = $view->new_display('media_browser', 'Photos', 'photo_media_browser');
  $translatables['photo_media_browser'] = array(
    t('Master'),
    t('Foto\'s'),
    t('meer'),
    t('Toepassen'),
    t('Terug zetten'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Inhoud'),
    t('Volgorde'),
    t('Upload date'),
    t('Naam'),
    t('Album'),
    t('Photos'),
  );
  $export['photo_media_browser'] = $view;

  return $export;
}
