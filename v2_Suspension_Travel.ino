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
const int pinSIN = A0; 
const int pinCOS = A1;

//Bryce will give this value once he finds it....it's the distance from the mount pivot to the orthagonal intersection of the wheel center axis
const int arm_radius = 0;

//ATAN2() outputs radians and all trig functions only take radians
const float R2D = 180.0/PI;
const float D2R = PI/180.0;

void setup() {

  pinMode(pinSIN, INPUT);
  pinMode(pinCOS, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  //all trig function parameters are in radians > convert if needed
  //recall By = @sin(θ) & Bx = @cos(θ) where B = output, @ = max MFD
  // MFD is in mA units  
  long vltSIN = analogRead(pinSIN);
  long vltCOS = analogRead(pinCOS);

  long R_vltSIN = numToRadians(vltSIN);
  long R_vltCOS = numToRadians(vltCOS);
  
  //should output 45 degrees until magnet is in range
  float angle = atan2(R_vltSIN,R_vltCOS) * R2D;

  //Serial.println(vltSIN);
  Serial.print(" ");
  //Serial.println(vltCOS);
  Serial.println(" ");
  Serial.println(angle);
  delay(100);

}


long numToRadians(long x){
  return(x*D2R);
}

/*
void numToRadians(long *x){
  
}

// formula for angular displacement θ = linear displacement/ Radius of arm
long angDisp(float x){
  return(x*arm_radius);
}

/*
Interrupter in case we need to slow down the program to avoid overwhelming the arduino

void interruptName(){
  count++;
  // Interrupt Service Route over
}
*/