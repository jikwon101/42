./temp/replace ./main.cpp "ft::vector" "std::vector";
mv ./main.cpp.replace ./teststd.cpp;
clang++ -o ft  ./main.cpp;
clang++ -o std ./teststd.cpp;
echo  "\033[1m\033[36mResult of diff\n \033[0m";
./ft > ./temp/result_ft.txt
./std > ./temp/result_std.txt
./temp/printdiff
rm ft std teststd.cpp
