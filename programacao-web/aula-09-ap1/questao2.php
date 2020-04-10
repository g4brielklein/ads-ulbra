<?php

$minhaString = "Marinha do Brasil";
$a = substr($minhaString, 1);
$b = substr($minhaString, 0, 8);
$c = substr($minhaString, -3, 1);

echo $a, $b, $c;

?>