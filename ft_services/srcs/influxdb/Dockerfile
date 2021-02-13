FROM alpine:3.12.3

# Install influxdb
RUN apk update && \
	apk add --no-cache influxdb

# Set influxdb
COPY srcs/influxdb.conf /etc/influxdb.conf
RUN chmod +x /etc/influxdb.conf
COPY srcs/init.sh /init.sh

EXPOSE 8086
ENTRYPOINT ["/bin/sh", "init.sh"]
