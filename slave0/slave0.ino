#define Sender_Txd_pin 17
#define Sender_Rxd_pin 16

HardwareSerial Receiver(1);

const int inputPin = 34;    // GPIO Pin
const int AirValue = 3579;   //Need change for callibration for air
const int WaterValue = 250;  //Need change for callibration for water
float soilPercentage = 0;
float soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);
  Receiver.begin(9600, SERIAL_8N1, Sender_Rxd_pin, Sender_Txd_pin);
}

void loop() {
  soilMoistureValue = analogRead(inputPin);
  soilPercentage = ((((AirValue - WaterValue) - (soilMoistureValue - WaterValue)) /(AirValue - WaterValue)) * 100);
  Serial.println("User#0: " + String(soilPercentage) + "%");
  Receiver.print("User#0: " + String(soilPercentage));
  delay(5000);
}
