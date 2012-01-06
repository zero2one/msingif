<?php
/**
 * @file
 * msingif_photos_media.features.inc
 */

/**
 * Implements hook_views_api().
 */
function msingif_photos_media_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
