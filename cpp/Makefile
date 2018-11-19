run:
	./main

main: main.o Point.o Entity.o Sprite.o
	g++ -Wall main.o Point.o Entity.o Sprite.o -o main `sdl-config --libs` -lSDL_ttf -lm
	rm *.gch

main.o: main.cpp Sprite.h
	g++ -c -Wall main.cpp Sprite.h

Point.o: Point.cpp Point.h
	g++ -c -Wall Point.cpp Point.h

Entity.o: Entity.cpp Entity.h Point.h
	g++ -c -Wall Entity.cpp Entity.h Point.h

Sprite.o: Sprite.cpp Sprite.h
	g++ -c -Wall Sprite.cpp Sprite.h

clean:
	rm -f *.o main
