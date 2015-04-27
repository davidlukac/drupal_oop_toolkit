<?php

/**
 * @file
 * Form.inc - Form base class.
 */


//$items['admin/config/oop-toolkit/example-settings'] = array(
//  'title' => 'Example administration for OPP Toolkit module',
//  'description' => 'Example administration pages for OOP Toolkit module.',
//  'page callback' => 'drupal_get_form',
//  // @TODO: This is the most problematic point - how to reference the callback function.
//  'page arguments' => array('oop_toolkit_example_settings_form'),
//  'access arguments' => array('administer OOP toolkit'),
//  'type' => MENU_NORMAL_ITEM,
//);

/**
 * Class Form.
 */
class Form {

  private $path;
  private $title;
  private $description;
  private $pageCallback;
  private $pageArguments;
  private $accessArguments;
  private $type;

  /**
   * Form constructor.
   *
   * @param string $path
   *   Path to hook into.
   * @param string $title
   *   Form title.
   */
  public function __construct($path, $title) {
    $this->path = $path;
    $this->title = $title;
  }

  /**
   * Form builder.
   *
   * @return array
   *   Drupal form array.
   */
  public function getForm() {
    $form = array();

    $form[$this->path] = array(
      'title' => $this->title,
      'description' => $this->description,
      'page callback' => $this->pageCallback,
      'page arguments' => $this->pageArguments,
      'access arguments' => $this->accessArguments,
      'type' => $this->type,
    );

    return $form;
  }

  /**
   * Getter.
   *
   * @return mixed
   */
  public function getPath() {
    return $this->path;
  }

  /**
   * @param mixed $path
   */
  public function setPath($path) {
    $this->path = $path;
  }

  /**
   * Getter.
   *
   * @return mixed
   */
  public function getTitle() {
    return $this->title;
  }

  /**
   * @param mixed $title
   */
  public function setTitle($title) {
    $this->title = $title;
  }

  /**
   * Getter.
   *
   * @return mixed
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * @param mixed $description
   */
  public function setDescription($description) {
    $this->description = $description;
  }

  /**
   * Getter.
   *
   * @return mixed
   */
  public function getPageCallback() {
    return $this->pageCallback;
  }

  /**
   * @param mixed $pageCallback
   */
  public function setPageCallback($pageCallback) {
    $this->pageCallback = $pageCallback;
  }

  /**
   * Getter.
   *
   * @return mixed
   */
  public function getPageArguments() {
    return $this->pageArguments;
  }

  /**
   * @param mixed $pageArguments
   */
  public function setPageArguments($pageArguments) {
    $this->pageArguments = $pageArguments;
  }

  /**
   * @return mixed
   */
  public function getAccessArguments() {
    return $this->accessArguments;
  }

  /**
   * @param mixed $accessArguments
   */
  public function setAccessArguments($accessArguments) {
    $this->accessArguments = $accessArguments;
  }

  /**
   * Getter.
   *
   * @return mixed
   */
  public function getType() {
    return $this->type;
  }

  /**
   * @param mixed $type
   */
  public function setType($type) {
    $this->type = $type;
  }

}
