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
	void Move();

private :
	Team _team = Team::None;
	Piece* _pieces[16] = { nullptr };
	Board* _board;
};

