#pragma once
#include "Enum.h"
#include "Piece.h"
#include "Board.h"
class Player
{
public :


private :
	Team _team = Team::None;
	Piece* _pieces[16];
	Board* _board;
};

