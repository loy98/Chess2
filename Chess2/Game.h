#pragma once
#include "Player.h"
#include "Board.h"
#include "Piece.h"

class Game
{
public:
	Game(Board* board) :_board(board) { }
	void Init();
	void Update();
	void Render();
	void Move();
	void CheckCanGo();
	bool IsKingDead();

	bool _isWhiteTurn = true;
private:
	Board* _board;
	Player* playerW = nullptr;
	Player* playerB = nullptr;
	
};

