import * as THREE from 'three';
import updateViaEngine from './engine_connector';
import { generateSolarPlanets, generateSun } from './planet_generator';
import { rotatePlanets } from './sample_orbiting';

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 0.1, 1000 );

const renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth, window.innerHeight );
document.body.appendChild( renderer.domElement );

generateSun(scene);
generateSolarPlanets(scene);

camera.position.z = 500;
camera.position.y = 300;
camera.rotateX((Math.PI / 180) * -35);

updateViaEngine(0);

function animate() {
    requestAnimationFrame( animate );
    rotatePlanets(scene);
    renderer.render( scene, camera );
}
animate()