FROM alpine:3.13.1

# Install grafana
RUN apk update && \
	apk --no-cache add grafana

# Set up grafana config
COPY srcs/grafana.ini /etc/grafana/grafana.ini

# Set up grafana dashboards
ENV G_PATH /usr/share/grafana/conf/provisioning
COPY srcs/dashboards /var/lib/grafana/dashboards
COPY srcs/provisioning/dashboards/dashboards.yaml $G_PATH/dashboards/dashboards.yaml
COPY srcs/provisioning/datasources/datasources.yaml $G_PATH/datasources/influxdb.yaml

EXPOSE 3000
CMD /usr/sbin/grafana-server --homepath=/usr/share/grafana --config=/etc/grafana/grafana.ini

