#pragma once

#include "window.hpp"

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

class Rect {
public:
    Rect(int x, int y, int w, int h,
         const std::string &image_path);
    ~Rect();
    void draw();
    bool pollEvents(SDL_Event &event);
    Vector2 position;

private:
    void moveRect();

private:
    Vector2 delta;
    Vector2 mouse_pos;

    int _w, _h;
    int _x, _y;
    int _r, _g, _b, _a;
    bool _clicked = false;
    SDL_Texture *_texture = nullptr;
};