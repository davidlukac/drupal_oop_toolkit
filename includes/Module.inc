<?php

abstract class Module {

  protected static $instance = null;

  /* @var string Name of the Module. */
  protected $name;
  /* @var string URL version of the Module name. Generally the same string as *name* with '-' instead of '_' */
  protected $urlName;
  /* @var string Help text describing usage of the module. */
  protected $helpText;
  /* @var string Path administration pages of the module. */
  protected $adminPath;

  /**
   * Constructs and returns path for Help page of the module.
   * @return string Help path.
   */
  function getHelpPath() {
    $helpPath = "admin/help" . "#" . $this->getName();
    return $helpPath;
  }

  /**
   * Returns name of the Module.
   * @return string Name of the module.
   */
  function getName() {
    return $this->name;
  }

  /**
   * Returns un-formatted help text.
   * @return string Help text.
   */
  function getHelpText() {
    return $this->helpText;
  }

  /**
   * Returns help text wrapped in *t()* and *<p>*.
   * @return string Formatted help text.
   */
  function getFormattedHelpText() {
    $text = '<p>' . t($this->getHelpText()) . '</p>';
    return $text;
  }

  /**
   * @return string Settings page URL.
   */
  function getAdminPath() {
    $path = "admin/config/" . $this->urlName;
    return $path;
  }

  // ---------------------------------------------------------------------------
  // --- Singleton helper functions. -------------------------------------------
  // ---------------------------------------------------------------------------

  /**
   * @return Module Singleton instance of the Module class.
   */
  public static function getInstance() {
    if (isset(static::$instance)) {
      return static::$instance;
    } else {
      static::$instance = new static;
      return static::$instance;
    }
  }

  /**
   * Protected constructor to prevent creating a new instance of the
   * *Module* via the `new` operator from outside of this class.
   */
  protected function __construct() {
  }

  /**
   * Private clone method to prevent cloning of the instance of the
   * *Module* instance.
   *
   * @return Module
   */
  private function __clone() {
  }

  /**
   * Private unserialize method to prevent unserializing of the *Module*
   * instance.
   *
   * @return Module
   */
  private function __wakeup() {
  }

}