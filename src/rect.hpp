#pragma once

#include "window.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdlib.h>

class Rect {
public:
    Rect(int x, int y, const std::string &image_path);
    ~Rect();
    void draw();
    void moveRect(Vector2 pos);
    bool pollEvents(SDL_Event &event);
    Vector2 position;

private:
    Vector2 delta;
    Vector2 mouse_pos;

    int _w, _h;
    int _x, _y;
    int _r, _g, _b, _a;
    bool _clicked = false;
    SDL_Texture *_texture = nullptr;
};