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

  /* @var $initialised boolean */
  private $initialised = FALSE;

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
   * @return object
   *   \Singleton
   */
  public static function getInstance() {
    /* @var $instance \InitialisedSingleton */
    $instance = parent::getInstance();
    // Let the initialisation happen only once.
    if (FALSE == $instance->initialised) {
      $instance->initialise();
      $instance->initialised = TRUE;
    }

    return $instance;
  }

}
