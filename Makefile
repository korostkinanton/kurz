target =  main
test_target = TEST
sources = mdfile.cpp
CC = g++
CCFlags = -Wall
LDLIBS = -lcrypto++
OPT = -Ofast

all: $(target)
$(target):
	$(CC) $(CCFlags) $(OPT) $(sources) $(target).cpp -o $(target) $(LDLIBS)
dbg:
	$(CC) -g $(sources) -o $(target)DBG
test: $(test_target)
$(test_target):
	$(CC) $(CCFlags) $(OPT) $(sources) $(test_target).cpp -o test $(LDLIBS) -lUnitTest++
clean:
	rm -f $(target) $(test_target)

