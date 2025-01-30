all: lib test

lib:
	$(MAKE) -C src/

test: lib
	$(MAKE) -C test/

run: test
	$(MAKE) -C test/ run

clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C test/ clean
