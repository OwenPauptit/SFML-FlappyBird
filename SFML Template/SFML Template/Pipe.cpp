#include "Pipe.hpp"
#include <iostream>

namespace Aesel {
	Pipe::Pipe(GameDataRef data) : _data(data) {

	}

	void Pipe::SpawnBottomPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x,0);
		pipeSprites.push_back(sprite);
	}

	/*void Pipe::SpawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x,0);
		sprite.setColor(sf::Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}*/

	void Pipe::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			pipeSprites[i].move(-movement, 0);
			if (pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
		}
		std::cout << pipeSprites.size() << std::endl;
	}

	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites[i]);
		}
	}
}