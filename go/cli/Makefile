PROGRAM = dpg
SOURCE = *.go

build:
	CGO_ENABLED=0 go build -a -ldflags '-extldflags "-static -s"' -o $(PROGRAM) $(SOURCE)
	strip $(PROGRAM)

windows:
	GOOS=windows GOARCH=386 go build -o $(PROGRAM).exe $(SOURCE)

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
