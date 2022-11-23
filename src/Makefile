CXX = g++
STD = -std=c++17
CFLAG = -Wall -Wextra -Werror -pedantic  -g
TEST_FILES = tests.cpp

.PHONY: test gcov_report

# определяем ОС специфед LEAKS
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	GTEST:= $(shell pkg-config --cflags --libs gtest 2>/dev/null)
	ifeq ($(GTEST),)
		GTEST:=-DGTEST_HAS_PTHREAD=1 -lgtest -pthread
	endif
	LEAKS_CMD = CK_FORK=no valgrind --tool=memcheck --leak-check=full --track-origins=yes  --leak-check=full --show-leak-kinds=all ./test
endif
ifeq ($(UNAME), Darwin)
	LEAKS_CMD = CK_FORK=no leaks --atExit -- ./test
	GTEST = -fsanitize=address -DGTEST_HAS_PTHREAD=1 -lgtest -pthread
endif

all: clean test

test:
	$(CXX) $(STD) $(CFLAG) -o test $(TEST_FILES) $(GTEST)
	./test

gcov_report: clean
	$(CXX) $(STD) $(CFLAG) -o test $(TEST_FILES) $(GTEST) --coverage
	./test || true
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report test.info
	open report/index.html

clean:
	rm -rf *.a *.o test gcov *.info report *.dSYM *.gc* *.out

check: 
	cppcheck --enable=all --suppress=missingIncludeSystem --language=c++ *.cpp *.hpp *.inc
	$(LEAKS_CMD)
