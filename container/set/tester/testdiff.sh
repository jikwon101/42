# How to execute this file
# list
# in list root folder 
# ./tester/testdiff.sh list

# How to compile printdiff.exe
# In tester folder
# gcc main.c get_next_line.a -D PATH="\"$PWD\"" -o printdiff.exe

./tester/replace.exe $PWD/main.cpp "ft::${1}" "std::${1}";
mv $PWD/main.cpp.replace $PWD/tester/teststd.cpp;
clang++ -Wall -Wextra -Werror -std=c++98 -o ./tester/ft  $PWD/main.cpp;
clang++ -Wall -Wextra -Werror -std=c++98 -o ./tester/std $PWD/tester/teststd.cpp -D TEST;
echo  "\033[1m\033[36mResult of diff\n \033[0m";
./tester/ft > $PWD/tester/result_ft.txt
./tester/std > $PWD/tester/result_std.txt
./tester/printdiff.exe
#rm teststd.cpp
