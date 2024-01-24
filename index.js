import Module from './Engines/KeplerApproximation/kepler.mjs'

Module().then((instance) => {
    const wasmArray = new Float64Array(instance.HEAPF64.buffer, instance._KeplerEngine(2, 4), 2)
    const jsArray = Array.from(wasmArray)
    console.log(jsArray)
})
