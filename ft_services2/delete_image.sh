delete_image()
{
	sets=("nginx" "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb" "telegraf")
	for tar in ${sets[@]}
	do
		docker rmi ${tar}_42 | grep -v "Deleted"
	done
}


eval $(minikube docker-env)
delete_image
