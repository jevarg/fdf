#ifndef _MAP_HPP_
#define _MAP_HPP_

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


#endif // _MAP_HPP_