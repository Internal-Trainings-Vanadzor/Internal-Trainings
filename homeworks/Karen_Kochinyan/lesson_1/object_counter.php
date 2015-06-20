<?php

class A {

    public static $counter = 0;

    function __construct() {
        ++A::$counter;
    }

    function __destruct() {
        --A::$counter;
    }
    
    public function printObjectsCount() {
        print "<br/>Object count = " . A::$counter;
    }

}

$obj1 = new A();
$obj1->printObjectsCount();
$obj2 = new A();
$obj2->printObjectsCount();
$obj3 = new A();
$obj3->printObjectsCount();
$obj4 = new A();
$obj4->printObjectsCount();

unset($obj1);
$obj4->printObjectsCount();
unset($obj2);
$obj4->printObjectsCount();

?>