#include <fstream>
#include <iostream>
#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

const bool Map::loadMap(const std::string &path)
{
    m_filePath = path;
    std::ifstream inFile(m_filePath);
    std::string line;
    std::string height("");

    while (std::getline(inFile, line))
    {
        std::vector<int> row;

        for (unsigned int i = 0; i < line.size(); ++i)
        {
            if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
            {
                std::cerr << "Map parsing error" << std::endl;
                m_map.clear();

                return false;
            }

            if (line[i] != ' ')
            {
                height += line[i];
            }
            else
            {
                row.push_back(std::stoi(height));
                height = "";
            }
        }

        m_map.push_back(row);
        height = "";
    }

    return true;
}

const std::vector<std::vector<int>> &Map::getMap()
{
    return m_map;
}