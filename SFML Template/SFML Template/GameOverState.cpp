#include <sstream>
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {
	GameOverState::GameOverState(GameDataRef data, int score) :_data(data), _score(score) {

	}

	void GameOverState::Init() {
		// Load textures and set them to sprites
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

		_background.setTexture(_data->assets.GetTexture("Game Over Background"));
		_title.setTexture(_data->assets.GetTexture("Game Over Title"));
		_body.setTexture(_data->assets.GetTexture("Game Over Body"));
		_retryButton.setTexture(_data->assets.GetTexture("Play Button"));

		_body.setPosition((_data->window.getSize().x / 2) - (_body.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_body.getGlobalBounds().height / 2));
		_title.setPosition((_data->window.getSize().x / 2) - (_title.getGlobalBounds().width / 2), _body.getPosition().y - (_title.getGlobalBounds().height * 1.2));
		_retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _body.getPosition().y + (_body.getGlobalBounds().height * 1.1));
		
		// Set up texts
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(GAME_OVER_SCORE_SIZE);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);

		_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(GAME_OVER_SCORE_SIZE);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);
	}

	// Check if close button on window has been pressed
	void GameOverState::HandleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			// Check if close button on window has been pressed
			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

		}
	}

	void GameOverState::Update(float dt) {

	}


	//Drawing the background to the screen
	void GameOverState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_body);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);

		_data->window.display();

	}
}