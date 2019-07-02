#ifndef _FDF_HPP_
#define _FDF_HPP_

#define DEFAULT_SCALE 40
#define SCALE_PITCH 5

#include <string>
#include "Window.hpp"
#include "Map.hpp"
#include "Input.hpp"

class Fdf
{
private:
    Window m_window;
    Map m_map;
    Input m_input;

    int m_scale = DEFAULT_SCALE;

public:
    Fdf();
    ~Fdf();

    void start(const std::string &map);
    void stop();
};

#endif // _FDF_HPP_