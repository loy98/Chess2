#pragma once
#include <fstream>
#include <string>
#include "Game.h" 

class fileManager {
public:
    fileManager();
    ~fileManager();

    void SaveGame(const std::string& filename, Game* game);
    void LoadGame(const std::string& filename, Game* game);
};
