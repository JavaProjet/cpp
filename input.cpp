#include "input.h"

string drawInput(Fenetre& w,int x, int y, int size, int nbChar){
	char* str = new char[nbChar + 1];
	for (int i = 0; i < nbChar; i++){
		str[i] = '\0';
	}
	bool maj = false;
	sf::Event event;
	bool stop = false;
	int cursor = 0;
	while(!stop && w.isOpen()){
		while (w.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                w.close();
			}
            else if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return)stop = true;
				if(cursor < nbChar - 1){
					if(event.key.code >= 0 && event.key.code <= 25){
						if(!maj) str[cursor++] = 'a' + event.key.code;
						else str[cursor++] = 'A' + event.key.code;
					}
					if(event.key.code == sf::Keyboard::Space) str[cursor++] = ' ';
				}
				if(cursor > 0){
					if(event.key.code == sf::Keyboard::BackSpace) str[--cursor] = '\0';
				}
				if(event.key.code == sf::Keyboard::LShift) maj = true;
			}
			if(event.type == sf::Event::KeyReleased){
				if(event.key.code == sf::Keyboard::LShift) maj = false;
			}
		}
		w.drawRect(x,y,w.getFont(nbChar, size), size, sf::Color::White);
		w.write(str,size - 1, sf::Color::Black, x, y - size / 8);
		w.getWindow().display();
	}
	string s = str;
	return s;
}

