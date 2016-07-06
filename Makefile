CCFILES = lex.Lury.cc lury.tab.cpp

CXX = g++
CXXFLAGS = -std=c++11
TARGET = lury

SRCS = $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(CCFILES) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

lury.tab.cpp: lury.ypp
	bison -dv lury.ypp

lex.Lury.cc: lury.l
	flex lury.l

clean:
	rm -f $(TARGET) $(OBJS) lury.tab.cpp lex.Lury.cc lury.tab.hpp position.hh stask.hh location.hh
