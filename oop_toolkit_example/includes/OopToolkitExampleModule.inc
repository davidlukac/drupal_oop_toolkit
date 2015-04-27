<?php

/**
 * @file
 * OopToolkitExampleModule.inc - OopToolkitExampleModule class.
 */

/**
 * Class OopToolkitExampleModule.
 */
class OopToolkitExampleModule extends Module {

  protected $name = "oop_toolkit_example";
  protected $urlName = "oop_toolkit_example";
  protected $helpText = "This is an example implementation module of OOP Toolkit module.
    It's purpose is to demonstrate functionality and API usage of the module.";
  protected $adminGroup = "oop_toolkit";

  /**
   * Initialising function.
   */
  protected function initialise() {
    // Nothing to do here atm.
  }

}
