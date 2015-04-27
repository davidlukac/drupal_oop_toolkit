<?php

/**
 * @file
 * InitialisedSingleton.inc.
 */

/**
 * Class InitialisedSingleton.
 *
 * Initialised singleton ensures, that initialisation method is called
 * once, when the instance is being instantiated.
 */
abstract class InitialisedSingleton extends Singleton {

  /**
   * Set up all module's dependencies.
   *
   * Run whatever initialisation tasks necessary so your Module has all
   * dependencies ready and injected for later use.
   */
  abstract protected function initialise();

  /**
   * Overriding 'getInstance' function in the \Singleton.
   *
   * So we can run initialisation routine as well.
   *
   * @TODO: Needs research - for some reason we can't just call parent::getInstance();
   *
   * @return object
   *   \Singleton
   */
  public static function getInstance() {
    /* @var $initialised boolean */
    static $initialised = FALSE;

    /* @var $instance \InitialisedSingleton Static holder of the Singleton instance. */
    static $instance = NULL;

    if ($instance == NULL) {
      // @TODO: Needs research - for some reason we can't just call parent::getInstance();
      $instance = new static();
    }

    // Let the initialisation happen only once.
    if (FALSE == $initialised) {
      $instance->initialise();
      $initialised = TRUE;
    }

    return $instance;
  }

}
