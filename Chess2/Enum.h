#pragma once
const int RENDERBOARD_MAX_X = 27;
const int RENDERBOARD_MAX_Y = 18;
const int PLAYBOARD_MAX = 8;
enum class Team
{
	None,
	White,
	Black
};
enum class PieceType
{
	None,
	Pawn,
	Rook,
	Knight,
	Bishop,
	Queen,
	King
};
struct Pos
{
	int x;
	int y;
};

