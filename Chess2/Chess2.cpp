#include <iostream>
#include "Board.h"
#include "Game.h"


int main()
{
    Board board;
    Game* game = new Game(&board);
    game->Init();
    while (1)
    {
        game->Update();
        game->Render();
        game->Move();
    }
  
    
}

