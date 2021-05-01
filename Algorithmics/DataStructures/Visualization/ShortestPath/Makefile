C = g++
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++ -lstdc++fs -std=c++17 -lm
VPATH = src inc lib
SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin
OBJ = $(notdir $(patsubst %.cpp,%.o,$(wildcard $(SRCDIR)/*))) # Project object files

ShortestPath : $(OBJ)
	$(CC) -o $(BINDIR)/$@  $(?:%.o=$(OBJDIR)/%.o) $(CFLAGS)

%.o : %.cpp
	$(CC) -c $< -o $(OBJDIR)/$@

clean :
	rm -f ./obj/*
	rm -f ./bin/*

build:
	mkdir -p ./obj/
	mkdir -p ./bin/
