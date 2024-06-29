import * as THREE from 'three';
import { cameraForwardBackward, mouseDownCamera, mouseUpCamera, rotateCamera } from './SimulationUI/camera_control';
import { generateSolarPlanets, generateSun } from './planet_generator';

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 10, 1000000 );
const renderer = new THREE.WebGLRenderer();
const dateLabel = document.getElementById('current-date-time')
const body = document.getElementById('page-body')
var cameraControl = {
    clicking: false,
    lastMouseX: 0,
    lastMouseY: 0
}

function setupScene() {
    renderer.setSize( window.innerWidth, window.innerHeight );
    document.body.appendChild( renderer.domElement );

    generateSun(scene);
    generateSolarPlanets(scene);

    camera.position.x = 778000;
    camera.position.z = 0;
    camera.position.y = 10000;
    camera.rotateX((Math.PI / 180) * -90);
    camera.rotateY((Math.PI / 180) * 0);

    body.addEventListener("wheel", function(e) { cameraForwardBackward(e.deltaY, camera) }, false);
    body.addEventListener("mousedown", function(e) { mouseDownCamera(e, cameraControl) }, false);
    body.addEventListener("mouseup", function(e) { mouseUpCamera(cameraControl) }, false);
    body.addEventListener("mousemove", function(e) { if (cameraControl.clicking) rotateCamera(e, cameraControl, camera) }, false);
}

function animate() {
    requestAnimationFrame( animate );
    //updateViaEngine(0, scene, Date.now() / 1000)
    dateLabel.innerText = new Date().toUTCString()
    renderer.render( scene, camera );
}

setupScene()
animate()