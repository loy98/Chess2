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

void Player::ChoicePiece()
{
	if (_team == Team::White)
		cout << "��� �����Դϴ�." << endl;
	if (_team == Team::Black)
		cout << "������ �����Դϴ�." << endl;
	cout << "������ ���� ��ǥ�� �Է����ּ��� : ";
	cin >> fromX >> fromY;
	cin.clear();
	cin.ignore();

	if (fromX < 'A' || fromX > 'H' || fromY < '1' || fromY > '8')
	{
		cout << "�ٽ� �Է��ϼ���" << endl;
		ChoicePiece();
		return;
	}
		
	if (_board->GetPlayPiece((int)(fromX-65), (int)(fromY-49))->GetTeam() != _team)
	{
		cout << "�ٽ� �Է��ϼ���" << endl;
		ChoicePiece();
		return;
	}
}

