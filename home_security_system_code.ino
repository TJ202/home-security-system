#include <Adafruit_LiquidCrystal.h> // Importing the library for LCD
#include <Servo.h> // Importing the library for Servo Motor

// Declaring
Adafruit_LiquidCrystal lcd_1(0);
Servo servo; 

// Pin numbers 
int led = 13;	 // LED 
int buzzer = 6;  // Piezo buzzer
int trigger = 9; // Ultrasonic distance sensor
int echo = 8;    // Ultrasonic distance sensor
int motor = 4; 	 // Servo motor
int pir = A3;	 // PIR sensor
int gas = A0;	 // Gas sensor
int temp = A1;	 // Temperature sensor
  
// Utility functions used
void alert();
void rest();
void alert_led();
void rest_led();

// Initialising
void setup()
{  
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0,0);
  lcd_1.print("Welcome to Home");
  lcd_1.setCursor(0,1);
  lcd_1.print("Security System");
  lcd_1.setBacklight(1);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pir, INPUT);
  pinMode(gas, INPUT);
  pinMode(temp, INPUT);
  servo.attach(motor);
  servo.write(0);
  Serial.begin(9600);
  delay(1000);
  lcd_1.clear();
}

// Driver code
void loop()
{
  // Gas sensor 
  int gasSensorValue = analogRead(A0); 
  
  // Temperature sensor
  float tempSensorValue = analogRead(temp);
  tempSensorValue = (tempSensorValue/1023)*5000;
  float temperature = (tempSensorValue-500)/10; // Converting voltage from sensor to temperature in degree Celcius
  
  // Ultrasonic distance sensor
  digitalWrite(trigger, HIGH);
  delay(200);
  digitalWrite(trigger, LOW);
  float time = pulseIn(echo, HIGH);
  float distance = (time*(float)0.034)/2;
  
  // PIR sensor
  float pirSensorValue = analogRead(pir);
  Serial.println(pirSensorValue);
  
  // Gas Sensor Configuration
  if(gasSensorValue >= 150 && temperature <75)
  {
    alert();
    lcd_1.setCursor(0,0);
    lcd_1.print("Smoke Detected!!");
    lcd_1.setCursor(0,1);
    lcd_1.print(gasSensorValue);
    lcd_1.setCursor(3,1);
    lcd_1.print("ppm");
  }
  else
  {
    rest();
  }
  
  // Temperature Sensor Configuration
  // High temperature
  if(temperature >= 75 && gasSensorValue < 150)
  {
    alert();
    lcd_1.setCursor(0,0);
    lcd_1.print("Fire Alert!!");
    lcd_1.setCursor(0,1);
    lcd_1.print(temperature);
    lcd_1.print("degC");
    delay(100);
  }
  else
  {
    rest();
  }
  
  // Fire detected
  if(temperature >= 90 && gasSensorValue >= 150) // Both fire and smoke detected
  {
    alert_led();
    lcd_1.setCursor(0,0);
    lcd_1.print("Fire Alert!!");
    lcd_1.setCursor(0,1);
    lcd_1.print("Starting sprayer");
    delay(2000);
    int pos;
    for(pos=0; pos<=180; pos++)
    {
      servo.write(pos); 
    }
    pos=0;
    lcd_1.clear();
    lcd_1.setCursor(0,0);
    lcd_1.print("Started!");
    delay(5000);
    lcd_1.clear();
  }
  else
  {
    rest_led();
  }
  
  // Ultrasonic Distance Sensor Configuration
  if(distance >= 60)
  {
    alert_led();
    lcd_1.setCursor(0,0);
    lcd_1.print("Thief");
    lcd_1.setCursor(0,1);
    lcd_1.print("Detected!!");
    delay(70);
  }
  else
  {
    rest_led();
  }
  
  // PIR Sensor Configuration
  if(pirSensorValue > 0)
  {
    alert_led();
    lcd_1.setCursor(0,0);
    lcd_1.print("Motion");
    lcd_1.setCursor(0,1);
    lcd_1.print("Detected!!");
    delay(10);
  }
  else
  {
    rest_led();
  }
}

// Function to ring the buzzer and blink led
void alert_led()
{
   digitalWrite(buzzer, HIGH);
   digitalWrite(led, HIGH);
   delay(200);
   digitalWrite(led, LOW);
}

void rest_led()
{
  digitalWrite(buzzer,LOW);
  digitalWrite(led, LOW);
  lcd_1.clear();
}

// Function to ring the buzzer 
void alert()
{
   digitalWrite(buzzer, HIGH);
}

void rest()
{
  digitalWrite(buzzer,LOW);
  lcd_1.clear();
}



