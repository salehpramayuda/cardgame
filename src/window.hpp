#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

struct Vector2 {
    int x, y;

    // operator overloading
    Vector2 operator+(const Vector2 &other) const {
        return {x + other.x, y + other.y};
    }
    Vector2 operator*(const Vector2 &other) const {
        return {x * other.x, y * other.y};
    }
    Vector2 operator-(const Vector2 &other) const {
        return {x - other.x, y - other.y};
    }
    Vector2 operator/(const Vector2 &other) const {
        return {x / other.x, y / other.y};
    }
    Vector2 operator/(const int &dividant) {
        this->x = x / dividant;
        this->y = y / dividant;
        return *this;
    }
    Vector2 &operator+=(const int &increment) {
        this->x += increment;
        this->y += increment;
        return *this;
    }
    Vector2 &operator+=(const Vector2 &increment) {
        this->x += increment.x;
        this->y += increment.y;
        return *this;
    }
    Vector2 &operator-=(const int &increment) {
        this->x -= increment;
        this->y -= increment;
        return *this;
    }
};

class Window {
public:
    Window(const std::string &title, Vector2 resolution);
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