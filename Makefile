target =  main
sources = main.cpp mdfile.cpp interface.cpp
test_sources = mdfile.cpp interface.cpp TEST.cpp
CC = g++
CCFlags = -Wall
LDLIBS = -lcrypto++
OPT = -Ofast
all:build
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)

test: TEST.cpp
	$(CC) $(CCFlags) $(OPT) -DMY_UNIT_TEST $(test_sources) -o test $(LDLIBS) -lUnitTest++
dbg:
	$(CC) -g $(sources) -o $(target)DBG

