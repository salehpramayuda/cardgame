#pragma once
#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void pollEvents(SDL_Event &event);
    void clear() const;
    inline bool isClosed() const { return _closed; }

private:
    bool init();

private:
    std::string _title;
    int _width = 800;
    int _height = 600;
    bool _closed = false;
    SDL_Window *_window = nullptr;

public:
    static SDL_Renderer *renderer;
};