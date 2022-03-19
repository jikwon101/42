# In root folder
# ./test.sh  > make stdmain & compile
# ./test.sh clear   >  clear testsrc file
# ./../tester/printer.exe vector ./testsrc/res_ft.txt ./testsrc/res_std.txt    IN VECTOR FOLDER
# Ignore tester folder IN VECTOR FOLDER

make_stdmain()
{
	cons=("vector"  "list" "map" "stack"  "queue"  "set"  "multimap" "multiset")
	for container in "${cons[@]}"
	do
		echo "Making ${container} std file"
		rm -rf $PWD/${container}/testsrc
		mkdir $PWD/${container}/testsrc
		./tester/replace.exe $PWD/${container}/main.cpp "ft::" "std::"
		mv $PWD/${container}/main.cpp.replace $PWD/${container}/testsrc/stdmain.cpp
	done
}

do_compile()
{
	cons=("vector"  "list" "map" "stack"  "queue"  "set"  "multimap" "multiset")
	for container in "${cons[@]}"
	do
		echo "compiling ${container}"
		clang++ -Wall -Wextra -Werror -std=c++98 -o $PWD/${container}/testsrc/ft  $PWD/${container}/main.cpp
		clang++ -Wall -Wextra -Werror -std=c++98 -o $PWD/${container}/testsrc/std  $PWD/${container}/testsrc/stdmain.cpp -D TEST

		./${container}/testsrc/ft >> $PWD/${container}/testsrc/res_ft.txt
		./${container}/testsrc/std >> $PWD/${container}/testsrc/res_std.txt
	done
}

make_printer()
{
	rm -rf $PWD/tester/printer.exe
	gcc $PWD/tester/main.c $PWD/tester/get_next_line.a -D PATH="\"$PWD\"" -o $PWD/tester/printer.exe
	echo  "Printer"
}

clear()
{
	cons=("vector"  "list" "map" "stack"  "queue"  "set"  "multimap" "multiset")
	for container in "${cons[@]}"
	do
		echo "clear ${container}"
		rm -rf $PWD/${container}/testsrc
	done
}

if [ "$#" -eq 0 ]; then
	clear
	make_printer
	make_stdmain
	do_compile
	exit 0
fi

if [ "$#" -eq 1 ]; then
	if [ $1 == 'clear' ]; then
		clear
		exit 0
	fi
fi
