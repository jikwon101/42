i=1
while :
do
	./a.out 4 410 200 200 5  > tmp
	echo ${i}
	echo "     "
	cat tmp | grep "died"
	i=$(($i + 1))
done
