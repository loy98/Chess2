#include "Enum.h"
#pragma once


class Piece
{
public:
	char GetShape() { return _shape; }
	void SetShape(char c) { _shape = c; }
	Pos GetPos() { return _pos; }
	Team GetTeam() { return _team; }
	PieceType GetType() { return _type; }
	void SetPos(Pos pos) { _pos = pos; }
	void SetTeam(Team team) { _team = team; }
	void SetType(PieceType type) { _type = type; }
	virtual void CheckCanGo();

private:
	Pos _pos;
	PieceType _type = PieceType::None;
	Team _team = Team::None;
	char _shape;
};

class Pawn : public Piece
{
public:
	void CheckCanGo() override;

private:
	bool isFirst = true;
};