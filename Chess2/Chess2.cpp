#include <iostream>
#include "Board.h"
#include "Game.h"
#include "fileManager.h"
using namespace std;

int main()
{
    Board board;
    Game* game = new Game(&board);
    Player* white;
    Player* black;
    fileManager file;
    game->Init();
    int choice;
    cout << "저장된 데이터를 불러오시겠습니까?" << endl;
    cout << "[1] 예 [2] 아니오" << endl;
    cin >> choice;
    if (choice == 1)
    {
        file.LoadGame("save_data.txt", game);
    }
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
        file.SaveGame("save_data.txt", game);
    }
    
    
}

