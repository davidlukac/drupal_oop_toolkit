<?php

/**
 * @file
 * Singleton.inc - Simple Singleton base class.
 */

/**
 * Class Singleton - base class for all our singletons.
 */
abstract class Singleton {

  /* @var $instance \Singleton Static holder of the Singleton instance. */
  protected static $instance = NULL;

  /**
   * Instance getter - single point of getting an instance of this class.
   *
   * @return \Singleton
   *    Singleton instance of the Module class.
   */
  public static function getInstance() {
    // Lets check whether we already have an instance...
    if (FALSE == isset(static::$instance)) {
      // ...and if not, lets create one.
      static::$instance = new static;
    }

    return static::$instance;
  }

  /**
   * Dummy constructor.
   *
   * Protected constructor to prevent creating a new instance of the
   * Singleton via the `new` operator from outside of this class.
   */
  protected function __construct() {
  }

  /**
   * Private clone method to prevent cloning of the instance of the class.
   */
  private function __clone() {
  }

  /**
   * Private unserialize method to prevent unserializing of the instance.
   */
  private function __wakeup() {
  }

}
