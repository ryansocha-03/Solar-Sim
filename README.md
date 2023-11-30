# Solar-Sim

## How to compile WebAssembly
In a terminal, navigate to the emscripten root directory emsdk > upstream > emscripten
The general form command for compiling is

    ./emcc <file-name> -o <destination-file-name>

Be sure to include extensions and file paths for both source and destination files

## To launch local server
In a terminal, navigate to the root directory of the project and use the following command

    npm vite

This will launch a dev server at http://localhost:<port>
The default port is 5173

Note that the file used to launch will be index.html

### TODO:
    Figure out how to explicity configure what file, port, etc vite uses to launch
    Create makefiles or other automation to manually compile webassembly so we don't have to type out that long ass command every time

