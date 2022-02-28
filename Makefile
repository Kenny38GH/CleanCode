
BIN = Balls
FLAGS = -Wall -g
INC = 
LIBS = -lGL -lm -lSDL2
LIBDIR = 
GCC = g++
OBJECTS = obj/main.o obj/render.o obj/boid.o
default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/boid.o: model/boid.cpp lib/boid.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/render.o: visu/render.cpp lib/render.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/main.o: main.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;