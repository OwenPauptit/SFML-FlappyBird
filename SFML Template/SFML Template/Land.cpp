#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {

	Land::Land(GameDataRef data) : _data(data) {

		// Use two sprites for continuous movement
		sf::Sprite sprite(_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(_data->assets.GetTexture("Land"));

		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);

	}

	void Land::MoveLand(float dt) {
		for (unsigned short int i = 0; i < _landSprites.size(); i++) {

			// Get the amount of movement based on time
			float movement = PIPE_MOVEMENT_SPEED * dt;

			_landSprites[i].move(-movement, 0.0f);

			// Move to right of window if off the left side of the screen
			if (_landSprites[i].getPosition().x < 0 - _landSprites[i].getGlobalBounds().width) {
				sf::Vector2f position(_data->window.getSize().x, _landSprites[i].getPosition().y);
				_landSprites[i].setPosition(position);
			}

		}
	}

	void Land::DrawLand() {
		// Iterate over vector, and draw each sprite
		for (unsigned short int i = 0; i < _landSprites.size(); i++){
			_data->window.draw(_landSprites[i]);
		}
	}

}