import Module from './Engines/KeplerApproximation/kepler.mjs'

Module().then((instance) => {
    const wasmArray = new Int32Array(instance.HEAP32.buffer, instance._KeplerEngine(2, 4), 2)
    const jsArray = Array.from(wasmArray)
    console.log(instance)
    console.log(wasmArray)
    console.log(jsArray)
})