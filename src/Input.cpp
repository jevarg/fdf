#include "Input.hpp"
#include <algorithm>

Input::Input()
{
}

Input::~Input()
{
}

void Input::update()
{
    m_keyPressed.clear();

    if (SDL_PollEvent(&m_event)) {
        m_keyPressed.push_back(m_event.key.keysym.sym);
    }
}

bool Input::operator[](const SDL_Keycode &key)
{
    if (m_keyPressed.empty())
    {
        return false;
    }

    std::list<SDL_Keycode>::iterator it = std::find(m_keyPressed.begin(), m_keyPressed.end(), key);

    return (it != m_keyPressed.end());
}