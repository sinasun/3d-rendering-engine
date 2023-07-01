CC= gcc
CC_FLAGS=  -g -pedantic -W -Wall 

LDFLAGS = -lm -lSDL2

FILES= menu.c main.c matrix.c render_screen.c
 
OUT_EXE = render

build: $(FILES)
	$(CC) $(CC_FLAGS)  $(FILES) -o $(OUT_EXE) $(LDFLAGS)


clean: rm -r *.o core  *~

rebuild: clean build