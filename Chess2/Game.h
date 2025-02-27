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
	Board* _board;
	Player* _players[2];
};

