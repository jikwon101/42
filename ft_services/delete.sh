#!/bin/bash -e

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

if [[ $1 == "service" ]]
then
	service
elif [[ $1 == "deploy" ]]
then
	deploy
else
	service
	deploy
fi
