#!/bin/bash


tests=(
    "test0.c"
    "test0_copy.c"
    "test1.c"
    "test1_copy.c"
    "test2.c"
    "test2_copy.c"
    "test3.c"
    "test3_copy.c"
    "test4.c"
    "test4_copy.c"
    "test5.c"
    "test5_copy.c"
)


make


for test in "${tests[@]}"; do
    echo "Lancement du test : $test"
    

    gcc "tests/correction/$test" -I inc -L. -lft_malloc


    if [ $? -eq 0 ]; then

        sh run.sh ./a.out
    else
        echo "Erreur lors de la compilation de $test"
    fi
done
