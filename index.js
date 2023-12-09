// Import the MyModule from the Emscripten-generated file (example.js)
import  { Module } from './Engines/KeplerApproximation/main.js';

// Set up a callback for when the Emscripten module is initialized
Module.onRuntimeInitialized = () => {
    // Call the C function
    const result = Module._main();

    // Print the result to the console
    console.log("Result:", result);
};