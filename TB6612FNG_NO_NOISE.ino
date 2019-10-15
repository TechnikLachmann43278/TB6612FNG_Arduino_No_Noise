//Motor 1
int pinAIN1 = 7; //Direction
int pinAIN2 = 8; //Direction
int pinPWMA = 9; //Speed

//Motor 2
int pinBIN1 = 5; //Direction
int pinBIN2 = 4; //Direction
int pinPWMB = 3; //Speed

int pinSTBY = 6;  //Standby

int analogPin = A2;
int val;
byte in, daten[5];
int i=0, error=0, schleife=0, links, rechts;

void setup() {

  setPwmFrequency(9, 1);
  setPwmFrequency(3, 1);
  

  pinMode(pinPWMA, OUTPUT);
  pinMode(pinAIN1, OUTPUT);
  pinMode(pinAIN2, OUTPUT);

  pinMode(pinPWMB, OUTPUT);
  pinMode(pinBIN1, OUTPUT);
  pinMode(pinBIN2, OUTPUT);
  
  pinMode(pinSTBY, OUTPUT);
  digitalWrite(pinSTBY, HIGH);
  Serial.begin(115200);

}

void loop() {
  
  val = analogRead(analogPin);  // read the input pin 
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);
  
  motor1R();           //sets the diraction of the motor 1, for the other direction use motor1L() instead
  analogWrite(pinPWMA,val);
  motor2L();           //sets the diraction of the motor 2, for the other direction use motor2L() instead
  analogWrite(pinPWMB,val);
  


}


void motor1R(){
  digitalWrite(pinAIN1,LOW);
  digitalWrite(pinAIN2,HIGH);
}
void motor1L(){
  digitalWrite(pinAIN2,LOW);
  digitalWrite(pinAIN1,HIGH);
}

void motor2R(){
  digitalWrite(pinBIN1,LOW);
  digitalWrite(pinBIN2,HIGH);
}
void motor2L(){
  digitalWrite(pinBIN2,LOW);
  digitalWrite(pinBIN1,HIGH);
}


// this function changes the pwm-frequency
// you won't hear any more annoying noises
void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
     
