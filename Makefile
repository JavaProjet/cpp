ISFML=-I/usr/local/SFML/include
LSFML=-lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/SFML/lib
RSFML=export LD_LIBRARY_PATH=/usr/local/SFML/lib &&
ficCpp = main.cpp	entity/Entity.cpp fenetre.cpp input.cpp editeur.cpp jouer.cpp entity/entity_rect.cpp entity/entity_ronde.cpp entity/arbre.cpp Carte.cpp entity/Cactus.cpp entity/Rocher.cpp entity/Tronc.cpp entity/Joueur.cpp
ficH   = 			entity/Entity.h   fenetre.h   input.h   editeur.h   jouer.h   entity/entity_rect.h   entity/entity_ronde.h   entity/arbre.h   Carte.h   entity/Cactus.h   entity/Rocher.h   entity/Tronc.h   entity/Joueur.h
ficO   = main.o			   Entity.o   fenetre.o   input.o   editeur.o   jouer.o          entity_rect.o          entity_ronde.o   arbre.o          Carte.o   Cactus.o          Rocher.o          Tronc.o          Joueur.o

all: main run

run:
	$(RSFML) ./main

main: $(ficO)
	g++ -Wall $(ficO) $(LSFML) -o main
	rm -f *.gch entity/*.gch

main.o: main.cpp input.h fenetre.h editeur.h jouer.h
	g++ -c -Wall main.cpp input.h fenetre.h editeur.h jouer.h $(ISFML)

Entity.o: entity/Entity.cpp entity/Entity.h fenetre.h
	g++ -c -Wall entity/Entity.cpp entity/Entity.h fenetre.h $(ISFML)

fenetre.o: fenetre.cpp fenetre.h
	g++ -c -Wall fenetre.cpp fenetre.h $(ISFML)

input.o: input.cpp input.h fenetre.h
	g++ -c -Wall input.cpp input.h fenetre.h $(ISFML)

editeur.o: editeur.cpp editeur.h fenetre.h input.h Carte.h entity/arbre.h entity/Cactus.h entity/Rocher.h entity/Tronc.h entity/Joueur.h
	g++ -c -Wall editeur.cpp editeur.h fenetre.h input.h Carte.h entity/arbre.h entity/Cactus.h entity/Rocher.h entity/Tronc.h entity/Joueur.h $(ISFML)

jouer.o: jouer.cpp jouer.h fenetre.h 
	g++ -c -Wall jouer.cpp jouer.h fenetre.h $(ISFML)

entity_ronde.o: entity/entity_ronde.cpp entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/entity_ronde.cpp entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

entity_rect.o: entity/entity_rect.cpp entity/entity_rect.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/entity_rect.cpp entity/entity_rect.h entity/Entity.h fenetre.h $(ISFML)

arbre.o: entity/arbre.cpp entity/arbre.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/arbre.cpp entity/arbre.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

Carte.o: Carte.cpp Carte.h entity/Entity.h entity/arbre.h fenetre.h entity/Cactus.h entity/Rocher.h entity/Tronc.h entity/Joueur.h
	g++ -c -Wall Carte.cpp Carte.h entity/Entity.h entity/arbre.h fenetre.h entity/Cactus.h entity/Rocher.h entity/Tronc.h entity/Joueur.h $(ISFML)
	
Cactus.o: entity/Cactus.cpp entity/Cactus.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/Cactus.cpp entity/Cactus.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)
	
Rocher.o: entity/Rocher.cpp entity/Rocher.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/Rocher.cpp entity/Rocher.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

Joueur.o: entity/Joueur.cpp entity/Joueur.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/Joueur.cpp entity/Joueur.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)
	
Tronc.o: entity/Tronc.cpp entity/Tronc.h entity/entity_rect.h entity/Entity.h fenetre.h
	g++ -c -Wall entity/Tronc.cpp entity/Tronc.h entity/entity_rect.h entity/Entity.h fenetre.h $(ISFML)



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


main2:
	g++ -Wall $(ficCpp) $(ficH) $(ISFML) $(LSFML) -o main
