PROGRAM = dpg
SOURCE = *.go

build:
	CGO_ENABLED=0 go build -a -ldflags '-extldflags "-static -s"' -o $(PROGRAM) $(SOURCE)
	strip $(PROGRAM)

clean:
	rm -f $(PROGRAM)

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
