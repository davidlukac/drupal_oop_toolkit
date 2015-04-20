<?php

/**
 * @file
 * Base class for Object representation of any Drupal variable.
 */

abstract class Variable {
  /* @var string Name of the variable used in Drupal. */
  private $name = NULL;

  // @TODO Clarify what type of variable to use here.
  /* @var mixed Default value. */
  private $default = NULL;

  /**
   *
   */
  function __construct() {
    if (is_null($this->name)) {
      throw new RuntimeException("Variable name is expected to be defined in 'name' member.");
    }
    if (is_null($this->default)) {
      throw new RuntimeException("Default variable value is expected to be defined in 'default' member.");
    }
  }

  public static function getInstance() {
    $instance = &drupal_static(get_class($this));
    if (isset($instance)) {
      return $instance;
    } else {
      //@TODO add implementation.
    }
  }

  /**
   * @return int Returns default value of the variable.
   */
  public function getDefault() {
    return $this->default;
  }

  /**
   * @return string Returns name of the variable.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param string $name
   */
  public function setName($name) {
    $this->name = $name;
  }

  /**
   * @return int Returns currently set or default value (if not set).
   */
  public function getCurrentOrDefault() {
    /* @var mixed Currently set or default value. */
    $value = variable_get($this->getName(), $this->getDefault());
    return $value;
  }

}