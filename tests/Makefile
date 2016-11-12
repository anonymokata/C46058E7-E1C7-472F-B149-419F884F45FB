TGT_NAME    =    romanNumeralCalc
TGT_FOLDER  =    ../source
TGT_SRC     =    $(TGT_FOLDER)/$(TGT_NAME).c

OPT         =    -O2 -fprofile-arcs -ftest-coverage
ERR         =    -Wall
INC_PATH    =    -I. -I..
LIB_PATH    =    -L$(TGT_FOLDER)
LD_PATH     =    $(TGT_FOLDER)

#---------------------------------------------------------
CC           =     gcc
RM           =     rm -f

CHECK_LIBS   =    -Wl,--whole-archive -lcheck -Wl,--no-whole-archive -lm -lrt
LIBS         =    -pthread $(CHECK_LIBS)

CC_FLAGS     =     $(INC_PATH) $(OPT) $(ERR) -DUNIT_TEST

LD_FLAGS     =     $(LIB_PATH)


TSET         =    check_$(TGT_NAME)
TEST1        =    check_addAndSub
TEST2        =    check_convert

TSET_SRC     =    $(TSET).c $(TEST1).c $(TEST2).c

TSET_FLAGS   =    $(CC_FLAGS) $(LD_FLAGS)

TSET_LIBS    =    $(LIBS) -l$(TGT_NAME)

TESTS        =    $(TSET)

$(TSET): $(TSET_SRC)
	$(CC) $(TSET_FLAGS) -o $@ $^ $(TSET_LIBS)
#---------------------------------------------------------- Targets
all: $(TESTS)
.PHONY: all clean check


clean:
	$(RM) $(TESTS) *.gcno *.gcda


check:
	@for t in $(TESTS); do                          \
		LD_LIBRARY_PATH='$(LD_PATH)' ./$$t;     \
	done
