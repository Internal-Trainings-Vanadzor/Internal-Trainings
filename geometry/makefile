CC=gcc
CFLAGS=-I.
DEPS = Canvas.h Circle.h Ellipse.h Geometry.h Line.h Painter.h Point.h Rect.h Shape.h StatisticalPainter.h Triangle.h Utility.h
OBJ = Geometry.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Geometrymake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)