<?php

class MenuItem extends Singleton {

  protected $title;
  protected $description;
  protected $pageCallback;
  protected $accessArguments;
  protected $type;
  protected $pageArguments;

  /** @var $module \Module this item belongs to. */
  private $module;

  /**
   * Menu item constructor.
   * @param string $title Menu item title.
   * @param \Module $module to which this menu item belongs.
   */
  public function __construct($title, Module $module) {
    // @TODO: Do we want to do some validation here? These params are mandatory.
    $this->title = $title;
    $this->module = $module;
  }

  public static function getInstance(\Module $module) {
    /* @var $instance \MenuItem */
    $instance = parent::getInstance();
    $instance->module = $module;

    return $instance;
  }

  /**
   * Returns menu item description as string.
   *
   * @return string
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * Setter for menu item description.
   *
   * @param string $description
   */
  public function setDescription($description) {
    $this->description = $description;
  }

  /**
   * @TODO: Add documentation.
   * @return mixed
   */
  public function getPageCallback() {
    return $this->pageCallback;
  }

  /**
   * @TODO: Add documentation.
   * @param mixed $pageCallback
   */
  public function setPageCallback($pageCallback) {
    $this->pageCallback = $pageCallback;
  }

  /**
   * @TODO: Add documentation.
   * @return mixed
   */
  public function getAccessArguments() {
    return $this->accessArguments;
  }

  /**
   * @TODO: Add documentation.
   * @param mixed $accessArguments
   */
  public function setAccessArguments($accessArguments) {
    $this->accessArguments = $accessArguments;
  }

  /**
   * @TODO: Add documentation.
   * @return mixed
   */
  public function getType() {
    return $this->type;
  }

  /**
   * @TODO: Add documentation.
   * @param mixed $type
   */
  public function setType($type) {
    $this->type = $type;
  }

  /**
   * @TODO: Add documentation.
   * @return mixed
   */
  public function getPageArguments() {
    return $this->pageArguments;
  }

  /**
   * @TODO: Add documentation.
   * @param mixed $pageArguments
   */
  public function setPageArguments($pageArguments) {
    $this->pageArguments = $pageArguments;
  }


  /**
   * Returns Drupal array representation of this menu item.
   *
   * @return array Menu item array representation.
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
