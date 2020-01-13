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
		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
		_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_score = 0;
		hud->UpdateScore(_score);

		_gameState = GameStates::eReady;
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
				if (_gameState != GameStates::eGameOver) {
					_gameState = GameStates::ePlaying;
					bird->Tap();
				}
			}
		}
	}

	
	void GameState::Update(float dt) {
		// Animations that happen before and during playing
		if (_gameState != GameStates::eGameOver) {
			land->MoveLand(dt);
			bird->Animate(dt);
		}

		// Processes that happen only when player is playing
		if (_gameState == GameStates::ePlaying) {
			pipe->MovePipes(dt);
			// If the right amount of time has passed, spawn a pipe
			if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
				pipe->RandomisePipeOffset();
				pipe->SpawnInvisiblePipe(); // fixes a bug
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();
				_clock.restart();
			}

			bird->Update(dt);

			// Checks bird collisions
			std::vector<sf::Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), BIRD_LAND_COLLISION_SCALE, landSprites[i], LAND_COLLISION_SCALE)) {
					_gameState = GameStates::eGameOver;
					//_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				}
			}
			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
			for (int i = 0; i < pipeSprites.size(); i++) {
				if (pipeSprites[i].getColor() != sf::Color(0, 0, 0, 0)) {
					if (collision.CheckSpriteCollision(bird->GetSprite(), BIRD_PIPE_COLLISION_SCALE, pipeSprites[i],PIPE_COLLISION_SCALE)) {
						_gameState = GameStates::eGameOver;
					}
				}
			}
			// Updating score if bird passes through a scoring pipe
			if (_gameState == GameStates::ePlaying) {
				std::vector<sf::Sprite>& scoringSprites = pipe->GetScoringSprites();
				for (int i = 0; i < scoringSprites.size(); i++) {
					if (scoringSprites[i].getColor() != sf::Color(0, 0, 0, 0)) {
						if (collision.CheckSpriteCollision(bird->GetSprite(), BIRD_PIPE_COLLISION_SCALE, scoringSprites[i], PIPE_COLLISION_SCALE)) {
							_score++;
							hud->UpdateScore(_score);
							scoringSprites.erase(scoringSprites.begin() + i);
						}
					}
				}
			}
		}

		if (_gameState == GameStates::eGameOver) {
			flash->Show(dt);
		}

	}


	//Drawing the Sprites to the screen
	void GameState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		pipe->DrawPipes();
		land->DrawLand();
		bird->DrawBird();
		flash->Draw();
		hud->Draw();

		this->_data->window.display();

	}
}