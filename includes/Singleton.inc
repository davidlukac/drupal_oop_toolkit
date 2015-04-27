<?php

/**
 * @file
 * Singleton.inc - Simple Singleton base class.
 */

/**
 * Class Singleton - base class for all our singletons.
 */
abstract class Singleton {
  /**
   * Instance getter - single point of getting an instance of this class.
   *
   * @return \Singleton
   *    Singleton instance of the Module class.
   */
  public static function getInstance() {
    /* @var $instance \Singleton Static holder of the Singleton instance. */
    static $instance = NULL;

    // Lets check whether we already have an instance...
    if ($instance == NULL) {
      // ...and if not, lets create one.
      $instance = new static();
    }

    return $instance;
  }

  /**
   * Dummy constructor.
   *
   * Protected constructor to prevent creating a new instance of the
   * Singleton via the `new` operator from outside of this class.
   */
  protected function __construct() {
    // Empty function for purpose.
  }

  /**
   * Private clone method to prevent cloning of the instance of the class.
   */
  private function __clone() {
    // Empty function for purpose.
  }

  /**
   * Private unserialize method to prevent unserializing of the instance.
   */
  private function __wakeup() {
    // Empty function for purpose.
  }

}
