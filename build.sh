#!/bin/sh

build() {
    echo ">>> Building app"
    gcc -I./libs/linux/SDL/include -o build/app src/main.cpp `sdl2-config --cflags --libs`
}

clean() {
    echo ">>> Removing app"
    rm ./build/app
}

run() {
    echo ">>> Running app"
    cd build
    ./app &
    cd ..
}
