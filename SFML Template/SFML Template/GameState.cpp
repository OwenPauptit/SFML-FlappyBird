#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {
	GameState::GameState(GameDataRef data) :_data(data) {

	}

	void GameState::Init() {
		// Load Splash state texture and set it to the sprite _background
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));


	}

	// Check if close button on window has been pressed
	void GameState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}
		}
	}

	// If more time has passed than the time allocated in DEFINITIONS.hpp, then the main menu will be loaded
	void GameState::Update(float dt) {
		
	}


	//Drawing the background to the screen
	void GameState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.display();

	}
}