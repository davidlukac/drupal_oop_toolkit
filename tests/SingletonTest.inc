<?php

/**
 * @file
 * Singleton class test.
 */

// error_reporting( E_ALL );
// @TODO: Convert this into proper PhpUnit test.

require_once "../includes/Singleton.inc";
require_once "../includes/InitialisedSingleton.inc";

//
///**
// * Class SingletonTest.
// */
//class SingletonTest extends Singleton {
//
//}
//
///**
// * Testing if correct class is being instantiated.
// *
// * @param \Singleton $test_instance
// *   Instance to test.
// *
// * @return bool
// *   TRUE if test passed, FALSE otherwise.
// */
//function test_instance_of(\Singleton $test_instance) {
//  $assertion = TRUE;
//  try {
//    if ($test_instance == NULL) {
//      throw new Exception("Instance is NULL.");
//    }
//
//    if ($test_instance instanceof Singleton) {
//      // We don't need to do anything here.
//    }
//    else {
//      throw new Exception("Not instance of Singleton.");
//    }
//  }
//  catch (Exception $e) {
//    // If we threw any Exception, we change the assertion flag to FALSE.
//    $assertion = FALSE;
//  }
//
//  return $assertion;
//}
//
//// $test_instance = SingletonTest::getInstance();
//// echo "Test instanceof: " . test_instance_of($test_instance) . "\n";
//

/**
 * Class TestSingleton1.
 */
class TestSingleton1 extends InitialisedSingleton {
  /**
   * Get Class Name.
   *
   * @return string
   *   Class name.
   */
  public function getClassName() {
    echo get_class($this) . "\n";
    return get_class($this);
  }

  /**
   * Get class ID.
   *
   * @return string
   *   Class ID.
   */
  public function getClassId() {
    return spl_object_hash($this);
  }

  /**
   * Initialisation.
   */
  protected function initialise() {
    echo "Initialising #1\n";
  }

}

/**
 * Class TestSingleton2.
 */
class TestSingleton2 extends InitialisedSingleton {
  /**
   * Get Class Name.
   *
   * @return string
   *   Class name.
   */
  public function getClassName() {
    echo get_class($this) . "\n";
    return get_class($this);
  }

  /**
   * Get class ID.
   *
   * @return string
   *   Class ID.
   */
  public function getClassId() {
    return spl_object_hash($this);
  }

  /**
   * Initialisation.
   */
  protected function initialise() {
    echo "Initialising #2\n";
  }

}

/**
 * Class TestSingleton3.
 */
class TestSingleton3 extends InitialisedSingleton {
  /**
   * Get Class Name.
   *
   * @return string
   *   Class name.
   */
  public function getClassName() {
    echo get_class($this) . "\n";
    return get_class($this);
  }

  /**
   * Get class ID.
   *
   * @return string
   *   Class ID.
   */
  public function getClassId() {
    return spl_object_hash($this);
  }

  /**
   * Initialisation.
   */
  protected function initialise() {
    echo "Initialising #3\n";
  }

}

function test2() {

  echo "T1\n";
  /* @var $ts1 \TestSingleton1 */
  $ts1 = TestSingleton1::getInstance();
  // $ts11 = TestSingleton1::getInstance();
  // $ts12 = TestSingleton1::getInstance();
  echo "instantiated\n";
  echo "TS1: Instance of " . $ts1->getClassName() . "; ID: " . $ts1->getClassID() . "\n";
  echo "T1-end\n";

  echo "T2\n";
  /* @var $ts2 \TestSingleton2 */
  $ts2 = TestSingleton2::getInstance();
  echo "TS2: Instance of " . $ts2->getClassName() . "; ID: " . $ts2->getClassID() . "\n";
  echo "T2-end\n";

  echo "T3\n";
  /* @var $ts3 \TestSingleton3 */
  $ts3 = TestSingleton3::getInstance();
  echo "TS3: Instance of " . $ts3->getClassName() . "; ID: " . $ts3->getClassID() . "\n";
  echo "T3-end\n";
}

test2();
