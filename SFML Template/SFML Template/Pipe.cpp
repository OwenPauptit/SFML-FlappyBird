#include "Pipe.hpp"

namespace Aesel {
	Pipe::Pipe(GameDataRef data) : _data(data) {
		// Used for finding valid values for the Y offset
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}

	// Creates a new sprite for a bottom pipe, and pushes to vector
	void Pipe::SpawnBottomPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		// Sets position to just outside the window, at the random y value
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
		pipeSprites.push_back(sprite);
	}

	// Creates a new sprite for a top pipe, and pushes to vector
	void Pipe::SpawnTopPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		// Sets position to just outside the window, at the random y value
		sprite.setPosition(_data->window.getSize().x,-_pipeSpawnYOffset);
		pipeSprites.push_back(sprite);
	}

	// Fixes jittery bug
	void Pipe::SpawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x,0);
		sprite.setColor(sf::Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnScoringPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition(_data->window.getSize().x, 0);
		scoringPipes.push_back(sprite);
	}


	// Moves the pipes
	void Pipe::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			// Moves the pipes relative to the amount of movements should have passed since the last frame
			float movement = PIPE_MOVEMENT_SPEED * dt;
			pipeSprites[i].move(-movement, 0);
			// Removes the sprite if it is off the screen
			if (pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
		}
		// Used for scoring system
		for (unsigned short int i = 0; i < scoringPipes.size(); i++) {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			scoringPipes[i].move(-movement, 0);
			if (scoringPipes[i].getPosition().x < 0 - scoringPipes[i].getGlobalBounds().width) {
				scoringPipes.erase(scoringPipes.begin() + i);
			}
		}
	}

	// Iterates over vector, and draws each sprite
	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites[i]);
		}
	}

	// Sets the Y offset variable to a random number between 1 and the height of the land
	void Pipe::RandomisePipeOffset() {
		_pipeSpawnYOffset = rand() % (1 + _landHeight);
	}

	const std::vector<sf::Sprite>& Pipe::GetSprites() const {
		return pipeSprites;
	}
	
	std::vector<sf::Sprite>& Pipe::GetScoringSprites() {
		return scoringPipes;
	}
}