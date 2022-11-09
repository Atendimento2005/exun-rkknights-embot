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

// rest 0
//moving 1
//turning 2

class Commands {
  constructor(){
    this.elements = [];
  }
  
  add(comm, data){
    //commm 0 = stop, 1 = move, 2 = rotate
    this.elements.push([comm, data])
  }
  
  getLength(){
    return this.elements.length
  }
  
  fetch(){
    return this.elements.shift()
  }
}

const commands = new Commands();
setSpeed(255);
set(15, setInterval(loop, 100));

function turn(deg) {
  var newRotation = ((get(rotationPin)*1023/5) + deg)
  if (newRotation < 0){
    newRotation += 360
  }
  newRotation %= 360
  commands.add(2, newRotation)
}



function loop() {
  // if (state == 2){
  //   setSpeed(50)
  //   set(stopPin, 1)
  //   set(rightPin, 1)
  // }
  
  console.log(get(fsPin))
  
  if (commands.getLength() > 0) {
    var curCommand = commands.fetch()
    console.log(curCommand)
    if (curCommand[0] == 2){
      var newRotation = curCommand[1]
      setSpeed(200)
      set(stopPin, 1)
      set(rightPin, 1)
      
      var turning = setInterval(() => {
        var curRotation = Math.round(get(rotationPin)*1023/5)
        if (curRotation < newRotation+5 && curRotation > newRotation-5){
          clearInterval(turning)
          set(rightPin, 0)
          set(stopPin, 0)
          setSpeed(255)
          console.log("Turned")
        }else{
          console.log(get(rotationPin)*1023/5)
          console.log("Turning")
        }
      })
    }
    
  }
      
  
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
