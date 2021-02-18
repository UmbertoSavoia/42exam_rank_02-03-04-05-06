NC='\e[0m'
RED='\e[31m'
GREEN='\e[32m'

gcc -Wall -Wextra -Werror micro_paint.c -o noorigin
gcc -Wall -Wextra -Werror our_micro_paint.c -o origin

./noorigin ./test/0 > test1
./origin ./test/0 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/1 > test1
./origin ./test/1 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/2 > test1
./origin ./test/2 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/3 > test1
./origin ./test/3 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/4 > test1
./origin ./test/4 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/5 > test1
./origin ./test/5 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/6 > test1
./origin ./test/6 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/7 > test1
./origin ./test/7 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/8 > test1
./origin ./test/8 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/ex_1 > test1
./origin ./test/ex_1 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/ex_2 > test1
./origin ./test/ex_2 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/ex_3 > test1
./origin ./test/ex_3 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

./noorigin ./test/ex_4 > test1
./origin ./test/ex_4 > test2
if diff -U 1 test1 test2
then
	printf "[$GREEN OK $NC] \n"
else
	printf "[$RED KO $NC] \n"
fi

rm noorigin origin test1 test2

#num=$(ls test | wc -w)
#file=$(ls test )
#dir=./test/
#
#for (( i=0; i<${#file[@]}; i++ ))
#do
#	./origin eval $($dir${file[$i]})
#done
