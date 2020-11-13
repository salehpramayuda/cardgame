#include "window.hpp"

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, Vector2 resolution) : _title(title), _height(resolution.y), _width(resolution.x) {
    _open = init();
};

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
};

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL.\n";
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        std::cerr << "Failed to initialize SDL_image.\n";
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf.\n";
        return false;
    }

    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width, _height,
        0);

    if (_window == nullptr) {
        std::cerr << "Failed to create window.\n";
        return 0;
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        return 0;
    }

    return true;
}

void Window::pollEvents(SDL_Event &event) {
    switch (event.type) {
    case SDL_QUIT:
        _open = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
            _open = false;
            break;
        }
    default:
        break;
    }
}

void Window::render() const {
    SDL_RenderPresent(renderer); // put everything to screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer); // get color on the renderer
}