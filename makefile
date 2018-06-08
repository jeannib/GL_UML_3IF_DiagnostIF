RM=rm
COMP=g++
EDL=g++
RMFLAGS=-f
COMPFLAGS = -ansi -pedantic  -Wall -std=c++11 -g
DEBUG=no
EXE=diagnostif
EXEPATH=./
SPEC=$(wildcard *.h)
SRC=$(SPEC:.h=.cpp)
OBJ=$(SRC:.cpp=.o)

ifeq ($(DEBUG),yes)
	DEFINE_DEBUG=-D MAP	
else
	DEFINE_DEBUG=
endif



all:$(EXEPATH)$(EXE)
	

$(EXEPATH)$(EXE): $(OBJ)
	$(EDL) -o $(EXEPATH)$(EXE) $(OBJ) main.o

%.o: %.cpp
	$(COMP) -c $< $(COMPFLAGS) $(DEFINE_DEBUG) $(DEFINE_LOGIN) main.cpp



.PHONY:clean tests

clean:
	$(RM) $(RMFLAGS) *.o $(EXEPATH)$(EXE) ./test


test:$(OBJ)
	$(COMP) -c unittest.cpp
	#$(RM) $(RMFLAGS) *.o ./test
	#$(COMP) -c $(SRC) unittest.cpp $(COMPFLAGS) $(DEFINE_DEBUG) $(DEFINE_LOGIN)
	$(EDL) -o ./test $(OBJ) unittest.o
	./test
	#$(RM) $(RMFLAGS) *.o ./test

