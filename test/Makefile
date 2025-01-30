CXX = g++
CXXFLAGS = -I../include -Wall -g
LDFLAGS = -lgtest -pthread
SRCS = tests.cpp
OBJS = $(SRCS:.cpp=.o)
LIB = ../src/libmain.a

all: tests

.PHONY: run
run: tests
	./tests --gtest_color=yes

tests: $(OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) tests
