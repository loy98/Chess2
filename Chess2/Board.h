#include "Piece.h"
#pragma once

class Board
{
public:
	void Init();
	void Update();
	void Render();
	bool CanGo(Piece* piece, int toX, int toY);
	void MovePiece(int fromX, int fromY, int toX, int toY);

	Piece* GetPlayPiece(int x, int y) { return _playBoard[y][x]; }

private:
	Piece* _renderBoard[RENDERBOARD_MAX_Y][RENDERBOARD_MAX_X] = { nullptr };
	Piece* _playBoard[8][8] = { nullptr };
	
};

