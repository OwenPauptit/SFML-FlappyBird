#include "HUD.hpp"
#include <string>

namespace Aesel {
	HUD::HUD(GameDataRef data) : _data(data) {
		// Set up sf::Text
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString("0");
		_scoreText.setCharacterSize(FLAPPY_FONT_SIZE);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 8);
	}

	void HUD::Draw(){
		_data->window.draw(_scoreText);
	}

	void HUD::UpdateScore(int score) {
		_scoreText.setString(std::to_string(score));
	}

}
