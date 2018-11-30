#include "editeur.h"
#include "fenetre.h"
#include "input.h"
#include <iostream>

using namespace std;

void nouvelle(){
    Fenetre window(600,500,"");
    window.getWindow().clear(sf::Color::Green);
    window.getWindow().display();
    window.draw_line(window.wait_clic(), window.wait_clic(),sf::Color::Red);
    window.getWindow().display();
    window.wait_clic();
}

void modifier(){
    Fenetre window(600,500,"test clic");
    Input a(&window,sf::Vector2i(10,10),30,20),b(&window,sf::Vector2i(10,50),30,20),c(&window,sf::Vector2i(10,90),30,20);
    while(window.isOpen()){
        window.getWindow().clear(sf::Color::Yellow);
        Input::get_clic(window);
        a.drawInput();
        b.drawInput();
        c.drawInput();
        window.getWindow().display();
    }
    cout << endl;
}

int menuEdition(){
    int choix = -1;
	Fenetre window(600,500,"Menu");
	while (window.isOpen() && choix < 0){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                choix = 0;
			}
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Up && choix < -1) choix++;
				if(event.key.code == sf::Keyboard::Down && choix > -3 ) choix--;
				if(event.key.code == sf::Keyboard::Return) choix = -choix;
			}
        }
        window.getWindow().clear(sf::Color(160,62,35));
        window.drawSprite(0,0,600,500,"fond.png");
        
        window.write("Nouvelle carte", 40, sf::Color::Black, 200, 100);
        window.write("Modifier une carte", 40, sf::Color::Black, 170, 220);
        window.write("Retour vers le menu", 40, sf::Color::Black, 165, 340);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::Black, 120, 100);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::Black, 120, 220);
		}
        else if(choix == -3){
			window.write(">", 40, sf::Color::Black, 120, 340);
		}

        window.getWindow().display();
    }
    return choix;
}

int editeur(){
    int choix = -1;

    choix = menuEdition();
    
    if(choix == 1){
        //nouvelle carte
        nouvelle();
    }
    else if(choix == 2){
        //modification de carte
        modifier();
    }

	return choix;
}
