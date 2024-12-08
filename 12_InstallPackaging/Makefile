.PHONY: build	

build:
	autoreconf -fisv
	./configure
	make

test: build
	./src/tests

install: build
	sudo ./scripts/install.sh

uninstall:
	sudo ./scripts/uninstall.sh
