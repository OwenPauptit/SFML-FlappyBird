#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Aesel {
	class Bird {
	public:
		Bird(GameDataRef data);

		void DrawBird();

		void Animate(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator;

		sf::Clock _clock;
	};
}