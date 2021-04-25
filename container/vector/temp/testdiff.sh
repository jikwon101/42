./temp/replace ./main.cpp "ft::vector" "std::vector";
mv ./main.cpp.replace ./teststd.cpp;
clang++ -o ft  ./main.cpp;
clang++ -o std ./teststd.cpp;
echo  "\033[1m\033[36mtest FT \033[0m";
./ft
echo  "\033[1m\033[36mtest STD \033[0m";
./std
rm ft std teststd.cpp
