TARGET=./a.out
CC=clang++
SRCS=\
	./evaluation.cpp \
	./graph.cpp \
	./kruskal.cpp \
	./main.cpp \
	./point_generator.cpp \
	./tsp.cpp
STD=-std=c++20

all: clean $(TARGET)

$(TARGET):
	$(CC) $(STD) -O2 -Wno-deprecated -lm -x c++ $(SRCS) -o $(TARGET)

build: $(TARGET)

clean:
	rm -rf $(TARGET)
