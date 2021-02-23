FROM alpine:3.13.1

RUN apk -U upgrade

RUN mkdir -p /tmp
 
WORKDIR /tmp

EXPOSE 8080

COPY dpg-web /tmp

CMD ["/tmp/dpg-web"]
