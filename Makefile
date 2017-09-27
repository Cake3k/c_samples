MODULES_SRC = coinflip.c numberguess.c txtcount.c
UTILS_SRC = common.c
TEST_SRC = tester.c $(MODULES_SRC) $(UTILS_SRC)
MAIN_SRC = sample.c $(MODULES_SRC) $(UTILS_SRC)
HEADERS = coinflip.h numberguess.h common.h txtcount.h


all: sample

test: testing

sample: $(MODULES_SRC) $(HEADERS) Makefile
	gcc -o $@ $(MAIN_SRC)

testing: $(MODULES_SRC) $(HEADERS) Makefile
	gcc -o $@ $(TEST_SRC)

clean: 
	rm -f *~ *.o *.exe sample testing