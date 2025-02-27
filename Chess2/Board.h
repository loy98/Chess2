#include "Piece.h"
#pragma once

class Board
{
public:
	void Init();
	void Update();
	void Render();

private:
	Piece* _board[18][27] = {nullptr};
	Piece* _playboard[8][8] = { nullptr };
};

