cls
gcc -O -Wall -Wextra -ansi -pedantic main1.c array.c -o array1
gcc -O -Wall -Wextra -ansi -pedantic main2.c array.c -o array2
.\array1.exe > myout1.txt
.\array2.exe > myout2.txt