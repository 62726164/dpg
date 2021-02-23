PROGRAM = dpg-web
SOURCE = *.go

build:
	CGO_ENABLED=0 go build -a -ldflags '-extldflags "-static -s"' -o $(PROGRAM) $(SOURCE)

docker:
	docker build -t dpg-web .

clean:
	rm -f $(PROGRAM)
	rm -f $(PROGRAM).exe

fmt:
	gofmt -w $(SOURCE)

vet:
	go vet $(SOURCE)

run:
	go run $(SOURCE)

install:
	cp $(PROGRAM) /usr/local/bin/

uninstall:
	rm /usr/local/bin/$(PROGRAM)

tag:
	docker tag dpg-web:latest 045356666431.dkr.ecr.us-east-2.amazonaws.com/dpg-web:latest

push:
	docker push 045356666431.dkr.ecr.us-east-2.amazonaws.com/dpg-web:latest

