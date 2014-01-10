<?php

function foo($s)
{
    $n = strlen($s);
    for($i = 0; $i < $n; $i++)
        printf($s[$i] . "\n");
}

foo("This is cs50!");
?>
