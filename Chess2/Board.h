#include "Piece.h"
#pragma once

class Board
{
public:
	void Init();
	void Render();
	

private:
	Piece* _board[18][27] = {nullptr};
};

