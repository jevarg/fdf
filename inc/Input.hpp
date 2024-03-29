#pragma once

#include <list>
#include <SDL2/SDL_events.h>

class Input
{
private:
    SDL_Event m_event;
    std::list<SDL_Keycode> m_keyPressed;

public:
    Input();
    ~Input();

public:
    void update();
    bool operator[](const SDL_Keycode &key);
};

