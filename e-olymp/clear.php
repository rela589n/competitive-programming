<?php

define('METHODS', [
    'ONLY' => 'ONLY',
    'EXCEPT' => 'EXCEPT',
]);

const METHOD = METHODS['ONLY'];
const DRY_RUN = false;


define('FILES_EXCEPT', [
    'cs',
    'cpp',
    'h',
    'jpg',
    'jpeg',
    'png',
    'php'
]);

define('FILES_ONLY', [
    'sln',
    'exe',
    'ilk',
    'pdb',
    'vcxproj',
    'filters',
    'user',
    'log',
    'obj',
    'idb',
    'pdb',
    'tlog',
    'lastbuildstate'
]);

define('DIRECTORIES', [
    './.vs'
]);


function startsWith($haystack, $needle)
{
    $length = strlen($needle);
    return (substr($haystack, 0, $length) === $needle);
}

function endsWith($haystack, $needle)
{
    $length = strlen($needle);
    if ($length == 0) {
        return true;
    }

    return (substr($haystack, -$length) === $needle);
}

function dir_is_empty($dirname)
{
    if (!is_dir($dirname))
        return false;

    foreach (scandir($dirname) as $file) {
        if (!in_array($file, array('.', '..')))
            return false;
    }

    return true;
}

function safe_del_tree($dirname, $context = null) {
    $files = array_diff(scandir($dirname), array('.','..'));

    foreach ($files as $file) {
        if (is_dir("$dirname/$file")) {
            safe_del_tree("$dirname/$file", $context) ;
        }
        else {
            safe_unlink("$dirname/$file", $context);
        }
    }

    return safe_rmdir($dirname, $context);
}

function safe_rmdir($dirname, $context = null)
{
    if (!DRY_RUN) {
        return rmdir($dirname, $context);
    }

    return false;
}

function safe_unlink($filename, $context = null)
{
    if (!DRY_RUN) {
        unlink($filename, $context);
    }
}

function scan($dir)
{
    $scanned = scandir($dir);
    unset($scanned[0]); // .
    unset($scanned[1]); // ..

    foreach ($scanned as $key => $value) {
        $base = "$dir/$value";
        if (is_dir($base)) {
            scan($base);

            if (dir_is_empty($base) ||
                in_array($base, DIRECTORIES, true)
            ) {
                printf("Deleting directory: %s\n", $base . PHP_EOL);

                safe_del_tree($base);
            }
        } else if (is_file($base)) {
            $pathInfo = pathinfo($base);
            $extension = $pathInfo['extension'] ?? null;

            $bool = in_array($extension, constant('FILES_' . METHOD), true);
            $needDelete = false;

            if (METHOD === METHODS['ONLY']) {
                $needDelete = $bool;
            }
            elseif(METHOD === METHODS['EXCEPT']) {
                $needDelete = !$bool;
            }

            $needDelete |= startsWith($value, 'TemporaryGeneratedFile');

            if ($needDelete) {
                printf("Deleting      file: %s\n", $base . PHP_EOL);

                safe_unlink($base);
            }
        }
    }
}

scan('.');
