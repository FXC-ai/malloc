#!/bin/sh
echo "Patience est mere de reussite"
export LD_LIBRARY_PATH=$PWD
export LD_PRELOAD=$PWD/libft_malloc.so
$@