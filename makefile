
objs=main.o sdl_sys.o
CFLAGS=`sdl-config --cflags`
LFLAGS=`sdl-config --libs` -lSDL_image

game: $(objs)
	gcc -o game $(objs) $(LFLAGS)

main.o: main.c
	gcc -c $< $(CFLAGS)

sdl_sys.o: sdl_sys.c sdl_sys.h
	gcc -c $< $(CFLAGS)
