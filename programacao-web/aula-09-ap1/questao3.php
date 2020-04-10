<?php

$fa = ""; $fb = "";

$frase = explode(" ", "asse essa ave");

$f1 = $frase[0];

$f2 = $frase[2];

 for($i = (strlen($f1)-1); $i >= 0; --$i)    

          $fa .= "$f1[$i]";

 for($i = (strlen($f2)-1);

         $i >= 0; --$i)    

$fb .= "$f2[$i]";

$frase[0] = $fa;

$frase[2] = $fb;

 $novafrase = implode(" ", $frase);

echo $novafrase; 

?>