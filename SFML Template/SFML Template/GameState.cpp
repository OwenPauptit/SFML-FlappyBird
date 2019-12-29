#include <sstream>
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {
	GameState::GameState(GameDataRef data) :_data(data) {

	}

	void GameState::Init() {
		// Load textures and set them to sprites
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		pipe = new Pipe(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));


	}

	void GameState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			// Check if close button on window has been pressed
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}

			// For Testing:
			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {


				// Replace Game State with GameOver State in stack
				//_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
	}

	
	void GameState::Update(float dt) {
		pipe->MovePipes( dt );

		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			_clock.restart();
		}
	}


	//Drawing the Sprites to the screen
	void GameState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		pipe->DrawPipes();

		this->_data->window.display();

	}
}