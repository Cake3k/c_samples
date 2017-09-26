MODULES_SRC = coinflip.c numberguess.c
TEST_SRC = tester.c $(MODULES_SRC)
MAIN_SRC = sample.c $(MODULES_SRC)
HEADERS = coinflip.h numberguess.h


all: sample

test: testing

sample: $(MODULES_SRC) $(HEADERS) Makefile
	gcc -o $@ $(MAIN_SRC)

testing: $(MODULES_SRC) $(HEADERS) Makefile
	gcc -o $@ $(TEST_SRC)

clean: 
	rm -f *~ *.o *.exe sample testing