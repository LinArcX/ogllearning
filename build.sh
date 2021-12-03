#!/bin/sh

build_debug() {
    echo ">>> Creating build directory and copy assets files"
    mkdir -p build/linux/debug
    cp assets/image.bmp build/linux/debug

    echo ">>> Building app (Debug mode)"
    $CC \
    -g \
    -lGLEW \
    -lGLU \
    -lGL \
    -I/usr/local/include/SDL2/ \
    `sdl2-config --cflags --libs` \
    src/main.cpp \
    -o build/linux/debug/app
}

build_release() {
    echo ">>> Creating build directory and copy assets files"
    mkdir -p build/linux/release
    cp assets/image.bmp build/linux/release

    echo ">>> Building app (Release mode)"
    $CC \
    -lGLEW \
    -lGLU \
    -lGL \
    -I/usr/local/include/SDL2/ \
    `sdl2-config --cflags --libs` \
    src/main.cpp \
    -o build/linux/release/app
}

clean() {
    echo ">>> Cleaning build directory"
    rm -r build/linux/
}

run_debug() {
    echo ">>> Running app (Debug mode)"
    cd build/linux/debug
    ./app &
    cd ../../..
}

run_release() {
    echo ">>> Running app (Release mode)"
    cd build/linux/release
    ./app &
    cd ../../..
}
