CCFILES = lex.Lury.cc lury.tab.cpp

CXX = g++
CXXFLAGS = -std=c++11 -I./
TARGET = lury

SRCS = lury.tab.cpp lex.Lury.cc src/lury.cpp src/object.cpp src/class.cpp src/function.cpp src/lambda.cpp src/boolean.cpp src/nil.cpp src/integer.cpp src/string.cpp src/context.cpp src/ast.cpp src/driver.cpp src/main.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

# $(TARGET): $(CCFILES) $(OBJS)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

lury.tab.cpp: lury.ypp
	bison -dv lury.ypp

lex.Lury.cc: lury.l
	flex lury.l

clean:
	rm -f $(TARGET) $(OBJS) lury.tab.cpp lex.Lury.cc lury.tab.hpp position.hh stask.hh location.hh
