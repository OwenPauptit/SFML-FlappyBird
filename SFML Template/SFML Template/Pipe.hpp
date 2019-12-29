#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"


namespace Aesel {
	class Pipe {
	public:
		Pipe(GameDataRef data);

		void SpawnBottomPipe();
		void SpawnTopPipe();
		//void SpawnInvisiblePipe();    <- ignore
		void MovePipes(float dt);
		void DrawPipes();

	private:
		GameDataRef _data;
		std::vector <sf::Sprite> pipeSprites;
	};
}