//PLAYER CLASS:
#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

class Player {
public:
	Player() {
		//Default
	}

	Player(std::string imgDirectory) {
		if (!pTexture.loadFromFile(imgDirectory)) {
			std::cerr << "Error\n";
		}
		pSprite.setTexture(pTexture);
	}

	void drawPlayer(sf::RenderWindow& window) {
		window.draw(pSprite);
	}

	void movePlayer(char direction, float moveSpeed) {
		if (direction == 'u') {
			pSprite.move(0, -moveSpeed);
		}
		else if (direction == 'd') {
			pSprite.move(0, moveSpeed);
		}
		else if (direction == 'l') {
			pSprite.move(-moveSpeed, 0);
		}
		else if (direction == 'r') {
			pSprite.move(moveSpeed, 0);
		}
	}
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
};


//MAIN.CPP:
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player Animation.h"

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);

	window.create(sf::VideoMode(1500, 700), "SFML Tutorial", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	Player myPlayer("player.png");

	//Main Loop:
	while (window.isOpen()) {

		sf::Event Event;

		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				myPlayer.movePlayer('u', 6.0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				myPlayer.movePlayer('d', 6.0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				myPlayer.movePlayer('l', 6.0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				myPlayer.movePlayer('r', 6.0);
			}
		}
		window.clear();
		myPlayer.drawPlayer(window);
		window.display();
	}
}