#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Aesel {

	// A struct of the classes that will be accessible by all parts of the program
	struct GameData {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr <GameData> GameDataRef;

	class Game {
	public:
		// contstuctor to create and run game
		Game(int width, int height, std::string title);
	private:
		// dt is the time for 1 frame, it is set to 1/60 which is 60fps
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		// Pointer to the classes that will be accessible by all
		GameDataRef _data = std::make_shared <GameData>();

		// game loop
		void Run();
	};
}