#include "Fdf.hpp"
#include <unistd.h>

Fdf::Fdf()
{
}

Fdf::~Fdf()
{
}

void Fdf::start(const std::string &map)
{
    if (!m_map.loadMap(map))
    {
        return;
    }

    std::vector<std::vector<int>> mapContent = m_map.getMap();
    m_window.create("FDF");

    while (1)
    {
        m_input.update();
        if (m_input[SDLK_ESCAPE])
        {
            break;
        }

        if (m_input[SDLK_KP_PLUS]) {
            m_scale += SCALE_PITCH;
        }

        if (m_input[SDLK_KP_MINUS] && (m_scale - SCALE_PITCH) >= 0)
        {
            m_scale -= SCALE_PITCH;
        }

        m_window.flush();

        for (unsigned int x = 0; x < mapContent.size(); ++x)
        {
            for (unsigned int y = 0; y < mapContent[x].size(); ++y)
            {
                int baseX = (10 - y) * (m_scale / 2);
                int height = mapContent[x][y];
                int prevHeight = 0;

                int pointX = baseX + (x * m_scale);
                int pointY = (y * m_scale) - (height * 10);

                int prevX;
                int prevY;

                SDL_Color color{255, 255, 255, SDL_ALPHA_OPAQUE};
                if (height > 0)
                {
                    color.g = 0;
                    color.b = 0;
                }

                if (x > 0)
                {
                    prevHeight = mapContent[x - 1][y];
                    prevX = (pointX - m_scale);
                    prevY = (y * m_scale) - (prevHeight * 10);

                    m_window.drawLine(prevX, prevY, pointX, pointY);
                }

                if (y > 0)
                {
                    prevHeight = mapContent[x][y - 1];
                    prevX = ((10 - (y - 1)) * (m_scale / 2)) + (x * m_scale);
                    prevY = ((y - 1) * m_scale) - (prevHeight * 10);

                    m_window.drawLine(prevX, prevY, pointX, pointY);
                }
            }
        }

        m_window.update();

        usleep(10000);
    }
}

void Fdf::stop()
{
    SDL_Quit();
}