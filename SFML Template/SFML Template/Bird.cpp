#include "Bird.hpp"

namespace Aesel {
	Bird::Bird(GameDataRef data) : _data(data) {
		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Bird 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 4"));
		_birdSprite.setTexture(_animationFrames[_animationIterator]);

		_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));

		_birdState = BIRD_STATE_STILL;
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

	// moves the bird depending on whether it is flying or falling
	void Bird::Update(float dt) {

		if (_birdState == BIRD_STATE_FALLING) {
			_birdSprite.move(0, GRAVITY * dt);
		}
		else if (_birdState == BIRD_STATE_FLYING) {
			_birdSprite.move(0, -FLYING_SPEED * dt);
		}

		// Switch from flying to falling
		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION ) {
			_movementClock.restart();
			_birdState = BIRD_STATE_FALLING;
		}
	}

	void Bird::Tap() {
		_movementClock.restart();
		_birdState = BIRD_STATE_FLYING;
	}
}