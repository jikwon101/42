#!/bin/bash -e
build()
{
	imgs=("nginx")
	#images=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb")
	for img in "${imgs[@]}"
	do
		docker build -t ${img}-images ./srcs/$img/.
	done
}

service()
{
	svcs=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb")
	for svc in "${svcs[@]}"
	do
		kubectl delete service ${svc}-service
	done
	kubectl get services
}

deploy()
{
	deploys=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb")
	for deploy in "${deploys[@]}"
	do
		kubectl delete deploy ${deploy}-deployment
	done
	kubectl get deployments
}

build
