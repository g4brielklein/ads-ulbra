<?php

$servidor = '192.168.64.2';
$user = 'root';
$senha = '';
$banco = 'ulbra';
$TAB = '$nbsp;&nbsp;&nbsp;&nbsp;';

$connect = mysqli_connect($servidor, $user, $senha);
$db = mysqli_select_db($conect, $banco);

$query_select = 'SELECT * FROM aluno';
$select = mysql_query($connect, $query_select);
$fetch = mysqli_fetch_row($select);

echo 'CGU'.$TAB.'Nome <br/>';

echo $fetch[0].$TAB.$fetch[1].'<br/>';

while ($fetch = mysqli_fetch_row($select)) {
    echo $fetch[0].$TAB.$fetch[1].'<br/>';
}

?>