ISFML=-I/usr/local/SFML/include
LSFML=-lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/SFML/lib
RSFML=export LD_LIBRARY_PATH=/usr/local/SFML/lib &&

all: main run

run:
	$(RSFML) ./main

main: main.o Point.o Entity.o fenetre.o
	g++ -Wall main.o Point.o Entity.o fenetre.o $(LSFML) -o main
	rm *.gch

main.o: main.cpp fenetre.h
	g++ -c -Wall main.cpp fenetre.h $(ISFML)

Point.o: Point.cpp Point.h
	g++ -c -Wall Point.cpp Point.h

Entity.o: Entity.cpp Entity.h Point.h
	g++ -c -Wall Entity.cpp Entity.h Point.h

fenetre.o: fenetre.cpp fenetre.h
	g++ -c -Wall fenetre.cpp fenetre.h $(ISFML)

clean:
	rm -f *.o main

install:
	unzip SFML.zip
	sudo cp -r SFML /usr/local
	rm -f -r SFML

#SFML est installé dans /usr/local
