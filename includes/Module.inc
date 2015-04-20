<?php

abstract class Module extends Singleton {

  protected static $instance = null;

  /* @var $name string Name of the Module. */
  protected $name;
  /* @var $urlName string URL version of the Module name. Generally the same string as *name* with '-' instead of '_' */
  protected $urlName;
  /* @var $helpText string Help text describing usage of the module. */
  protected $helpText;


// @TODO: Not sure if we need this yet.
//  /* @var $adminPath string Path administration pages of the module. */
//  private $adminPath;

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

}