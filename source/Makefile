#example taken from http://entrenchant.blogspot.com/2010/08/unit-testing-in-c.html
NAME        =    romanNumeralCalc
LIBNAME     =    lib$(NAME).so
ARCHIVE     =    lib$(NAME).a

DEBUG       =    -DDEBUG -ggdb
OPT         =    -O2
ERR         =    -Wall
INC_PATH    =    -I.
LIB_PATH    =    

#----------------------------------------------------------------
CC          =     gcc
LD          =    ld
AR          =    ar rc
RANLIB      =    ranlib
RM          =    rm -f

LIBS        =    -lcheck -lm -lrt
CC_FLAGS    =     $(INC_PATH) $(DEBUG) $(OPT) $(ERR) -fPIC
LD_FLAGS    =    $(LIB_PATH) $(LIBS) -shared -soname=$(LIBNAME)
 
SRC         =     romanNumeralCalc.c convert.c

OBJ         =     romanNumeralCalc.o convert.o

#---------------------------------------------------------- Targets
all: $(LIBNAME)
.PHONY: all clean check

$(ARCHIVE): $(OBJ)
	$(AR) $(ARCHIVE) $^
	$(RANLIB) $(ARCHIVE)

$(LIBNAME): $(ARCHIVE)
	$(LD) $(LD_FLAGS) --whole-archive $< --no-whole-archive -o $@

.c.o: $(SRC)
	$(CC) $(CC_FLAGS) -o $@ -c $<

TEST_DIR   = ../tests
CHANGE_DIR = cd $(TEST_DIR)
clean:
	[ -f $(LIBNAME) ] && $(RM) $(LIBNAME)|| [ 1 ]
	[ -f $(ARCHIVE) ] && $(RM) $(ARCHIVE)|| [ 1 ]
	$(RM) $(OBJ)
	$(CHANGE_DIR) && make clean

check: $(LIBNAME)
	$(CHANGE_DIR) && make && make check 
