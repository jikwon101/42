delete_image()
{
	sets=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb" "telegraf")
	for tar in ${sets[@]}
	do
		docker rmi ${tar}-42
	done
}


eval $(minikube docker-env)
delete_image
