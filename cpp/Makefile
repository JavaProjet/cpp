run:
	./main

main: main.o graphics/graphics.o Point.o Personnage.o
	g++ -Wall main.o graphics/graphics.o Point.o Personnage.o -o main `sdl-config --libs` -lSDL_ttf -lm
	rm *.gch

main.o: main.cpp graphics/graphics.h Personnage.h
	g++ -c -Wall main.cpp graphics/graphics.h Personnage.h

Point.o: Point.cpp Point.h
	g++ -c -Wall Point.cpp Point.h

Personnage.o: Personnage.cpp Personnage.h Point.h
	g++ -c -Wall Personnage.cpp Personnage.h Point.h

#supprimer apres debut QT
graphics.o: graphics/graphics.c graphics/graphics.h
	rm -f graphics/police.h
	touch graphics/police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > graphics/police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > graphics/police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > graphics/police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > graphics/police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics/graphics.c
	cp graphics.o graphics/graphics.o
	rm graphics.o
#fin suppression

clean:
	rm -f *.o main
