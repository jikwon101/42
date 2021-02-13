#!/bin/bash -e
metallb()
{
	echo "\033[35mSetting metallb \033[0m"
	kubectl apply -f srcs/metallb/metallb-control.yaml
	kubectl apply -f srcs/metallb/metallb-config.yaml
	echo "\n\n"
}
build()
{

	echo "\033[32mSetting image \033[0m"
	imgs=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "telegraf" "influxdb")
	for img in "${imgs[@]}"
	do
		echo "\033[32mBuild image/${img}_42 \033[0m"
		docker build -t ${img}_42 ./srcs/$img/. | grep Step
	done
	echo "\n\n"
}

service()
{
	echo "\033[35mCreate service objets\033[0m"
	svcs=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb")
	for svc in "${svcs[@]}"
	do	
		kubectl apply -f srcs/$svc/${svc}-service.yaml
	done
	echo "\n\n"
}

deploy()
{
	echo "\033[35mCreate deployment objets\033[0m"
	deploys=("nginx" "mysql" "phpmyadmin" "ftps" "grafana" "telegraf" "influxdb" "wordpress")
	for deploy in "${deploys[@]}"
	do
		kubectl apply -f srcs/$deploy/${deploy}-deployment.yaml
	done
	echo "\n\n"
}

volume()
{
	echo "\033[35mCreate volume objets\033[0m"
	volumes=("mysql" "influxdb")
	for vl in "${volumes[@]}"
	do
		kubectl apply -f srcs/$vl/${vl}-volume.yaml
	done
	echo "\n\n"
}

secret()
{
	echo "\033[35mCreate secret objets\033[0m"
	secretes=("nginx" "grafana" "influxdb")
	for sc in "${secretes[@]}"
	do
		kubectl apply -f srcs/$sc/${sc}-secret.yaml
	done
	echo "\n\n"
}

config()
{
	conf=()
	for cf in "${conf[@]}"
	do
		kubectl apply -f srcs/$cf/${cf}-configmap.yaml
	done
	echo "\n\n"
}

eval $(minikube docker-env)

if [ "$#" -eq 0 ]; then
	build
	metallb
	secret
	service
	volume
	deploy
fi

if [ "$#" -eq 1 ]; then
	if [ $1 == "x" ]; then
		secret
		service
		volume
		deploy
		exit 0
	fi
fi

args=("$@")
for (( c=0; c < $#; c++ ))
do
	${args[$c]}
done
