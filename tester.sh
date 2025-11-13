
echo "======================================================================"
echo "                              Preliminaries"
echo "======================================================================"


echo ""
echo "-------------------------- Preliminary tests --------------------------"
echo ""

cat Makefile



echo ""
echo ""
echo "-------------------------- Library Compilation --------------------------"
echo ""

export HOSTTYPE=Testing
make
echo ""
echo ""

ln -s libft_malloc_Testing.so libft_malloc.so
ls -l libft_malloc.so


echo ""
echo "-------------------------- Functions export --------------------------"
echo ""

nm -g libft_malloc.so

echo ""

nm -g libft_malloc.so | grep "T malloc"
nm -g libft_malloc.so | grep "T free"
nm -g libft_malloc.so | grep "T realloc"
nm -g libft_malloc.so | grep "T show_alloc_mem"
nm -g libft_malloc.so | grep "mmap"
nm -g libft_malloc.so | grep "munmap"
nm -g libft_malloc.so | grep "getpagesize"
nm -g libft_malloc.so | grep "write"
echo ""

echo "======================================================================"
echo "                           Feature's testing"
echo "======================================================================"


echo ""
echo "-------------------------- Malloc test --------------------------"
echo ""
echo "test0.c"

cat test0.c

echo ""
echo ""

echo ""
echo "test1.c"

cat test1.c

echo ""
echo ""

echo "malloc @ stdlib"
echo ""

gcc -o test0 test0.c && /usr/bin/time -v ./test0

echo ""

gcc -o test1 test1.c && /usr/bin/time -v ./test1
echo ""
echo ""


echo "Let's test now both programs with our library"
echo ""
echo ""

echo "malloc @ libft_malloc"

echo ""
echo ""

./run_linux.sh /usr/bin/time -v ./test0

echo ""

./run_linux.sh /usr/bin/time -v ./test1


echo ""
echo "-------------------------- Pre-allocated zones --------------------------"
echo ""
echo "malloc.h"
echo ""
echo ""
head -n 16 includes/malloc.h

echo ""
echo ""


echo ""
echo "-------------------------- Tests of free (test2.c) --------------------------"
echo ""

cat test2.c

echo ""
echo "test1 VS test2"

echo ""
echo ""

echo "malloc @ libft_malloc : gcc -o test2 test2.c && ./run_linux.sh /usr/bin/time -v ./test2"

echo ""
echo ""

gcc -o test2 test2.c && ./run_linux.sh /usr/bin/time -v ./test2


echo ""
echo "-------------------------- Quality of the free function --------------------------"
echo ""
echo "test 0 VS test2"
echo ""

echo ""
echo "-------------------------- Realloc test (test3.c) --------------------------"
echo ""

cat test3.c

echo ""
echo ""
echo "gcc -o test3 test3.c -L. -lft_malloc && ./run_linux.sh ./test3 :"
echo ""
echo ""


gcc -o test3 test3.c -L. -lft_malloc && ./run_linux.sh ./test3

echo ""
echo "-------------------------- Show_alloc_mem test (test4.c) --------------------------"
echo ""

cat test4.c

echo ""
echo "gcc -o test4 test4.c -L. -lft_malloc && ./run_linux.sh ./test4 :"
echo ""
echo ""

gcc -o test4 test4.c -L. -lft_malloc && ./run_linux.sh ./test4

echo ""
echo "-------------------------- Alignement test (test5.c) --------------------------"
echo ""
echo "test5.c"

cat test5.c

echo ""
echo ""

gcc -o test5 test5.c -L. -lft_malloc && ./run_linux.sh ./test5

echo ""
echo "-------------------------- Alignement test (test6.c) --------------------------"
echo ""
echo "test6.c"
echo ""
echo ""

echo "malloc @ stdlib"
echo ""
echo ""

gcc -o test6 test6.c && /usr/bin/time -v ./test6

echo ""
echo ""
echo "malloc @ libft_malloc"
echo ""
echo ""

gcc -o test6 test6.c -L. -lft_malloc && ./run_linux.sh /usr/bin/time -v ./test6



echo "======================================================================"
echo "                              BONUS"
echo "======================================================================"

echo ""
echo ""

echo "-------------------------- Competitive access--------------------------------"
echo ""
echo "cf. code"
echo ""
echo ""

echo "-------------------------- Additional bonuses --------------------------------"
echo "None"
