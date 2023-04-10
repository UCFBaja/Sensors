/*
Wire Color Code

Red = power
Black = ground
Green/Blue = Output

*/

//IRS
const int pinSIN = A0; // analog read in
const int pinCOS = A1;



void setup() {

  pinMode(pinSIN, INPUT);
  pinMode(pinCOS, INPUT);

  //ignore this pls... we might need it
  // interrupt initialization
  //attachInterrupt(digitalPinToInterrupt(pinHall), interruptName, RISING);

  Serial.begin(9600);
  // put your setup code here, to run once:

  
}

void loop() {
  // put your main code here, to run repeatedly:

  long vltSIN = analogRead(pinSIN);
   //unis mA
  long vltCOS = analogRead(pinCOS);

    //ignore this pls... we might need it
  float mVS = vltSIN * 5000.0 / 1023; // Voltage in mV 
  float mVC = vltCOS * 5000.0 / 1023; // Voltage in mV 
  
  //magnetic flux density
  //float mTS = mVS * 53.33 -133.3;
  //float mTC = mVS * 53.33 -133.3;
  
  //double totVolt = (vltSIN-vltCOS);

  float angle = atan2(vltSIN,vltCOS);
  //float angle = asin(vltCOS);

  //System.println(angle);
  //Serial.println(vltSIN);
  //Serial.print(",");
  //Serial.println(vltCOS);
  //Serial.println(",");
  Serial.println(angle);
  delay(100);

}

//ignore this pls... we might need it
/*
void interruptName(){
  count++;
  // Interrupt Service Route over
}
*/