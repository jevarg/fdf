#include <iostream>
#include "Window.hpp"

Window::Window(int width, int height)
{
    m_width = width;
    m_height = height;
}

Window::~Window()
{
    if (m_renderer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }

    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
}

void Window::create(const char *title, const int &x, const int &y, Uint32 flags)
{
    std::cout << "Creating window: " << m_width << 'x' << m_height << std::endl;
    m_window = SDL_CreateWindow(title, x, y, m_width, m_height, flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::update()
{
    SDL_RenderPresent(m_renderer);
}

void Window::flush()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
}

void Window::drawLine(const int &x1, const int &y1, const int &x2, const int &y2, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
}

void Window::drawPixel(const int &x, const int &y, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(m_renderer, x, y);
}

const int &Window::getWidth()
{
    return m_width;
}

const int &Window::getHeight()
{
    return m_height;
}