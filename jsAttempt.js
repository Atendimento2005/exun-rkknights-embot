const stopPin = 0; //brake or move
const leftPin = 1; //move left
const rightPin = 2; //move right
const fsPin = 0; //forward sensor
const lsPin = 1; //left sensor
const rsPin = 2; //right sensor
const rotationPin = 3; //rotation
const arrowPin = 11; //arrow area
const blockPin = 12; //block area
const upPin = 13; //move up in block area

setSpeed(255);
set(15, setInterval(loop, 100));

function turn(deg) {
  newRotation = ((get(rotationPin)*1023/5) + deg)%360
  set(stopPin, 0)
  setSpeed(50)
  set(stopPin, 1)
  set(rightPin, 1)
  while (get(rotationPin)*1023/5 != newRotation){
    console.log("Turning")
  }
  set(rightPin, 0)
}

function loop() {
  
}

function set(pin, value) {
  document.getElementById(pin + "out").textContent = value;
}

function get(pin) {
  return document.getElementById(pin).textContent;
}

function setSpeed(speed){
  let i = 3;
  while (speed > 0) {
    set(i, speed % 2 == 1 ? 1 : 0);
    speed = Math.floor(speed / 2);
    i++;
  }
  for (;i < 11; i++) set(i, 0);
}