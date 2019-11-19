#pragma once

#define DEFAULT_SCALE 40
#define SCALE_PITCH 1

#define DEFAULT_HEIGHT_SCALE 3
#define HEIGHT_SCALE_PITCH 1

#define OFFSET_PITCH 5

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
    int m_heightScale = DEFAULT_HEIGHT_SCALE;
    int m_offsetX = 0;
    int m_offsetY = 50;

public:
    Fdf();
    ~Fdf();

    void start(const std::string &map);
    void stop();
};

