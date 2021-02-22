i=1
while :
do
	./a.out  > tmp
	echo ${i}
	echo "     "
	cat tmp | grep "died"
	i=$(($i + 1))
done
