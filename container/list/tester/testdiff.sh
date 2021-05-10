
# How to compile printdiff.exe
# In tester folder
# gcc main.c get_next_line.a -D PATH="\"$PWD\"" -o printdiff.exe

$PWD/tester/replace.exe $PWD/main.cpp "ft::${1}" "std::${1}";
mv $PWD/main.cpp.replace $PWD/tester/teststd.cpp;
clang++ -o ft  $PWD/main.cpp;
clang++ -o std $PWD/teststd.cpp -D TEST;
echo  "\033[1m\033[36mResult of diff\n \033[0m";
./ft > $PWD/tester/result_ft.txt
./std > $PWD/tester/result_std.txt
./$PWD/tester/printdiff.exe
#rm teststd.cpp
