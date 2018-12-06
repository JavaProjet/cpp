ISFML=-I/usr/local/SFML/include
LSFML=-lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/SFML/lib
RSFML=export LD_LIBRARY_PATH=/usr/local/SFML/lib &&
fic= main.o entity/Entity.o fenetre.o input.o editeur.o jouer.o entity/entity_rect.o entity/entity_ronde.o entity/arbre.o Carte.o

all: main run

run:
	$(RSFML) ./main

main: $(fic)
	g++ -Wall $(fic) $(LSFML) -o main
	rm -f *.gch entity/*.gch

main.o: main.cpp input.h fenetre.h editeur.h jouer.h
	g++ -c -Wall main.cpp input.h fenetre.h editeur.h jouer.h $(ISFML)

entity/Entity.o: entity/Entity.cpp entity/Entity.h
	g++ -c -Wall entity/Entity.cpp entity/Entity.h $(ISFML)
	mv Entity.o entity/Entity.o

fenetre.o: fenetre.cpp fenetre.h
	g++ -c -Wall fenetre.cpp fenetre.h $(ISFML)

input.o: input.cpp input.h fenetre.h
	g++ -c -Wall input.cpp input.h fenetre.h $(ISFML)

editeur.o: editeur.cpp editeur.h fenetre.h input.h Carte.h
	g++ -c -Wall editeur.cpp editeur.h fenetre.h input.h Carte.h $(ISFML)

jouer.o: jouer.cpp jouer.h fenetre.h 
	g++ -c -Wall jouer.cpp jouer.h fenetre.h $(ISFML)

entity/entity_ronde.o: entity/entity_ronde.cpp entity/entity_ronde.h entity/Entity.h
	g++ -c -Wall entity/entity_ronde.cpp entity/entity_ronde.h entity/Entity.h $(ISFML)
	mv entity_ronde.o entity/entity_ronde.o

entity/entity_rect.o: entity/entity_rect.cpp entity/entity_rect.h entity/Entity.h
	g++ -c -Wall entity/entity_rect.cpp entity/entity_rect.h entity/Entity.h $(ISFML)
	mv entity_rect.o entity/entity_rect.o

entity/arbre.o: entity/arbre.cpp entity/arbre.h entity/entity_ronde.h entity/Entity.h
	g++ -c -Wall entity/arbre.cpp entity/arbre.h entity/entity_ronde.h entity/Entity.h $(ISFML)
	mv arbre.o entity/arbre.o

Carte.o: Carte.cpp Carte.h entity/Entity.h
	g++ -c -Wall Carte.cpp Carte.h entity/Entity.h $(ISFML)

clean:
	rm -f *.o main entity/*.gch

install:
	unzip SFML.zip
	sudo cp -r SFML /usr/local
	rm -f -r SFML

#SFML est installé dans /usr/local

git: clean
	git add -A
	git commit
	git push

