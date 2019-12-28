#include "AssetManager.hpp"

namespace Aesel {
	// Attempts to load the texture, if succesful, assigns the texture to its name in the map
	void AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;

		if (tex.loadFromFile(fileName)) {
			this->_textures[name] = tex;
		}
	}

	// return the texture with the name in the parameter name
	sf::Texture& AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}
	

	//Exactly same process as for textures, except for fonts
	void AssetManager::LoadFont(std::string name, std::string fileName) {
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}
}