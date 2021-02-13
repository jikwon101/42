FROM alpine:3.12.3

# Install grafana
RUN     apk add grafana=7.3.6-r0 --repository=https://dl-cdn.alpinelinux.org/alpine/latest-stable/community/

# Set up grafana config
COPY srcs/grafana.ini /etc/grafana/grafana.ini
# Set up grafana dashboards
ENV G_PATH /usr/share/grafana/conf/provisioning
COPY srcs/dashboards /var/lib/grafana/dashboards
COPY srcs/provisioning/dashboards/dashboards.yaml $G_PATH/dashboards/dashboards.yaml
COPY srcs/provisioning/datasources/datasources.yaml $G_PATH/datasources/influxdb.yaml

EXPOSE 3000
CMD /usr/sbin/grafana-server --homepath=/usr/share/grafana --config=/etc/grafana/grafana.ini

