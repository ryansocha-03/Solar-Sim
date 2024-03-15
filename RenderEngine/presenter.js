import * as THREE from 'three';
import updateViaEngine from './engine_connector';
import { generateSolarPlanets, singlePlanetTest, generateSun } from './planet_generator';
import { rotatePlanets } from './sample_orbiting';

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 0.1, 1000 );
const renderer = new THREE.WebGLRenderer();
const dateLabel = document.getElementById('current-date-time')

function setupScene() {
    renderer.setSize( window.innerWidth, window.innerHeight );
    document.body.appendChild( renderer.domElement );

    generateSun(scene);
    //generateSolarPlanets(scene);
    singlePlanetTest(scene);

    camera.position.z = 0;
    camera.position.y = 100;
    camera.rotateX((Math.PI / 180) * -90);
}

function animate() {
    requestAnimationFrame( animate );
    updateViaEngine(0, scene, Date.now() / 1000)
    dateLabel.innerText = new Date().toUTCString()
    renderer.render( scene, camera );
}

setupScene()
animate()