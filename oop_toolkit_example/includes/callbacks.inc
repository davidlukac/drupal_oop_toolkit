<?php

/**
 * @file
 * File callbacks.inc contains special implementation of all needed callbacks.
 *
 * Special implementation, because the callbacks return their name in a string
 * when 'getName' parameter is set to TRUE.
 */

/**
 * Form builder - implements hook_form().
 *
 * Example administration page using Variable class.
 *
 * @param array $form
 *   Form.
 * @param mixed $form_state
 *   Form state.
 * @param bool $get_name
 *   Flag - if set to TRUE, function returns it's name as string.
 *
 * @return mixed
 *   String or system form.
 */
function oop_toolkit_example_settings_form(array $form, &$form_state, $get_name = FALSE) {
  // This is a callback function, so if we want to reference it
  // in different way, than by string, we need a 'flag' argument
  // saying we need the function name to be returned.
  if ($get_name) {
    return __FUNCTION__;
  }

  /* @var $example_var \OopToolkitExampleExampleVariable */
  $example_var = OopToolkitExampleExampleVariable::getInstance();

  $form = array();

  $form[$example_var->getName()] = array(
    '#type' => 'textfield',
    '#title' => t('Example settings form'),
    '#default_value' => $example_var->getDefault(),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t("Some example description text to be added here."),
    '#required' => TRUE,
  );

  // TODO! You probably don't need validation or submit handlers if using system_settings_form().
  return system_settings_form($form);
}
