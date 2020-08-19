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
const int sensorPin       = A0;                   // seleccionar la entrada para el sensor
int sensorValue           = 0;                    // variable que almacena el valor raw (0 a 1023)
double voltage            = 0.0;                  // variable que almacena el voltaje (0.0 a 25.0)
int offset                = 0;                   // set the correction offset value

void setup() {
   Serial.begin(9600);
}
 
void loop() {
  sensorValue = analogRead(sensorPin);                      // read the input
  //value = fmap(sensorValue, 0, 1023, 0.0, 25.0);            // cambiar escala a 0.0 - 25.0
  voltage = map(sensorValue, 0, 1023, 0, 2500) + offset;    // map 0-1023 to 0-2500 and add correction offset
  voltage /=100;// divide by 100 to get the decimal values
  Serial.println(voltage);                                  // mostrar el valor por serial
  delay(500);
}
 
// cambio de escala entre floats - prueba
//float fmap(float x, float in_min, float in_max, float out_min, float out_max)
//{
//   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}
