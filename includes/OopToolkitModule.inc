<?php

/**
 * @file
 * OopToolkitModule class.
 */

/**
 * Class OopToolkitModule.
 */
class OopToolkitModule extends Module {

  protected $name = 'oop_toolkit';
  protected $urlName = 'oop_toolkit';
  protected $helpText = "Helper module for developer which provides classes and functions to work with Drupal in OOP manner.";

  /**
   * Module initialisation.
   *
   * This function is called once, when the Module is being instantiated.
   */
  protected function initialise() {
    /* @var $admin_menu \OopToolkitAdminMenuItem */
    $admin_menu = OopToolkitAdminMenuItem::getInstance();
    // Let's inject module to the menu item, so it's aware of it's context.
    $this->addMenuItem($admin_menu);
    // @TODO: Probably we want to do DI in some other way, not in initialisation function of a Singleton. Probably some Factory pattern.
  }

}
