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

config_file()
{
	rm ./srcs/wordpress/srcs/wordpress.sql
	rm ./srcs/phpmyadmin/srcs/config.inc.php
	rm ./srcs/metallb/metallb-config.yaml
	rm ./srcs/nginx/srcs/default.conf
}
if [ "$#" -eq 0 ]; then
	config_file
	deploy
	secret
	config
	service
	pvc
	pv
	exit 0
fi

if [ $1 == 'x' ]; then

	deploy
	secret
	config
	service 
	pvc
	pv
	exit 0
fi

args=("$@")
for (( c=0; c < $#; c++ ))
do
	${args[$c]}
done
