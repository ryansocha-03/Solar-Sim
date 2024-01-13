const importObject = { imports: { imported_func: (arg) => console.log(arg) } };

WebAssembly.instantiateStreaming(fetch("./Engines/KeplerApproximation/main.wasm"), importObject).then(
    (obj) => {
        const wasmArray = new Int32Array(obj.instance.exports.memory.buffer, obj.instance.exports.KeplerEngine(3, -23423), 2);
        const jsArray = Array.from(wasmArray)
            // Print the result to the console
        console.log("WASM Array: ", wasmArray);
        console.log("JS Array: ", jsArray)

        jsArray[0] = 100;

        console.log("WASM Array: ", wasmArray);
        console.log("JS Array: ", jsArray);

    }
)