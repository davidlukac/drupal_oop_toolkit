<?php

/**
 * @file
 * Variable.inc.
 *
 * Base class for Object representation of any Drupal variable.
 */

/**
 * Class Variable.
 */
abstract class Variable extends Singleton {

  // @TODO: These vars should be set in extending class?
  /* @var string Name of the variable used in Drupal. */
  protected $name = NULL;

  // @TODO Clarify what type of variable to use here.
  /* @var mixed Default value. */
  protected $default = NULL;

  /**
   * Validations to run when Variable is instantiated.
   */
  public function __construct() {
    if (is_null($this->name)) {
      throw new RuntimeException("Variable name is expected to be defined in 'name' member.");
    }

    if (is_null($this->default)) {
      throw new RuntimeException("Default variable value is expected to be defined in 'default' member.");
    }
  }

  /**
   * Default value getter.
   *
   * @return mixed
   *   Returns default value of the variable.
   */
  public function getDefault() {
    return $this->default;
  }

  /**
   * Variable name getter.
   *
   * @return string
   *   Returns name of the variable.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Getter for current/default value.
   *
   * @return mixed
   *   Returns currently set or default value (if not set).
   */
  public function getCurrentOrDefault() {
    /* @var mixed Currently set or default value. */
    $value = variable_get($this->getName(), $this->getDefault());
    return $value;
  }

}