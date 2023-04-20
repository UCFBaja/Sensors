/*
Wire Color Code
Red = power
Black = ground
Green/Blue = Output
*/

//these pins are reading in Magnetic Flux Density
//sensor outputs voltage proportional to magnetic strength
//analog read in
const int pinSIN = A0; 
const int pinCOS = A1;
const double MAX_TRAVEL = 6.95;

void setup() 
{
  pinMode(pinSIN, INPUT);
  pinMode(pinCOS, INPUT);
  Serial.begin(9600);  
}

void loop() 
{
  //Read analog vlt from pins, I believe it's measuring in guass
  double vltSIN = analogRead(pinSIN);
  double vltCOS = analogRead(pinCOS);
  //Convert a known high and low to a linear equation since travel is linear, divide by 100 to get a percentage of travel occured.
  double pSIN = ((vltSIN - 523) * 2)/100;
  double pCOS = ((vltCOS - 631) * -0.68966)/100;
  //Convert percentage covered to the known max travel length, 100% travel is not on suspension,0% suspension is fully collapsed,  e.g 50% of travel of 7 inches is .5 times 7 = 3.5 inches travel,
  //Replacing 6.95 with a variable makes this not work, don't ask me
  double sTravel = (pSIN * 6.95);
  double cTravel = (pCOS * 6.95);
  //Average the two inputs for a more accurate reading
  double fTravel = (sTravel + cTravel)/2;
  
  
  //Serial.print();
  
  /*
  //
  //Print Block to confirm read
  //
  Serial.print("vltSIN: ");
  Serial.print(vltSIN);
  Serial.print(", vltCOS: ");
  Serial.print(vltCOS);
  Serial.print(", pSIN: ");
  Serial.print(pSIN);
  Serial.print(", pCOS: ");
  Serial.print(pCOS);
  Serial.print(", sTravel: ");
  Serial.print(sTravel);
  Serial.print(", cTravel: ");
  Serial.print(cTravel);
  Serial.print(", Distance Traveled(in):");
  Serial.println(fTravel);
  */
  delay(100);

}
