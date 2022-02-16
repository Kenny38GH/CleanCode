
BIN = Balls
FLAGS = -Wall -g
INC = 
LIBS = -lGL -lm -lSDL2
LIBDIR = 
GCC = g++
OBJECTS = obj/main.o obj/ball.o obj/vector.o obj/render.o
default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/vector.o: model/vector.cpp lib/vector.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ball.o: model/ball.cpp lib/ball.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/render.o: visu/render.cpp lib/render.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/main.o: main.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;