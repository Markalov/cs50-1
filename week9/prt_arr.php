<?php

$arr = [1, 2, 4, 3, 5];

for($i = 0, $n = count($arr); $i < $n; $i++)
    printf($arr[$i] . "\n");

printf("\n\n");

foreach($arr as $n)
    printf($n . "\n");

?>
