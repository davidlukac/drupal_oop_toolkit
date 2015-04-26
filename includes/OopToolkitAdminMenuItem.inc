<?php

/**
 * @file
 * File OopToolkitAdminMenuItem.inc.
 */

/**
 * Class OopToolkitAdminMenuItem.
 */
class OopToolkitAdminMenuItem extends MenuItem {

  protected $title = "OPP Toolkit Administration";
  protected $description = 'Configuration and administration pages for OOP Toolkit module.';
  protected $pageCallback = 'drupal_get_form';
  protected $pageArguments;
  protected $accessArguments;
  protected $type = self::MENU_NORMAL_ITEM;

  /**
   * Initialisation function implementation.
   */
  protected function initialise() {
    $callback_name = oop_toolkit_settings_form(NULL, new stdClass(), TRUE);
    $this->setPageArguments($callback_name);
    $this->setAccessArguments(array('access administration pages'));
  }

}
