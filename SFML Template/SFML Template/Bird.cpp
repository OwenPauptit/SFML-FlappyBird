#include "Bird.hpp"

namespace Aesel {
	Bird::Bird(GameDataRef data) : _data(data) {
		_birdSprite.setTexture(_data->assets.GetTexture("Bird 1"));

	}

	void Bird::DrawBird() {
		_data->window.draw(_birdSprite);
	}
}