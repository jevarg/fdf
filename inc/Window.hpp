#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <SDL2/SDL.h>

class Window
{
private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    int m_width = 800;
    int m_height = 600;

public:
    Window(int width = 800, int height = 600);
    ~Window();

public:
    void create(
        const char *title,
        const int &x = SDL_WINDOWPOS_CENTERED,
        const int &y = SDL_WINDOWPOS_CENTERED,
        Uint32 flags = SDL_WINDOW_SHOWN
    );
    void update();
    void flush();

    void drawLine(const int &x1, const int &y1, const int &x2, const int &y2, const SDL_Color &color = {255, 255, 255, SDL_ALPHA_OPAQUE});
    void drawPixel(const int &x, const int &y, const SDL_Color &color = {255, 255, 255, SDL_ALPHA_OPAQUE});

    const int &getWidth();
    const int &getHeight();
};

#endif // _WINDOW_HPP_
