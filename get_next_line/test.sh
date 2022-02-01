gcc -Wall -Werror -Wextra main.c
echo "main.c"
./a.out< main.c > yours_1.txt
cat -e yours_1.txt > yours.txt
cat -e main.c > original.txt
diff -s original.txt yours.txt
echo "============="
echo "get_next_line.c"
./a.out< get_next_line.c > yours_1
cat -e yours_1 > yours
cat -e get_next_line.c > original
diff -s original yours
echo "============="
echo "HUGE:"
gcc -Wall -Werror -Wextra generator.c -o generator
./generator
./a.out< HUGE.txt > yoursHUGE.txt
diff -s HUGE.txt yoursHUGE.txt
echo "============="
echo "./generator (should differ):"
./a.out< generator > yours_1
cat -e yours_1 > yours_g
cat -e generator > original_g
diff -q original_g yours_g

