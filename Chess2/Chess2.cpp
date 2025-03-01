#include <iostream>
#include "Board.h"
#include "Game.h"
using namespace std;

int main()
{
    Board board;
    Game* game = new Game(&board);
    Player* white;
    Player* black;
    game->Init();
    while (1)
    {
        game->Update();
        game->Render();
        game->Move();
        white = game->GetPlayerW();
        black = game->GetPlayerB();
        if (game->IsKingDead(white)) {
            game->Update();
            game->Render();
            cout << "검은팀 승리!" << endl;
            break;
        }
        if (game->IsKingDead(black)) {
            game->Update();
            game->Render();
            cout << "흰색팀 승리!" << endl;
            break;
        }
        
    }
  
    
}

