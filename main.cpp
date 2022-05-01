//SFML Template by NRG Cristi

#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(900, 900), "SFML Project", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	//Main Loop:
	while (window.isOpen()) {

		sf::Event Event;

		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			}

		}
		window.clear();
		window.display();
	}
}