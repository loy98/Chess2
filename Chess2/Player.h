#pragma once
#include "Enum.h"
#include "Piece.h"
#include "Board.h"
class Player
{
public :
	Player() {}
	Player(Board* board, Team team);
	void Update();
	void ChoicePiece();

	char GetFromX() { return fromX; }
	char GetFromY() { return fromY; }
private :
	Team _team = Team::None;
	Piece* _pieces[16] = { nullptr };
	Board* _board;
	char fromX;
	char fromY;
};

