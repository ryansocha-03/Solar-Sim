# Solar-Sim

## Requirements to Run
If you would like to run Solar Sim locally you will need the following:
* A local development server to serve your files (we used vite for development)
* emscripten if you would like to make changes to the physics engine, as it runs from WebAssembly

## To launch local server
In a terminal, navigate to the root directory of the project and use the following command

    npx vite

This will launch a dev server at http://localhost:<port>
The default port is 5173

Note that the file used to launch will be index.html

## How to compile Physics Engine
The physics engine is built in C and compiled to WebAssembly. When cloning this repository, the engine will be packaged and ready to run. If however, you wish you compile it yourself, the follow the instructions below.

1. Ensure you have emscripten installed on your computer. 

2. Once emscripten is installed, be sure to change the path of the variable CC in the makefile to the path for your install of emscripten.When necessary, recompile the physics engine using the following steps:
    1. Open a terminal in the directory for the engine you would like to compile
    2. (optional) execute make clean
    3. Execute make

Note: compiler optimizations seem to introduce some inexplicable behavior so avoid for now.

### TODO:
    Figure out how to explicity configure what file, port, etc vite uses to launch
