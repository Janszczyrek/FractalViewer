COMPILER = g++
LINKER = $(COMPILER)
CFLAGS = -Wall -lsfml-graphics -lsfml-window -lsfml-system -O
LFLAGS = -Wall -lsfml-graphics -lsfml-window -lsfml-system -O

mandelbrot.out: object/mandelbrot.o object/mandelbrot_draw.o
	$(LINKER) object/mandelbrot.o object/mandelbrot_draw.o $(LFLAGS) -o mandelbrot.out
object/mandelbrot.o: source/mandelbrot.cpp headers/mandelbrot.hpp
	$(COMPILER) -c source/mandelbrot.cpp $(CFLAGS) -o object/mandelbrot.o
object/mandelbrot_draw.o: source/mandelbrot_draw.cpp headers/mandelbrot_draw.hpp
	$(COMPILER) -c source/mandelbrot_draw.cpp $(CFLAGS) -o object/mandelbrot_draw.o

sierpinski.out: object/sierpinski.o object/sierpinski_draw.o
	$(LINKER) object/sierpinski.o object/sierpinski_draw.o $(LFLAGS) -o sierpinski.out
object/sierpinski.o: source/sierpinski.cpp headers/sierpinski.hpp
	$(COMPILER) -c source/sierpinski.cpp $(CFLAGS) -o object/sierpinski.o
object/sierpinski_draw.o: source/sierpinski_draw.cpp headers/sierpinski_draw.hpp
	$(COMPILER) -c source/sierpinski_draw.cpp $(CFLAGS) -o object/sierpinski_draw.o
all: mandelbrot.out sierpinski.out