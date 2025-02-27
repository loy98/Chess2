#include "Game.h"

void Game::Init()
{
	for (int i = 0; i < 2; ++i)
	{
		_players[i] = new Player();
	}
}

void Game::Update()
{
}

void Game::Render()
{
	_board->Render();
}

bool Game::IsKingDead()
{
	return false;
}

