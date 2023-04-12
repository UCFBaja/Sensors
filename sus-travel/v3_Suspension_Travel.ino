/*
Wire Color Code

Red = power
Black = ground
Green/Blue = Output

*/


//these pins are reading in Magnetic Flux Density (MFD)
//sensor outputs voltage proportional to magnetic strength
//analog read in 

//IMPORTANT: Make sure pinCOS is the x- axis and pinSIN is the y- axis 
const int pinCOS = A0; 
const int pinSIN = A1;

//Bryce will give this value once he finds it....it's the distance from the mount pivot to the orthagonal intersection of the wheel center axis
const int arm_radius = 0;

void setup() {

  pinMode(pinSIN, INPUT);
  pinMode(pinCOS, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  //all trig function parameters are in radians -> convert if needed
  //recall By = @sin(θ) & Bx = @cos(θ) where B = output, @ = max MFD
  // MFD is in mA units  
  long vltSIN = analogRead(pinSIN);
  long vltCOS = analogRead(pinCOS);

  //Serial.println(vltSIN);
  //difference of max voltage - min voltage when going up, will hit 0 going down, and do min voltage - max voltage
  Serial.println(vltSIN-vltCOS);
  Serial.println(" ");
  Serial.println(",");
  //Serial.println(vltSIN);
  //Serial.println(",");
  delay(100);

}

// formula for angular displacement θ = linear displacement/ Radius of arm
// Devon has found a way to find linear displacement by just using voltage and has the sketch on him
// this function may be changed to accomodate his code as they were accurate, according to Bryce 

long angDisp(float x){
  return(x*arm_radius);
}
