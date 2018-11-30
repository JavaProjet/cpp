#include "input.h"

/*
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
*/
bool findFocus = false;
int Input::nbInstance = 0;
int Input::nbInstanceActif = 0;
sf::Vector2i Input::clic(0,0);
int Input::focus = -1;
bool maj = false;

void Input::drawInput(){
	cout << id << "  ?  " << focus << endl;
	if(clic.x >= posInput.x && clic.x <= posInput.x + sizeX && clic.y >= posInput.y && clic.y <= posInput.y + sizeText){
		focus = id;
		findFocus = true;
	}

	if(focus == id){
		
		sf::Event event;
		while (w->getWindow().pollEvent(event)){
			if (event.type == sf::Event::Closed){
				w->close();
			}
			else if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return)focus = -1;
				if(cursor < maxChar - 1){
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
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					clic = sf::Mouse::getPosition(w->getWindow());
				}
			}
		}
		w->drawRect(posInput.x,posInput.y,sizeX, sizeText, sf::Color(127,127,127));
	}
	if(focus != id) w->drawRect(posInput.x,posInput.y,sizeX, sizeText, sf::Color::White);
	
	w->write(str,sizeText - 1, sf::Color::Black, posInput.x, posInput.y - sizeText / 8);
}

Input::Input(Fenetre* _w, sf::Vector2i posInput, int sizeText, int maxChar) {
	str = new char[maxChar + 1];
	for (int i = 0; i < maxChar + 1; i++){
		str[i] = '\0';
	}
	w = _w;
	nbInstanceActif++;
	id = nbInstance++;
	this->posInput = posInput;
	sizeX = w->getFont(maxChar, sizeText);
	this->sizeText = sizeText; //sizeY
	this->maxChar = maxChar;
	cursor = 0;
}

Input::~Input(){
	delete[] str;
	nbInstanceActif--;
	if(nbInstanceActif == 0) focus = -1;
}

char* Input::getString(){
	return str;
}

sf::Vector2i Input::get_clic(Fenetre& w){
	if(findFocus == false) focus = -1;
	if(focus == -1){
		sf::Event event;
		while (w.getWindow().pollEvent(event)){
			if (event.type == sf::Event::Closed){
				w.close();
			}
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					clic = sf::Mouse::getPosition(w.getWindow());
				}
			}
		}
	}
	findFocus = false;
	return clic;
}
