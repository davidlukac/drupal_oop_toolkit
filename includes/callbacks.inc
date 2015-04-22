<?php

/**
 * Form builder.
 *
 * @param $form
 * @param $form_state
 * @param bool $getName
 * @return string
 */
function oop_toolkit_settings_form($form, &$form_state, $getName = FALSE) {
  // This is a callback function, so if we want to reference it in different way,
  // than by string, we need a 'flag' argument saying we need the function name
  // to be returned.
  if ($getName) {
    return __FUNCTION__;
  }

  $form['oop_toolkit_variable_foo'] = array(
    '#type' => 'textfield',
    '#title' => t('Foo'),
    '#default_value' => variable_get('oop_toolkit_variable_foo', 42),
    '#required' => TRUE,
  );

  // TODO! You probably don't need validation or submit handlers if using system_settings_form().
  return system_settings_form($form);
}
