NC='\e[0m'
RED='\e[31m'
GREEN='\e[32m'

gcc -Wall -Wextra -Werror -lm mini_paint.c -o noorigin
gcc -Wall -Wextra -Werror -lm our_mini_paint.c -o origin

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

./noorigin ./test/test > test1
./origin ./test/test > test2
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
