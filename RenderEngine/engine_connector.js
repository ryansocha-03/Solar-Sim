import Module from '../Engines/KeplerApproximation/kepler.mjs'


export default function updateViaEngine(engineIndex, scene, requestedTime) {
    const NUMBEROFTESTPLANETS = 2;
    switch (engineIndex) {
        case 0:
            Module().then((instance) => {
                const wasmArray = new Float64Array(instance.HEAPF64.buffer, instance._KeplerEngine(NUMBEROFTESTPLANETS, requestedTime), NUMBEROFTESTPLANETS * 3)
                const jsArray = Array.from(wasmArray)
                scene.children[1].position.set(jsArray[0], jsArray[1], jsArray[2])
                scene.children[2].position.set(jsArray[3], jsArray[4], jsArray[5])
                //console.log(jsArray)
            })
            break;
        default:
            break;
    }
}