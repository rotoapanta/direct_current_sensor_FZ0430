/******************************************************************************************************
  voltage_sensor_FZ0430.ino
  Measure voltages up to 25V with the FZ0430 sensor.
  Version: 1.0
  Fecha: 17/08/2020
  Autor: Roberto Toapanta, @rotoapanta
  © 2017-2020 ToGuBrain Solutions
*******************************************************************************************************
/*
El Sketch usa 3502 bytes (10%) del espacio de almacenamiento de programa. El máximo es 32256 bytes.
Las variables Globales usan 200 bytes (9%) de la memoria dinámica, dejando 1848 bytes para las variables locales. El máximo es 2048 bytes.

Wiring diagram

Arduino Pin                       FZ0430 Sensor
5V  -----------------------------   (+)
GND -----------------------------   (-)
AN0 -----------------------------   S
*/

/* define variables */
const int sensorPin       = A0;                   // select the analog input for the sensor 
int sensorValue           = 0;                    // variable that stores the raw value (0 to 1023)
double voltage            = 0.0;                  // variable that stores voltage (0.0 to 25.0)
int offset                = 0;                    // set the correction offset value

void setup() {
   Serial.begin(9600);
}
 
void loop() {
  sensorValue = analogRead(sensorPin);                      // read the input
  voltage = map(sensorValue, 0, 1023, 0, 2500) + offset;    // map 0-1023 to 0-2500 and add correction offset
  voltage /=100;                                            // divide by 100 to get the decimal values
  Serial.println(voltage);                                  // show value by serial
  delay(500);
}
