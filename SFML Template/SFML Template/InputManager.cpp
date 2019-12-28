#include "InputManager.hpp"

namespace Aesel {

	// See if the mouse button 'button' (left click, right click etc.) is clicked, and mouse is over the sprite
	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) {
		
		// If the button passed into the function has been pressed on the mouse
		if (sf::Mouse::isButtonPressed(button)) {
			// Create a temporary IntRect of the sprite
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
			
			// Returns true if the mouse is inside the sprite's IntRect
			if (tempRect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}
		}
		return false;
	}

	//returns the mouse's position
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window);
	}
}
