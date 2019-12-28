#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {
	GameOverState::GameOverState(GameDataRef data) :_data(data) {

	}

	void GameOverState::Init() {
		// Load textures and set them to sprites
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Over Title"));


	}

	// Check if close button on window has been pressed
	void GameOverState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			// Check if close button on window has been pressed
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}

		}
	}

	void GameOverState::Update(float dt) {

	}


	//Drawing the background to the screen
	void GameOverState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);

		this->_data->window.display();

	}
}