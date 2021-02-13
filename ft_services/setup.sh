#!/bin/bash -e
build()
{
	imgs=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "telegraf" "influxdb")
	for img in "${imgs[@]}"
	do
		docker build -t ${img}_42 ./srcs/$img/. | grep Step
	done
}

service()
{
	svcs=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb")
	for svc in "${svcs[@]}"
	do
		kubectl apply -f srcs/$svc/${svc}-service.yaml
	done
}

deploy()
{
	deploys=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "telegraf" "influxdb")
	for deploy in "${deploys[@]}"
	do
		kubectl apply -f srcs/$deploy/${deploy}-deployment.yaml
	done
}

volume()
{
	volumes=("mysql" "influxdb")
	for vl in "${volumes[@]}"
	do
		kubectl apply -f srcs/$vl/${vl}-volume.yaml
	done
}

secret()
{
	secretes=("nginx" "grafana" "influxdb")
	for sc in "${secretes[@]}"
	do
		kubectl apply -f srcs/$sc/${sc}-secret.yaml
	done
}

config()
{
	conf=()
	for cf in "${conf[@]}"
	do
		kubectl apply -f srcs/$cf/${cf}-configmap.yaml
	done
}

eval $(minikube docker-env)
build
secret
service
volume
deploy
