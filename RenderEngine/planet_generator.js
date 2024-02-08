import * as THREE from 'three';

function generateSolarPlanets(scene) {
    const planetData = [
      { name: 'Mercury', size: 0.383, distance: 20 },
      { name: 'Venus', size: 0.949, distance: 30 },
      { name: 'Earth', size: 1, distance: 40 },
      { name: 'Mars', size: 0.532, distance: 50 },
      { name: 'Jupiter', size: 10.97, distance: 70 },
      { name: 'Saturn', size: 9.14, distance: 100 },
      { name: 'Uranus', size: 3.981, distance: 200 },
      { name: 'Neptune', size: 3.865, distance: 300 }
    ];

    for (let i = 0; i < planetData.length; i++) {
      const planetInfo = planetData[i];
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

function generateSun(scene) {
  const sunSize = 15;
  const geometry = new THREE.SphereGeometry(sunSize, 10, 10);
  const material = new THREE.MeshBasicMaterial({
    color: 0xFFFF00, // Sun color
    wireframe: true
  });
  const sun = new THREE.Mesh(geometry, material);
  sun.position.set(0, 0, 0);
  scene.add(sun);
}

export {generateSolarPlanets, generateSun }