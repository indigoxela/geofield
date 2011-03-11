<?php


/**
 * Implements hook_field_formatter_info().
 *
 */
function geofield_field_formatter_info() {
  return array(
    'default' => array(
      'label' => t('Display Nothing'),
      'field types' => array('geofield'),
    ),
    'wkt' => array(
      'label' => t('Display WKT'),
      'field types' => array('geofield'),
    ),
    'lat' => array(
      'label' => t('Latitude Only'),
      'field types' => array('geofield'),
    ),
    'lon' => array(
      'label' => t('Longitude Only'),
      'field types' => array('geofield'),
    ),
  );
}

function geofield_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
   switch ($display['type']) {
    case 'wkt':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['wkt']);
      }
      return $element;
    case 'lat':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['lat']);
      }
      return $element;
    case 'lon':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $item['lon']);
      }
      return $element;
  }
}