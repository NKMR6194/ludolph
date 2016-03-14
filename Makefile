SRC=src/driver.cpp lex.Lury.cc lury.tab.cpp src/object.cpp src/ast.cpp src/main.cpp
HPP=include/ast.hpp include/object.hpp include/driver.hpp include/scanner.hpp include/context.hpp

all: lury

lury.tab.cpp: lury.ypp
	bison -dv lury.ypp

lex.Lury.cc: lury.l
	flex lury.l

lury: $(SRC) $(HPP)
	clang++ -std=c++11 -o lury $(SRC)

clean:
	rm -f lury lex.Lury.cc location.hh lury.output position.hh stack.hh lury.tab.cpp lury.tab.hpp
