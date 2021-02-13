metallb()
{
	kubectl delete namespace metallb-system
}
deploy()
{
	kubectl delete deployment --all
}
secret()
{
	kubectl delete secret --all
}
config()
{
	kubectl delete configmap --all
}
service()
{
	kubectl delete service --all
}
pv()
{
	kubectl delete persistentvolume --all
}
pvc()
{
	kubectl delete pvc --all
}

if [ "$#" -eq 0 ]; then
	deploy
	secret
	configmap
	service
	pv
	pvc
fi

args=("$@")
for (( c=0; c < $#; c++ ))
do
	${args[$c]}
done
