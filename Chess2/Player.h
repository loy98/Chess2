#pragma once
#include "Enum.h"
#include "Piece.h"
#include "Board.h"
class Player
{
public :
	Player() {}
	Player(Board* board): _renderBoard(board) {}

private :
	Team _team = Team::None;
	Piece* _pieces[16];
	Board* _renderBoard;
};

