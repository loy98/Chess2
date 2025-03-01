#include "Game.h"
#include <iostream>
using namespace std;

void Game::Init()
{
	_board->Init();
	playerW = new Player(_board, Team::White);
	playerB = new Player(_board, Team::Black);
}

void Game::Update()
{
	_board->Update();
	playerW->Update();
	playerB->Update();
}

void Game::Render()
{
	system("cls");
	_board->Render();
	
}

void Game::Move()
{
	if (_isWhiteTurn)
	{
		playerW->ChoicePiece();
		CheckCanGo();
		_isWhiteTurn = false;
	}
	else
	{
		playerB->ChoicePiece();
		CheckCanGo();
		_isWhiteTurn = true;
	}


}

void Game::CheckCanGo()
{
	char fromX, fromY;
	if (_isWhiteTurn)
	{
		fromX = playerW->GetFromX();
		fromY = playerW->GetFromY();
	}							 
	else						 
	{							 
		fromX = playerB->GetFromX();
		fromY = playerB->GetFromY();
	}
	
	char toX, toY;
	cout << "이동시킬 위치를 입력하세요 : ";
	cin >> toX >> toY;
	cin.clear();
	cin.ignore();
	int intToX = (int)(toX - 65);
	int intToY = (int)(toY - 49);
	if (_board->CanGo(_board->GetPlayPiece((int)(fromX - 65), (int)(fromY - 49)), intToX, intToY))
	{
		_board->MovePiece((int)(fromX - 65), (int)(fromY - 49), intToX, intToY);
		return;
	}
	else {
		cout << "다시 입력하세요";
		Move();
		return;
	}
}

bool Game::IsKingDead(Player* player)
{
	for (int i = 0; i < 16; ++i)
	{
		Piece** pieces = player->GetPieces();
		if (pieces[i]->GetType() == PieceType::King)
			return false;
	}
	return true;
}

