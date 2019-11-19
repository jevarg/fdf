#pragma once

#include <string>
#include <vector>

class Map
{
private:
    std::string m_filePath;
    std::vector<std::vector<int>> m_map;

public:
    Map();
    ~Map();

    const bool loadMap(const std::string &path);
    const std::vector<std::vector<int>> &getMap();
};

