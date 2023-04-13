
#include "Wire.h" //allows communication over i2c devices

const float pressureInput = A5; //select the analog input pin for the pressure transducer
const float pressureZero = 105.5; //analog reading of pressure transducer at 0psi
const float pressureMax = 920.60; //analog reading of pressure transducer at 100psi
const float pressureTransducermaxPSI = 30.00; //psi value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 150; //constant integer to set the sensor read delay in milliseconds

float pressureValue = 0; //variable to store the value coming from the pressure transducer
float pressure = 0;
float percentageOfFuel = 0;

int pressureAverageIterator = 0;
float pressureAveraged = 0;
float pressureAverageTotal = 0;
float pressureRecentValue[50];

void setup() //setup routine, runs once when system turned on or reset
{
  Serial.begin(baudRate); //initializes serial communication at set baud rate bits per second
}

void loop() //loop routine runs over and over again forever
{
  pressureValue = analogRead(pressureInput);
  pressure = pressureTransducermaxPSI * (pressureValue - pressureZero) / (pressureMax - pressureZero);
  //Serial.print("PSI:");
  //Serial.println(pressure);
  
  if(pressureAverageIterator == 50)
    {
      pressureAverageIterator = 0;
    }
  if(pressureAverageIterator<51)
    {
      pressureAverageTotal = pressureAverageTotal - pressureRecentValue[pressureAverageIterator];
      pressureRecentValue[pressureAverageIterator] = pressure;
      pressureAverageTotal = pressureAverageTotal + pressureRecentValue[pressureAverageIterator];
      //Serial.println(pressureAverageTotal);
      pressureAveraged = pressureAverageTotal/50;
      //Serial.print("Average:");
      //Serial.println(pressureAveraged);
      pressureAverageIterator++;

      percentageOfFuel = 250 * pressureAveraged + 5;
      //Serial.print("Fuel percent:");
      //Serial.println(percentageOfFuel);
      Serial.print("FU ");
      Serial.print(percentageOfFuel,1);
      Serial.println("|");
    }
  delay(sensorreadDelay);
}