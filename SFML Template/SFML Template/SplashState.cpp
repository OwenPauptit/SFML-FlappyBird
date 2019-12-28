//#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Aesel {
	SplashState::SplashState(GameDataRef data) :_data(data){

	}

	void SplashState::Init() {
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));


	}

	void SplashState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			std::cout << "Go to main menu" << std::endl;
		}
		else {
			return;
		}
	}

	void SplashState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.display();

	}
}