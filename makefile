RM=rm
COMP=g++
EDL=g++
RMFLAGS=-f
COMPFLAGS = -ansi -pedantic  -Wall -std=c++11 -g
EXE=diagnostif
EXEPATH=./
SPEC=$(wildcard *.h)
SRC=$(SPEC:.h=.cpp)
OBJ=$(SRC:.cpp=.o)




all:$(EXEPATH)$(EXE)
	

$(EXEPATH)$(EXE): $(OBJ)
	$(EDL) -o $(EXEPATH)$(EXE) $(OBJ) main.o

%.o: %.cpp
	$(COMP) -c $< $(COMPFLAGS) main.cpp



.PHONY:clean tests

clean:
	$(RM) $(RMFLAGS) *.o $(EXEPATH)$(EXE) ./test


test:$(OBJ)
	@$(COMP) -c $(COMPFLAGS) unittest.cpp
	@$(EDL) -o ./test $(OBJ) unittest.o
	@./test
	@$(RM) ./test

