.PHONY: all
all: debug release test

.PHONY: debug
debug:
	$(MAKE) -f makefile.common TYPE=debug CFLAGS="-g -O0"

.PHONY: release
release:
	$(MAKE) -f makefile.common TYPE=release CFLAGS=-O3

.PHONY: test
test:
	$(MAKE) -f makefile.common SRCDIR=test/unit TARGET=test_units \
		TYPE=test CFLAGS="-g -O0" LIBS=-lcheck LDFLAGS="-Wl,--wrap=rand"

.PHONY: clean-dbg
clean-dbg:
	$(MAKE) -f makefile.common TYPE=debug clean

.PHONY: clean-rel
clean-rel:
	$(MAKE) -f makefile.common TYPE=release clean

.PHONY: clean-test
clean-test:
	$(MAKE) -f makefile.common TYPE=test clean

.PHONY: clean
clean:
	$(MAKE) -f makefile.common TYPE="" clean

.PHONY: run-dbg
run-dbg:
	$(MAKE) -f makefile.common TYPE=debug run

.PHONY: run-rel
run-rel:
	$(MAKE) -f makefile.common TYPE=release run

.PHONY: run-test_units
run-test_units:
	$(MAKE) -f makefile.common TYPE=test TARGET=test_units run
