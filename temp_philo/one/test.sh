i=1
while :
do
	./a.out 5 800 200 200 7 > tmp
	echo ${i}
	echo "     "
	cat tmp | grep "died"
	i=$(($i + 1))
done
