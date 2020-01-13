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
		void SpawnInvisiblePipe();    // fixes a bug
		void MovePipes(float dt);
		void DrawPipes();
		void RandomisePipeOffset();

		const std::vector<sf::Sprite>& GetSprites() const;

	private:
		GameDataRef _data;
		std::vector <sf::Sprite> pipeSprites;

		int _landHeight;
		int _pipeSpawnYOffset;
	};
}