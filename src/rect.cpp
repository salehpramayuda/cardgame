#include "rect.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdlib.h>

Rect::Rect(int x, int y, int w, int h, const std::string &image_path)
    : _x(x), _y(y), _w(w), _h(h) {
    SDL_Surface *surface = IMG_Load(image_path.c_str());
    if (!surface) {
        std::cerr << "Failed to create surface.\n";
    }
    _texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    SDL_QueryTexture(_texture, NULL, NULL, &_w, &_h);
    if (!_texture) {
        std::cerr << "Failed to create texture.\n";
    }
    SDL_FreeSurface(surface);
}

Rect::~Rect() {
    SDL_DestroyTexture(_texture);
}

void Rect::draw() {
    SDL_Rect rect = {_x, _y, _w, _h};
    position = {_x + _w / 2, _y + _h / 2};
    if (_texture) {
        SDL_RenderCopy(Window::renderer, _texture, nullptr, &rect);
    } else {
        SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
        SDL_RenderFillRect(Window::renderer, &rect);
    };
    if (_clicked) {
        moveRect();
    };
}

void Rect::moveRect() {
    SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
    _x = mouse_pos.x - delta.x;
    _y = mouse_pos.y - delta.y;
}

bool Rect::pollEvents(SDL_Event &event) {
    switch (event.type) {
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
            bool in_x = (event.button.x >= _x && event.button.x <= _x + _w);
            bool in_y = (event.button.y >= _y && event.button.y <= _y + _h);
            if (in_x && in_y) {
                SDL_GetMouseState(&delta.x, &delta.y);
                delta.x -= _x;
                delta.y -= _y;
                _clicked = !_clicked;
            }
        }
    };
    return _clicked;
}