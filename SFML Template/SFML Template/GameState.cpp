#include <sstream>
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {
	GameState::GameState(GameDataRef data) :_data(data) {

	}

	void GameState::Init() {
		// Load textures
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);

		_data->assets.LoadTexture("Bird 1", BIRD_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Bird 2", BIRD_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Bird 3", BIRD_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Bird 4", BIRD_FRAME_4_FILEPATH);

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));


	}

	void GameState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			// Check if close button on window has been pressed
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}

			// If the user clicks inside the window
			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {

			}
		}
	}

	
	void GameState::Update(float dt) {
		// Move all the pipes
		pipe->MovePipes( dt );
		land->MoveLand(dt);

		// If the right amount of time has passed, spawn a pipe
		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
			pipe->RandomisePipeOffset();
			pipe->SpawnInvisiblePipe(); // fixes a bug
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
		land->DrawLand();
		bird->DrawBird();

		this->_data->window.display();

	}
}