#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    
MMA8452Q accel;                   // create instance of the MMA8452 class

void setup() {
  Serial.begin(115200);
  Serial.println("Sensor 1");
  Wire.begin();

  if (accel.begin() == false) {
    accel.setScale(SCALE_8G); // can either be SCALE_2G, SCALE_4G or SCALE_8G
    Serial.println("Not Connected");
    while (1);
  }
}

void loop() {
  if (accel.available()) {      // Wait for new data from accelerometer
    // Acceleration of x, y, and z directions in g units
    Serial.print(accel.getCalculatedX(), 3);
    Serial.print("\t");
    Serial.print(accel.getCalculatedY(), 3);
    Serial.print("\t");
    Serial.print(accel.getCalculatedZ(), 3);
    Serial.println();
    delay(4);
  }
}
