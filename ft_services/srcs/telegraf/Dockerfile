FROM alpine:3.12.3

# Download telegraf
ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.16.3_static_linux_amd64.tar.gz .

# Install telegraf
RUN tar -xzf telegraf-1.16.3_static_linux_amd64.tar.gz
RUN rm telegraf-1.16.3_static_linux_amd64.tar.gz
RUN cp -r telegraf-1.16.3/* /
RUN ln -s /bin/sh bash

# Setup telegraf
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/init.sh /init.sh
RUN chmod +x /init.sh

ENTRYPOINT ["bin/sh", "init.sh"]

