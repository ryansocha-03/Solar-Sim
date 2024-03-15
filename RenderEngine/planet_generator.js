import * as THREE from 'three';

const SUNSIZE = 100;

function generateSolarPlanets(scene) {
    const planetData = [
      { name: 'Mercury', size: SUNSIZE * 0.003504, distance: 20 },
      { name: 'Venus', size: SUNSIZE * 0.008691, distance: 30 },
      { name: 'Earth', size: SUNSIZE * 0.009149, distance: 40 },
      { name: 'Mars', size: SUNSIZE * 0.004868, distance: 50 },
      { name: 'Jupiter', size: SUNSIZE * 0.100398, distance: 70 },
      { name: 'Saturn', size: SUNSIZE * 0.083626, distance: 100 },
      { name: 'Uranus', size: SUNSIZE * 0.036422, distance: 200 },
      { name: 'Neptune', size: SUNSIZE * 0.035359, distance: 300 }
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

function singlePlanetTest(scene) {
  const planetInfo = { name: 'Mercury', size: SUNSIZE * 0.003504, distance: 20 };
  const planetInfoTwo ={ name: 'Venus', size: SUNSIZE * 0.008691, distance: 30 }
  const geometry = new THREE.SphereGeometry(planetInfo.size, 10, 10);
  const material = new THREE.MeshBasicMaterial({
    color: 0xffffff,
    wireframe: true
  });
  const planet = new THREE.Mesh(geometry, material);
  planet.position.set(planetInfo.distance, 0, 0);
  planet.name = planetInfo.name;
  scene.add(planet);

  const geometrytwo = new THREE.SphereGeometry(planetInfo.size, 10, 10);
  const materialtwo = new THREE.MeshBasicMaterial({
    color: 0xffffff,
    wireframe: true
  });
  const planettwo = new THREE.Mesh(geometrytwo, materialtwo);
  planettwo.position.set(planetInfoTwo.distance, 0, 0);
  planettwo.name = planetInfoTwo.name;
  scene.add(planettwo);
}

function generateSun(scene) {
  const geometry = new THREE.SphereGeometry(SUNSIZE, 10, 10);
  const material = new THREE.MeshBasicMaterial({
    color: 0xFFFF00, // Sun color
    wireframe: true
  });
  const sun = new THREE.Mesh(geometry, material);
  sun.position.set(0, 0, 0);
  scene.add(sun);
}

export {generateSolarPlanets, singlePlanetTest, generateSun }