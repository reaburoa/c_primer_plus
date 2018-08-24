#!/usr/local/php/bin/php
<?php
declare(strict_types = 1);
function getAllFiles(string $path = '.', string $match = '') : array
{
    $ar_files = [];
    $dir_handler = opendir($path);
    while (($file = readdir($dir_handler)) !== false) {
        if ($file == '.' || $file == '..') {
            continue;
        }
        $tmp_file = $path.DIRECTORY_SEPARATOR.$file;
        if (is_dir($tmp_file)) {
            $ar_files = array_merge($ar_files, getAllFiles($tmp_file, $match));
        } else {
            if ($match) {
                if (preg_match($match, $tmp_file)) {
                    $ar_files[] = $tmp_file;
                }
            } else {
                $ar_files[] = $tmp_file;
            }
        }
    }

    return $ar_files;
}

$files = getAllFiles('.', '/^[a-zA-Z0-9\.\/\_]([a-zA-Z0-9\.\/\_]+)\.c$/');

$lines = 0;
foreach ($files as $val) {
    echo $val, "\n";
    $file_content = file_get_contents($val);
    $lines += substr_count($file_content, "\n");
}

echo $lines,"\n";

