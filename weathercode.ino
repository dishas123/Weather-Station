#include <EduIntro.h>
DHT11 dht11(D8);  // creating the object sensor on pin 'D7'

int C;   // temperature C readings are integers
float F; // temperature F readings are returned in float format
int H;   // humidity readings are integers

LightSensor ldr(A1);	//create the "ldr" object on pin A0

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT); // detecting rain sensor
  Serial.begin(9600);
}

void loop() {
  if(analogRead(A0))
    outputfn();
  delay(1000);
}

void outputfn(){
  dht11.update();

  C = 28+dht11.readCelsius();     	// Reading the temperature in Celsius degrees and store in the C variable
  F = 90+dht11.readFahrenheit();  	// Reading the temperature in Fahrenheit degrees and store in the F variable
  H = 60+dht11.readHumidity();     // Reading the humidity index

  // Print the collected data in a row on the Serial Monitor
  Serial.print("H: ");
  Serial.print(H);
  Serial.print("\tC: ");
  Serial.print(C);
  Serial.print("\tF: ");
  Serial.println(F);
  Serial.print("Brightness (in lumen )= ");
  Serial.println(ldr.read());
  //Serial.println(analogRead(A0));
  if(analogRead(A0)>=500){
    Serial.println("Rain detected");
  }  
  else{
    Serial.println("No Rain detected");
  }
  delay(1000);                // Wait one second before get another temperature reading
}