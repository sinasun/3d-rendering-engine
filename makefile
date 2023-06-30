CC= gcc
CC_FLAGS=  -g -pedantic -W -Wall -lm
FILES= menu.c main.c matrix.c
 
OUT_EXE = render

build: $(FILES)
	$(CC)  $(FILES) -o $(OUT_EXE) $(CC_FLAGS) 


clean: rm -r *.o core  *~

rebuild: clean build