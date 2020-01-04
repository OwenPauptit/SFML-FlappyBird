#include "Pipe.hpp"

namespace Aesel {
	Pipe::Pipe(GameDataRef data) : _data(data) {

	}

	// Creates a new sprite for a bottom pipe, and pushes to vector
	void Pipe::SpawnBottomPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		pipeSprites.push_back(sprite);
	}

	// Creates a new sprite for a top pipe, and pushes to vector
	void Pipe::SpawnTopPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x,0);
		pipeSprites.push_back(sprite);
	}

	// Fixes jittery bug
	void Pipe::SpawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x,0);
		sprite.setColor(sf::Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}

	// Moves the pipes
	void Pipe::MovePipes(float dt) {
		//iterates over vector
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			// Moves the pipes relative to the amount of movements should have passed since the last frame
			float movement = PIPE_MOVEMENT_SPEED * dt;
			pipeSprites[i].move(-movement, 0);
			// Removes the sprite if it is off the screen
			if (pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
		}
	}

	// Iterates over vector, and draws each sprite
	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites[i]);
		}
	}
}