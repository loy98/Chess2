#include "Game.h"
#include <iostream>

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
		playerW->Move();
		_isWhiteTurn = false;
	}
	else
	{
		playerB->Move();
		_isWhiteTurn = true;
	}

	
}

bool Game::IsKingDead()
{
	return false;
}

