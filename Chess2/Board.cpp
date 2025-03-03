#include <iostream>
#include "Board.h"
using namespace std;
void Board::Init()
{
	for (int y = 0; y < RENDERBOARD_MAX_Y; ++y)
	{
		for (int x = 0; x < RENDERBOARD_MAX_X; ++x)
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
	for (int y = 0; y < RENDERBOARD_MAX_Y; ++y)
	{
		for (int x = 0; x < RENDERBOARD_MAX_X; ++x)
		{
			if (x < RENDERBOARD_MAX_X-2 && y < 17)
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
	for (int i = 1; i < RENDERBOARD_MAX_X-4; i += 3)
	{
		_renderBoard[RENDERBOARD_MAX_Y-1][i]->SetShape(alphabet);
		alphabet++;
	}
	int num = 56;
	for (int i = 1; i < RENDERBOARD_MAX_Y-1; i += 2)
	{
		_renderBoard[i][RENDERBOARD_MAX_X-1]->SetShape(num);
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
	for (int y = 0; y < RENDERBOARD_MAX_Y; ++y)
	{
		for (int x = 0; x < RENDERBOARD_MAX_X; ++x)
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
	case PieceType::Pawn: {
		int dir = (team == Team::White) ? -1 : 1;
		int firstY = (team == Team::White) ? 6 : 1;

		//���� ����
		if (toX == nowX) {
			//1ĭ����
			if (toY - nowY == dir) {
				// ������ ĭ�� ���� ������ �̵� �Ұ�
				if (_playBoard[toY][toX]->GetTeam() != Team::None)
					return false;
				else
					return true;
			}
			//2ĭ���� : ���� Y�� �����Ҷ� Y�̰�, �����°��� �ι� �����Ѱ��϶�
			if (nowY == firstY && (toY - nowY == dir * 2)) {
				// 1ĭ���̳� 2ĭ�տ� ���� ������ �̵� �Ұ�
				if (_playBoard[nowY + dir][toX]->GetTeam() != Team::None ||
					_playBoard[toY][toX]->GetTeam() != Team::None)
					return false;
				else
					return true;
			}
		}
		//�밢 ����
		if (abs(toX - nowX) == 1 && (toY - nowY == dir)) {
			Piece* target = _playBoard[toY][toX];
			if (target->GetTeam() != Team::None &&
				target->GetTeam() != team)
				return true;
			else
				return false;
		}
		return false;
	}
	case PieceType::Rook: {
		// ���� Ȥ�� ���� �̵��� �ƴϸ� �̵� �Ұ�
		if (toX != nowX && toY != nowY)
			return false;
		// ��� ��ġ�� ���� ��ġ�� ������ �̵� �Ұ�
		if (toX == nowX && toY == nowY)
			return false;

		// �̵� ���� ����
		int dx = 0, dy = 0;
		if (toX - nowX == 0) 
			dy = (toY - nowY) / abs(toY - nowY);
		else if (toY - nowY == 0)
			dx = (toX - nowX) / abs(toX - nowX);

		// ��� ĭ �ٷ� �������� ���� ĭ �ٷ� ������ ��ο� ���� �ִ��� �˻�
		int nextX = nowX + dx;
		int nextY = nowY + dy;
		while (nextX != toX || nextY != toY) {
			if (_playBoard[nextY][nextX]->GetType() != PieceType::None)
				return false;
			nextX += dx;
			nextY += dy;
		}

		// ���� ĭ �˻�
		Piece* target = _playBoard[toY][toX];
		if (target->GetTeam() == team)
			return false;

		return true;
	}
	case PieceType::Knight: {
		Pos canGoPos[8] =
		{
			{nowX + 1, nowY + 2},
			{nowX + 1, nowY - 2},
			{nowX - 1, nowY + 2},
			{nowX - 1, nowY - 2},
			{nowX + 2, nowY + 1},
			{nowX + 2, nowY - 1},
			{nowX - 2, nowY + 1},
			{nowX - 2, nowY - 1},
		};
		// �� ��ġ�� ���� �� ���� ������ �̵�����
		for (int i = 0; i < 8; ++i)
		{
			int canGoX = canGoPos[i].x;
			int canGoY = canGoPos[i].y;
			//�Է¹��� ��ġ�� nextPos �ȿ� �ְ�, �ش� ��ġ�� �츮�� ���� ���ٸ� �̵�����
			if ((toX == canGoX && toY == canGoY) &&
				(_playBoard[toY][toX]->GetTeam() != team))
				return true;
		}
		return false;
	}
	case PieceType::Bishop: {
		// ������ ��ġ�� �밢���� ������ �̵� �Ұ�
		if (abs(toX - nowX) != abs(toY - nowY))
			return false;
		// ������ ��ġ�� ���� ��ġ��� �̵� �Ұ�
		if (toX == nowX && toY == nowY)
			return false;
		// �̵� ���� ����
		int dx = (toX - nowX) / abs(toX - nowX);
		int dy = (toY - nowY) / abs(toY - nowY);
		
		int nextX = nowX + dx;
		int nextY = nowY + dy;
		// ������ ��ġ ��ĭ ���� ��ĭ�� üũ
		while (nextX != toX) {
			// �̵��� ����ĭ�� ���� ������ �̵� �Ұ�
			if (_playBoard[nextY][nextX]->GetType() != PieceType::None)
				return false;
			nextX += dx;
			nextY += dy;
		}
		// ������ ��ġ�� ���� �츮���̸� �̵� �Ұ�
		Piece* target = _playBoard[toY][toX];
		if (target->GetTeam() == team)
			return false;
		
		return true;
	}
	case PieceType::Queen: {
		int dx = 0, dy = 0;
		// ������ ��ġ�� ���� ��ġ��� �̵� �Ұ�
		if (toX == nowX && toY == nowY)
			return false;
		// ������ ��ġ�� �밢���� ������
		if (abs(toX - nowX) == abs(toY - nowY)) {
			dx = (toX - nowX) / abs(toX - nowX);
			dy = (toY - nowY) / abs(toY - nowY);
		}
		// ���� Ȥ�� ���� �̵��̸� 
		else if (toX - nowX == 0)
			dy = (toY - nowY) / abs(toY - nowY);
		else if (toY - nowY == 0)
			dx = (toX - nowX) / abs(toX - nowX);
		// ���� �� ��찡 �ƴ϶�� �̵� �Ұ�
		else
			return false;

		int nextX = nowX + dx;
		int nextY = nowY + dy;
		while (nextX != toX || nextY != toY) {
			if (_playBoard[nextY][nextX]->GetTeam() != Team::None)
				return false;
			nextX += dx;
			nextY += dy;
		}

		Piece* target = _playBoard[toY][toX];
		if (target->GetTeam() != team)
			return true;

		return false;
	}
	case PieceType::King: {
		Pos canGoPos[8] =
		{
			{nowX + 1, nowY + 1},
			{nowX + 1, nowY - 1},
			{nowX + 1, nowY},
			{nowX - 1, nowY + 1},
			{nowX - 1, nowY - 1},
			{nowX - 1, nowY},
			{nowX, nowY + 1},
			{nowX, nowY - 1},
		};
		// �� ��ġ�� ���� �� ���� ������ �̵�����
		for (int i = 0; i < 8; ++i)
		{
			int canGoX = canGoPos[i].x;
			int canGoY = canGoPos[i].y;
			//�Է¹��� ��ġ�� nextPos �ȿ� �ְ�, �ش� ��ġ�� �츮�� ���� ���ٸ� �̵�����
			if ((toX == canGoX && toY == canGoY) &&
				(_playBoard[toY][toX]->GetTeam() != team))
				return true;
		}
		return false;
	}
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
