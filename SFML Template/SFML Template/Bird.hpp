#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Aesel {
	class Bird {
	public:
		Bird(GameDataRef data);

		void DrawBird();

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;
	};
}