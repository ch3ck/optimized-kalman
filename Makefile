# Builds and runs the Two dimensional histogram filter
#
# # srcfiles := $(shell find . -name "*.C")
# # objects  := $(patsubst %.C, %.o, $(srcfiles))
CC=gcc
CXX=g++
RM=rm -f
LDLIBS=-lm
CPPFLAGS=-std=c++11 -Wfatal-errors -Wall -fsyntax-only
# CPPFLAGS += -Wextra -Wwrite-strings -Wno-parentheses -Wconversion -Wshadow
# CPPFLAGS += -Wpedantic -Warray-bounds -Weffc++
SRCS=blur.cpp initialize_beliefs.cpp main.cpp move.cpp normalize.cpp print.cpp sense.cpp, zeros.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
HDRS=$(subst .cpp,.h.gch,$(SRCS))


all: clean dist-clean kalman

kalman: $(OBJS) main.cpp
	$(CXX) -Iheaders/ $(CPPFLAGS) main.cpp -o kalman $(OBJS) $(LDLIBS)

blur.o: blur.cpp headers/blur.h headers/zeros.h
	g++ $(CPPFLAGS) -c blur.cpp headers/blur.h headers/zeros.h

initialize_beliefs: initialize_beliefs.cpp headers/initialize_beliefs.h
	g++ $(CPPFLAGS)  -c headers/initialize_beliefs.h initialize_beliefs.cpp

move.o: headers/move.h headers/zeros.h move.cpp
	g++ $(CPPFLAGS) -c  headers/move.h headers/zeros.h move.cpp

normalize.o: normalize.cpp headers/normalize.h
	g++ $(CPPFLAGS) -c normalize.cpp headers/normalize.h

print.o: print.cpp headers/print.h
	g++ $(CPPFLAGS) -c print.cpp headers/print.h

sense.o: sense.cpp headers/sense.h
	g++ $(CPPFLAGS) -c sense.cpp headers/sense.h

zeros.o: zeros.cpp headers/zeros.h
	g++ $(CPPFLAGS) -c zeros.cpp headers/zeros.h


clean:
	$(RM) $(OBJS) headers/$(HDRS) kalman

dist-clean: clean
	$(RM) kalman