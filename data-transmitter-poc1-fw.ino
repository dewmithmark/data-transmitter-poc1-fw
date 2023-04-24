#include <SPI.h>
#include "LoRa.h" 
#include <DHT.h>

#define ss 15
#define rst 16
#define dio0 2
#define DHT11_PIN 2

DHT dht2(0,DHT11);  

typedef enum _rain_modes
{
  RAIN_DETECTED =0,
  RAIN_NOT_DETECTED
}rain_modes;

uint8_t rain_status = 0;
float temp_val = 0;
uint8_t humidity_val = 0;

const int rain_sensor_pin = 4;

void LORA_connect()
{
  Serial.println("LoRa Sender");
  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6))
  {
    Serial.println("Starting LoRa failed!");
    delay(100);
    while (1);
  }    
}

rain_modes rain_sensor_read(void)
{
  if(LOW == digitalRead(rain_sensor_pin))
  {
    return RAIN_DETECTED;
  }
  else
  {
    return RAIN_NOT_DETECTED;
  }
}

float temp_sensor_read()
{
  return (dht2.readTemperature()); 
}

uint8_t humidity_sensor_read()
{
  return (dht2.readHumidity()); 
}
void transmit_data()
{
    LoRa.beginPacket();
    
    LoRa.print(rain_status);
    LoRa.print(" ");
    LoRa.print(temp_val);
    LoRa.print(" ");
    LoRa.print(humidity_val);
    LoRa.print(" \n");
    
    LoRa.endPacket();  
}

void serial_print_data()
{
    Serial.print(rain_status);
    Serial.print(", ");
    Serial.print(temp_val);
    Serial.print(", ");
    Serial.print(humidity_val);
    Serial.print(" \n");
}
 
void setup() 
{
  Serial.begin(9600);
  pinMode(rain_sensor_pin, INPUT);
  while (!Serial);
  LORA_connect();

  Serial.println("rain_status, temperature, humidity");

}

void loop() 
{
  rain_status = rain_sensor_read();
  temp_val = temp_sensor_read();
  humidity_val = humidity_sensor_read();

  transmit_data();
  serial_print_data();

  delay(1000);
}
