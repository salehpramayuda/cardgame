#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void pollEvents(SDL_Event &event);
    void render() const;
    inline bool is_open() const { return _open; }

private:
    bool init();

private:
    std::string _title;
    int _width = 800;
    int _height = 600;
    bool _open = false;
    SDL_Window *_window = nullptr;

public:
    static SDL_Renderer *renderer;
};