#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

namespace Aesel {
	MainMenuState::MainMenuState(GameDataRef data) :_data(data) {

	}

	void MainMenuState::Init() {
		// Load textures and set them to sprites
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		// Adjust position of title and play button
		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}


	void MainMenuState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			// Check if close button on window has been pressed
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}
			if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
				// Replace Main Menu State with Game State in stack
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt) {

	}

	//Drawing the sprites to the screen
	void MainMenuState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();

	}
}