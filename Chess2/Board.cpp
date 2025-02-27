#include <iostream>
#include "Board.h"
using namespace std;
void Board::Init()
{
	for (int y = 0; y < 18; ++y)
	{
		for (int x = 0; x < 27; ++x)
		{
			_renderBoard[y][x] = new Piece;
			_renderBoard[y][x]->SetPos({ x, y });
		}
	}
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			_playBoard[y][x] = new Piece;
			_playBoard[y][x]->SetShape(32);
			_playBoard[y][x]->SetPos({ x, y });
		}
	}
	for (int y = 0; y < 18; ++y)
	{
		for (int x = 0; x < 27; ++x)
		{
			if (x < 25 && y < 17)
			{
				if (x % 3 == 0)
				{
					if (y % 2 == 0)
						_renderBoard[y][x]->SetShape(32);
					else
						_renderBoard[y][x]->SetShape(124);
				}
				else if (y % 2 == 0)
				{
					_renderBoard[y][x]->SetShape(45);
				}
				else
					_renderBoard[y][x]->SetShape(32);
			}
			else
				_renderBoard[y][x]->SetShape(32);
		}
	}
	char alphabet = 65;
	for (int i = 1; i < 23; i += 3)
	{
		_renderBoard[17][i]->SetShape(alphabet);
		alphabet++;
	}
	int num = 56;
	for (int i = 1; i < 17; i += 2)
	{
		_renderBoard[i][26]->SetShape(num);
		num--;
	}

	for (int i = 0; i < 8; ++i)
	{
		_playBoard[0][i]->SetShape('B');
		_playBoard[0][i]->SetTeam(Team::Black);
	}

	
	_playBoard[0][0]->SetType(PieceType::Rook);
	_playBoard[0][1]->SetType(PieceType::Knight);
	_playBoard[0][2]->SetType(PieceType::Bishop);
	_playBoard[0][3]->SetType(PieceType::King);
	_playBoard[0][4]->SetType(PieceType::Queen);
	_playBoard[0][5]->SetType(PieceType::Bishop);
	_playBoard[0][6]->SetType(PieceType::Knight);
	_playBoard[0][7]->SetType(PieceType::Rook);

	for (int i = 0; i < 8; ++i)
	{
		_playBoard[1][i]->SetShape('B');
		_playBoard[1][i]->SetTeam(Team::Black);
		_playBoard[1][i]->SetType(PieceType::Pawn);
	}

	for (int i = 0; i < 8; ++i)
	{
		_playBoard[7][i]->SetShape('W');
		_playBoard[7][i]->SetTeam(Team::White);
	}

	_playBoard[7][0]->SetType(PieceType::Rook);
	_playBoard[7][1]->SetType(PieceType::Knight);
	_playBoard[7][2]->SetType(PieceType::Bishop);
	_playBoard[7][3]->SetType(PieceType::King);
	_playBoard[7][4]->SetType(PieceType::Queen);
	_playBoard[7][5]->SetType(PieceType::Bishop);
	_playBoard[7][6]->SetType(PieceType::Knight);
	_playBoard[7][7]->SetType(PieceType::Rook);

	for (int i = 0; i < 8; ++i)
	{
		_playBoard[6][i]->SetShape('W');
		_playBoard[6][i]->SetTeam(Team::White);
		_playBoard[6][i]->SetType(PieceType::Pawn);
	}
}

void Board::Update()
{
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			_renderBoard[15 - 2*y][1 + 3 * x] = _playBoard[y][x];
		}
	}
}

void Board::Render()
{
	for (int y = 0; y < 18; ++y)
	{
		for (int x = 0; x < 27; ++x)
		{
			PieceType type = _renderBoard[y][x]->GetType();
			cout << _renderBoard[y][x]->GetShape();
			switch (type)
			{
			case PieceType::King:
				_renderBoard[y][x + 1]->SetShape('K');
				break;
			case PieceType::Queen:
				_renderBoard[y][x + 1]->SetShape('Q');
				break;
			case PieceType::Knight:
				_renderBoard[y][x + 1]->SetShape('N');
				break;
			case PieceType::Rook:
				_renderBoard[y][x + 1]->SetShape('R');
				break;
			case PieceType::Pawn:
				_renderBoard[y][x + 1]->SetShape('P');
				break;
			case PieceType::Bishop:
				_renderBoard[y][x + 1]->SetShape('B');
				break;
			}
		}
		cout << endl;
	}
}

bool Board::CanGo(Piece* piece, int toX, int toY)
{
	int nowX = piece->GetPos().x;
	int nowY = piece->GetPos().y;
	PieceType type = piece->GetType();
	Team team = piece->GetTeam();
	switch (type)
	{
	case PieceType::Pawn : 
		if (team == Team::White)
		{
			if (toX == nowX && toY == nowY) {
				return false; break;
			}
			else if (toY - nowY != -1) {
				return false; break;
			}
			else if (abs(toX - nowX) > 1) {
				return false; break;
			}
			else if (toX == nowX)
			{
				if (_playBoard[toY][toX]->GetType() == PieceType::None)
				{
					return true; break;
				}
				else
					return false;
			}
			else if (piece->GetTeam() != _playBoard[toY][toX]->GetTeam()) {
				return false; break;
			}
			else
				return true;
		}
		else
		{
			return true;
		}
		break;
	default : 
		return false;
		break;
	}
}

void Board::MovePiece(int fromX, int fromY, int toX, int toY)
{
	Piece* prev = _playBoard[fromY][fromX];
	_playBoard[toY][toX]->SetShape(prev->GetShape());
	_playBoard[toY][toX]->SetTeam(prev->GetTeam());
	_playBoard[toY][toX]->SetType(prev->GetType());
	
	_playBoard[fromY][fromX]->SetShape(32);
	_renderBoard[15 - 2 * fromY][1 + 3 * fromX + 1]->SetShape(32);
	_playBoard[fromY][fromX]->SetTeam(Team::None);
	_playBoard[fromY][fromX]->SetType(PieceType::None);

}
