import * as THREE from 'three';
import { PLANETDATA } from '../CelestialData/planet_data';
import { SUNDATA } from '../CelestialData/sun_data';

/**
 * Generates solar planets and adds them to the provided scene.
 *
 * @param {THREE.Scene} scene - The scene to add the solar planets to.
 * @return {void} This function does not return anything.
 */
function generateSolarPlanets(scene) {
  generateHelperRings(scene);
  for (let i = 0; i < PLANETDATA.length; i++) {
    const planetInfo = PLANETDATA[i];
    const geometry = new THREE.SphereGeometry(planetInfo.size, 10, 10);
    const material = new THREE.MeshBasicMaterial({
      color: 0xffffff,
      wireframe: true
    });
    const planet = new THREE.Mesh(geometry, material);
    planet.position.set(planetInfo.distance, 0, 0);
    planet.name = planetInfo.name;
    scene.add(planet);
  }
}

/**
 * Generates helper rings for planets to allow for better visibility and adds them to the provided scene.
 *
 * @param {THREE.Scene} scene - The scene to add the helper rings to.
 * @return {void} This function does not return anything.
 */
function generateHelperRings(scene) {
  for (let i = 0; i < PLANETDATA.length; i++) {
    const planetInfo = PLANETDATA[i];
    const geometry = new THREE.SphereGeometry(planetInfo.size * 2, 10, 10);
    const material = new THREE.MeshBasicMaterial({
      color: 0x00ff00,
      wireframe: true
    });
    const planetHelper = new THREE.Mesh(geometry, material);
    planetHelper.position.set(planetInfo.distance, 0, 0);
    planetHelper.name = planetInfo.name + "helper";
    scene.add(planetHelper);
  }
  // const sunHelperGeometry = new THREE.SphereGeometry(sunData[0].size * 100, 10, 10);
  // const sunHelperMaterial = new THREE.MeshBasicMaterial({
  //   color: 0xffff00,
  //   wireframe: true
  // });
  // const sunHelper = new THREE.Mesh(sunHelperGeometry, sunHelperMaterial);
  // sunHelper.position.set(0, 0, 0);
  // scene.add(sunHelper);
}

/**
 * Generates a sun object and adds it to the provided scene.
 *
 * @param {THREE.Scene} scene - The scene to add the sun object to.
 * @return {void} This function does not return anything.
 */
function generateSun(scene) {
  const geometry = new THREE.SphereGeometry(SUNDATA[0].size, 10, 10);
  const material = new THREE.MeshBasicMaterial({
    color: 0xFFFF00, // Sun color
    wireframe: true
  });
  const sun = new THREE.Mesh(geometry, material);
  sun.position.set(0, 0, 0);
  scene.add(sun);
}

export {generateSolarPlanets, generateSun }