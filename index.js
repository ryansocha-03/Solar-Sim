// Import the MyModule from the Emscripten-generated file (example.js)
//import {Module} from './Engines/KeplerApproximation/main.js';

// Set up a callback for when the Emscripten module is initialized
import init from './Engines/KeplerApproximation/main.wasm?init'

const arraySize = 2;

init().then((instance) => {
    console.log(instance.exports)
    const wasmArray = new Int32Array(instance.exports.memory.buffer, instance.exports.KeplerEngine(2, 4), arraySize);
    const jsArray = Array.from(wasmArray);

    // Print the result to the console
    console.log("WASM Array: ", wasmArray);
    console.log("JS Array: ", jsArray)

    jsArray[0] = 100;

    console.log("WASM Array: ", wasmArray);
    console.log("JS Array: ", jsArray);

})