# define stop_pin 0 //brake or move
# define left_pin 1 //move left
# define right_pin 2 //move right
# define fs_pin A0 //forward sensor
# define ls_pin A1 //left sensor
# define rs_pin A2 //right sensor
# define rotation_pin A3 //rotation
# define arrow_pin 11 //arrow area
# define block_pin 12 //block area
# define up_pin 13 //move up in block area

void setup() {
  Serial.begin(115200);
  pinMode(stop_pin, OUTPUT);
  pinMode(left_pin, OUTPUT);
  pinMode(right_pin, OUTPUT);
  pinMode(fs_pin, INPUT);
  pinMode(rs_pin, INPUT);
  pinMode(ls_pin, INPUT);
  pinMode(arrow_pin, INPUT);
  pinMode(block_pin, INPUT);
  pinMode(rotation_pin, INPUT);
  pinMode(up_pin, OUTPUT);
  for (int i = 3; i < 11; i++)
    pinMode(i, OUTPUT);
  set_speed(255);
  delay(1000);
}

void loop() {
  
}

void set_speed(byte speed){
  int i = 3;
  while (speed > 0) {
    digitalWrite(i, speed % 2 == 1 ? HIGH : LOW);
    speed = speed / 2;
    i++;
  }
  for (;i < 11; i++) digitalWrite(i, LOW);
}