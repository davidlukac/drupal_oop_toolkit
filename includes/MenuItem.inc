<?php
/**
 * @file
 * MenuItem.inc - MenuItem class definition.
 */

/**
 * Class MenuItem - provides interface for working with single menu item.
 */
abstract class MenuItem extends InitialisedSingleton {

  protected $title;
  protected $description;
  protected $pageCallback;
  protected $accessArguments;
  protected $type;
  protected $pageArguments;

  /* @var $module \Module this item belongs to. */
  private $module;

  /**
   * Mirroring menu item types from Drupal internal definitions.
   *
   * @see menu.inc.
   */
  const MENU_CALLBACK = MENU_CALLBACK;
  const MENU_DEFAULT_LOCAL_TASK = MENU_DEFAULT_LOCAL_TASK;
  const MENU_LOCAL_ACTION = MENU_LOCAL_ACTION;
  const MENU_LOCAL_TASK = MENU_LOCAL_TASK;
  const MENU_NORMAL_ITEM = MENU_NORMAL_ITEM;
  const MENU_SUGGESTED_ITEM = MENU_SUGGESTED_ITEM;

  /**
   * Initialization function of the MenuItem.
   *
   * @param \Module $module
   *   DI of which Module this MenuItem belongs to.
   */
  public function setModule(\Module $module) {
    // @TODO: Need to decide what would be the approach to do this DI.
    /* @var $instance \MenuItem */
    $instance->module = $module;
  }

//  /**
//   * Menu item constructor.
//   *
//   * @param string $title
//   *   Menu item title.
//   * @param \Module $module
//   *   Module to which this menu item belongs.
//   *
//   * @deprecated Do not use the constructor, use 'setModule' instead.
//   */
//  public function __construct($title, Module $module) {
//    // @TODO: Do we want to do some validation here? These params are mandatory.
//    $this->title = $title;
//    $this->module = $module;
//  }

  /**
   * Returns menu item description as string.
   *
   * @return string
   *   Menu item description.
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * Setter for menu item description.
   *
   * @param string $description
   *   Menu item description.
   */
  public function setDescription($description) {
    $this->description = $description;
  }

  /**
   * Callback function getter.
   *
   * @return mixed
   *   Callback function for path of this menu.
   */
  public function getPageCallback() {
    return $this->pageCallback;
  }

  /**
   * Callback function setter.
   *
   * @param string $page_callback
   *    Callback function name.
   */
  public function setPageCallback($page_callback) {
    $this->pageCallback = $page_callback;
  }

  /**
   * Access arguments getter.
   *
   * @return mixed
   *    Array of access arguments.
   */
  public function getAccessArguments() {
    return $this->accessArguments;
  }

  /**
   * Access arguments setter.
   *
   * @param mixed $access_arguments
   *    Array of access arguments.
   */
  public function setAccessArguments($access_arguments) {
    $this->accessArguments = $access_arguments;
  }

  /**
   * Menu type getter.
   *
   * @return mixed
   *    Returns menu type.
   */
  public function getType() {
    return $this->type;
  }

  /**
   * Menu type setter.
   *
   * @param mixed $type
   *   Menu type constant.
   */
  public function setType($type) {
    $this->type = $type;
  }

  /**
   * Page arguments getter.
   *
   * @return mixed
   *    Array of page arguments.
   */
  public function getPageArguments() {
    return $this->pageArguments;
  }

  /**
   * Function to set page arguments.
   *
   * @param mixed $page_arguments
   *    Page arguments.
   */
  public function setPageArguments($page_arguments) {
    $this->pageArguments = $page_arguments;
  }


  /**
   * Returns Drupal array representation of this menu item.
   *
   * @return array
   *   Menu item array representation.
   */
  public function getMenuItem() {
    $path = $this->module->getAdminPath();

    $items = array();

    $items[$path] = array(
      'title' => $this->title,
      'description' => $this->description,
      'page callback' => $this->pageCallback,
      'page arguments' => $this->pageArguments,
      'access arguments' => $this->accessArguments,
      'type' => $this->type,
    );

    return $items;
  }

}
