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
	bool IsKingDead(Player* player);
	Player* GetPlayerW() { return playerW; }
	Player* GetPlayerB() { return playerB; }
	bool GetIsWhiteTurn() { return _isWhiteTurn; }
	void SetIsWhiteTurn(bool turn) { _isWhiteTurn = turn; }
	Board* GetBoard() { return _board; }
private:
	Board* _board;
	Player* playerW = nullptr;
	Player* playerB = nullptr;
	bool _isWhiteTurn = true;
};

