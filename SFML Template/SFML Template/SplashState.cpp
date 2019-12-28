//#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Aesel {
	SplashState::SplashState(GameDataRef data) :_data(data){

	}

	void SplashState::Init() {
		// Load Splash state texture and set it to the sprite _background
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));


	}

	// Check if close button on window has been pressed
	void SplashState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}
		}
	}

	// If more time has passed than the time allocated in DEFINITIONS.hpp, then the main menu will be loaded
	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			std::cout << "Go to main menu" << std::endl;
		}
		else {
			return;
		}
	}


	//Drawing the background to the screen
	void SplashState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.display();

	}
}