import * as THREE from 'three';

export function rotatePlanets(scene) {
  scene.traverse(function (object) {
    if (object instanceof THREE.Mesh && object !== scene.children[0]) { // Assuming the sun is the first child
      const planetSpeeds = {
        'Mercury': 1,
        'Venus': 1.5,
        'Earth': 1,
        'Mars': 1.2,
        'Jupiter': 2,
        'Saturn': 2.5,
        'Uranus': 1,
        'Neptune': 1.5
      };
      const angle = planetSpeeds[object.name] * (Math.PI / 180) || 0.01 * (Math.PI / 180);
      //object.rotation.y += speed;
      object.position.sub(scene.children[0].position);
      object.position.applyAxisAngle(new THREE.Vector3(0, 1, 0), angle);
      object.position.add(scene.children[0].position);
    }
  });
}
