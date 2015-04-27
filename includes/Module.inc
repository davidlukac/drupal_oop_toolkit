<?php

/**
 * @file
 * Module class.
 */

/**
 * Class Module - base interface for working with modules.
 */
abstract class Module extends InitialisedSingleton {

  /* @var $name string Name of the Module. */
  protected $name;
  /* @var $urlName string URL version of the Module name.
   * Generally the same string as *name* with '-' instead of '_' */
  protected $urlName;
  /* @var $helpText string Help text describing usage of the module. */
  protected $helpText;

  /* @var $menu_items array of \MenuItem */
  protected $menuItems;

  /**
   * Constructs and returns path for Help page of the module.
   *
   * @return string
   *    Help path.
   */
  public function getHelpPath() {
    $help_path = "admin/help#" . $this->urlName;
    return $help_path;
  }

  /**
   * Returns name of the Module.
   *
   * @return string
   *   Name of the module.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Returns un-formatted help text.
   *
   * @return string
   *   Help text.
   */
  public function getHelpText() {
    return $this->helpText;
  }

  /**
   * Returns help text wrapped in *t()* and *<p>*.
   *
   * @return string
   *   Formatted help text.
   */
  public function getFormattedHelpText() {
    // @TODO: Getter could return text value already in t()?
    $help_text = $this->getHelpText();
    $text = '<p>' . t($help_text) . '</p>';
    return $text;
  }

  /**
   * Returns path to administration pages of the module.
   *
   * @return string
   *   Settings page URL.
   */
  public function getAdminPath() {
    $path = "admin/config/" . $this->urlName;
    return $path;
  }

  /**
   * Add specific menu item to the list of MenuItems associated with the Module.
   *
   * This function injects Module into the MenuItem, so it's aware
   * of it's context as well.
   *
   * @param \MenuItem $menu_item
   *    Specific MenuItem that should be added.
   *
   * @return array
   *    Returns updated array of MenuItems currently associated with the Module.
   */
  public function addMenuItem(\MenuItem $menu_item) {
    $menu_item->setModule($this);
    // @TODO: Do actual implementation of this function.
    $this->menuItems = array($menu_item);

    return $this->menuItems;
  }

}
