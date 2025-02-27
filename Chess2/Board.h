#include "Piece.h"
#pragma once

class Board
{
public:
	void Init();
	void Update();
	void Render();

private:
	Piece* _renderBoard[18][27] = {nullptr};
	Piece* _playBoard[8][8] = { nullptr };
};

