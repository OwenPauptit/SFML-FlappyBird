#include "Pipe.hpp"

namespace Aesel {
	Pipe::Pipe(GameDataRef data) : _data(data) {

	}

	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites[i]);
		}
	}
}