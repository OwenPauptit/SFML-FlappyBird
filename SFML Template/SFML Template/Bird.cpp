#include "Bird.hpp"

namespace Aesel {
	Bird::Bird(GameDataRef data) : _data(data) {
		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Bird 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 4"));
		_birdSprite.setTexture(_animationFrames[_animationIterator]);
	}

	void Bird::DrawBird() {
		_data->window.draw(_birdSprite);
	}

	void Bird::Animate(float dt) {
		// if more time has passed than there should be per animation frame, bird texture is changed
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()) {
			// Keeps iterator in valid range
			if (_animationIterator < _animationFrames.size() - 1) {
				_animationIterator++;
			}
			else {
				_animationIterator = 0;
			}
			_birdSprite.setTexture(_animationFrames[_animationIterator]);
			_clock.restart();
		}
	}
}