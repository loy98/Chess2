#pragma once
#include "Player.h"
#include "Board.h"
#include "Piece.h"

class Game
{
public:
	void Init();
	void Update();
	void Render();
	bool IsKingDead();

private:
	Board* board;
	Player* players[2];
};

