#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(Board* board, Team team) : _board(board), _team(team)
{

}

void Player::Update()
{
	int i = 0;
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			Piece* piece = _board->GetPlayPiece(x, y);
			if (piece->GetTeam() == _team)
			{
				_pieces[i] = piece;
				i++;
			}
		}
	}
}

void Player::Move()
{
	
	char inputX, inputY;
	if (_team == Team::White)
		cout << "��� �����Դϴ�." << endl;
	if (_team == Team::Black)
		cout << "������ �����Դϴ�." << endl;
	cout << "������ ���� ��ǥ�� �Է����ּ��� : ";
	cin >> inputX >> inputY;
	cin.clear();
	cin.ignore();
	if (inputX < 'A' || inputX > 'H' || inputY < '1' || inputY > '8')
	{
		cout << "�ٽ� �Է��ϼ���" << endl;
		Move();
		return;
	}
		
	if (_board->GetPlayPiece((int)(inputX-65), (int)(inputY-49))->GetTeam() != _team)
	{
		cout << "�ٽ� �Է��ϼ���" << endl;
		Move();
		return;
	}
	
	char toX, toY;
	cout << "�̵���ų ��ġ�� �Է��ϼ���" << endl;
	cin >> toX >> toY;
	cin.clear();
	cin.ignore();
	if (_board->CanGo(_board->GetPlayPiece((int)(inputX - 65), (int)(inputY - 49)), (int)(toX - 65), (int)(toY - 49)))
	{
		_board->MovePiece((int)(inputX - 65), (int)(inputY - 49), (int)(toX - 65), (int)(toY - 49));
	}
	else {
		cout << "������";
		return;
	}

}
