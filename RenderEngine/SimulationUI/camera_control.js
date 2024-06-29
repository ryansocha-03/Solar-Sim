function cameraForwardBackward(deltaY, camera) {
    const ZOOMSCALE = 50;
    camera.translateZ(deltaY * ZOOMSCALE);
}

function mouseDownCamera(e, cameraControl) {
    cameraControl.clicking = true;
    cameraControl.lastMouseX = e.screenX;
    cameraControl.lastMouseY = e.screenY;
}

function mouseUpCamera(cameraControl) {
    cameraControl.clicking = false;
}

function rotateCamera(e, cameraControl, camera) {
    const CAMERAROTATESPEED = 1000;
    var movementX = e.screenX - cameraControl.lastMouseX;
    var movementY = e.screenY - cameraControl.lastMouseY;
    cameraControl.lastMouseX = e.screenX;
    cameraControl.lastMouseY = e.screenY;
    camera.rotateY(movementX / CAMERAROTATESPEED);
    camera.rotateX(movementY / CAMERAROTATESPEED);
}

export {cameraForwardBackward, mouseDownCamera, mouseUpCamera, rotateCamera}