#include "fileManager.h"
#include <fstream>
#include <iostream>
fileManager::fileManager()
{
}

fileManager::~fileManager()
{
}
void fileManager::SaveGame(const std::string& filename, Game* game)
{
    std::ofstream ofs(filename);
    if (!ofs)
    {
        std::cerr << "파일을 열 수 없습니다." << filename << std::endl;
        return;
    }
       

    // 현재 턴 정보 저장 (1이면 흰색, 0이면 검은색)
    ofs << game->GetIsWhiteTurn() << "\n";

    // 8x8 체스판 상태 저장
    Board* board = game->GetBoard();
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            Piece* piece = board->GetPlayPiece(x, y);
            // PieceType과 Team을 int로 저장
            ofs << static_cast<int>(piece->GetType()) << " "
                << static_cast<int>(piece->GetTeam()) << " ";
        }
        ofs << "\n";
    }
    ofs.close();
}
void fileManager::LoadGame(const std::string& filename, Game* game)
{
    std::ifstream ifs(filename);
    if (!ifs)
    {
        std::cerr << "파일을 열 수 없습니다." << filename << std::endl;
        return;
    }

    bool isWhiteTurn;
    ifs >> isWhiteTurn;
    game->SetIsWhiteTurn(isWhiteTurn);

    // 8x8 체스판 상태 복원
    Board* board = game->GetBoard();
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            int type, team;
            ifs >> type >> team;
            Piece* piece = board->GetPlayPiece(x, y);
            piece->SetType(static_cast<PieceType>(type));
            piece->SetTeam(static_cast<Team>(team));
            //팀 타입에 따라 팀 렌더링
            if (piece->GetTeam() == Team::White) {
                piece->SetShape('W');
            }
            else if (piece->GetTeam() == Team::Black) {
                piece->SetShape('B');
            }
            else {
                piece->SetShape(' ');
            }
        }
    }
    
    ifs.close();
}


