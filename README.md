# Cangkul Card Game

How to compile:
- Install MinGW
- Set MinGW environment variable path
- Install SDL2, SDL2_image & SDL2_text
- Copy vscode settings
- Press F5 to debug. Currently compiled .exe files don't work with resources

MinGW Installation (Windows):
- Download mingw installation tool : https://osdn.net/projects/mingw/
- Run setup, set MinGW folder
- Open installation manager
  - Mark for installation: mingw32-gcc-g++-bin, msys-base-bin, mingw32-base-bin, mingw-developer-toolkit-bin
- Pick Installation Tab > Apply Changes

SDL2, SDL2_image & SDL2_text installation (mingw build):
- Download:
  - SDL2: https://www.libsdl.org/release/SDL2-devel-2.0.12-mingw.tar.gz
  - SDL2_image: https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz
  - SDL2_ttf: https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-mingw.tar.gz
- Get into the i686 folder, drag the include, bin, lib to your mingw folder
- Put all .dll files from i686/lib folder into our /build folder
