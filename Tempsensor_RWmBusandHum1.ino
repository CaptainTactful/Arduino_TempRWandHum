//
// FILE: TwoPin_DS18B20.ino
// AUTHOR: Rob Tillaart
// VERSION: 0.1.00
// PURPOSE: two pins for two sensors demo
// DATE: 2014-06-13
// URL: http://forum.arduino.cc/index.php?topic=216835.msg1764333#msg1764333
//
// Released to the public domain
//

#include <OneWire.h>
#include <DallasTemperature.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 3

#define ONE_WIRE_BUS_1 7
#define ONE_WIRE_BUS_2 8
#define ONE_WIRE_BUS_3 9
#define ONE_WIRE_BUS_4 10

#define DHTTYPE    DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

OneWire oneWire_one(ONE_WIRE_BUS_1);
OneWire oneWire_two(ONE_WIRE_BUS_2);
OneWire oneWire_three(ONE_WIRE_BUS_3);
OneWire oneWire_four(ONE_WIRE_BUS_4);

DallasTemperature sensor_busone(&oneWire_one);
DallasTemperature sensor_bustwo(&oneWire_two);
DallasTemperature sensor_busthree(&oneWire_three);
DallasTemperature sensor_busfour(&oneWire_four);

int busoneCount = 0;
int bustwoCount = 0;
int busthreeCount = 0;
int busfourCount = 0;

float sensor1Atwodec = 0;

float sensor1Avalue = 0;

char sensor1Astring = ("startup");

int16_t busoneraw = 0xFFFF;

DeviceAddress add1A, add1B, add1C, add1D, add1E, add1F, add1G, add1H, add1I, add1J;
DeviceAddress add2A, add2B, add2C, add2D, add2E, add2F, add2G, add2H, add2I, add2J;
DeviceAddress add3A, add3B, add3C, add3D, add3E, add3F, add3G, add3H, add3I, add3J;
DeviceAddress add4A, add4B, add4C, add4D, add4E, add4F, add4G, add4H, add4I, add4J;


void setup(void)
{
    Serial.begin(9600);
    Serial.println("Calling Dallas Multibus");

    sensor_busone.begin();
    sensor_bustwo.begin();
    sensor_busthree.begin();
    sensor_busfour.begin();
   
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
 
 /* Serial.println("Printing addresses...");
  for (int i = 0;  i < deviceCount;  i++)
  {
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    sensors.getAddress(Thermometer, i);
    printAddress(Thermometer);
  }
  */
}

void loop(void)
{

   // locate devices on the bus
  Serial.println("Locating devices...");
  Serial.print("Found ");
  busoneCount = sensor_busone.getDeviceCount();
  if (busoneCount > 0) {
  if (!sensor_busone.getAddress(add1A, 0)) Serial.println("NO add1A");
  }
  if (busoneCount > 1) {
  if (!sensor_busone.getAddress(add1B, 1)) Serial.println("NO add1B");
  }
  if (busoneCount > 2) {
  if (!sensor_busone.getAddress(add1C, 2)) Serial.println("NO add1C");
  }
  if (busoneCount > 3) {
  if (!sensor_busone.getAddress(add1D, 3)) Serial.println("NO add1D");
  }
  if (busoneCount > 4) {
  if (!sensor_busone.getAddress(add1E, 4)) Serial.println("NO add1E");
  }
  if (busoneCount > 5) {
  if (!sensor_busone.getAddress(add1F, 5)) Serial.println("NO add1F");
  }
  if (busoneCount > 6) {
  if (!sensor_busone.getAddress(add1G, 6)) Serial.println("NO add1G");
  }
  if (busoneCount > 7) {
  if (!sensor_busone.getAddress(add1H, 7)) Serial.println("NO add1H");
  }
  if (busoneCount > 8) {
  if (!sensor_busone.getAddress(add1I, 8)) Serial.println("NO add1I");
  }
  if (busoneCount > 9) {
  if (!sensor_busone.getAddress(add1J, 9)) Serial.println("NO add1J");
  }

  bustwoCount = sensor_bustwo.getDeviceCount();
    if (bustwoCount > 0) {
  if (!sensor_bustwo.getAddress(add2A, 0)) Serial.println("NO add2A");
  }
  if (bustwoCount > 1) {
  if (!sensor_bustwo.getAddress(add2B, 1)) Serial.println("NO add2B");
  }
  if (bustwoCount > 2) {
  if (!sensor_bustwo.getAddress(add2C, 2)) Serial.println("NO add2C");
  }
  if (bustwoCount > 3) {
  if (!sensor_bustwo.getAddress(add2D, 3)) Serial.println("NO add2D");
  }
  if (bustwoCount > 4) {
  if (!sensor_bustwo.getAddress(add2E, 4)) Serial.println("NO add2A");
  }
  if (bustwoCount > 5) {
  if (!sensor_bustwo.getAddress(add2F, 5)) Serial.println("NO add2A");
  }
  if (bustwoCount > 6) {
  if (!sensor_bustwo.getAddress(add2G, 6)) Serial.println("NO add2A");
  }
  if (bustwoCount > 7) {
  if (!sensor_bustwo.getAddress(add2H, 7)) Serial.println("NO add2A");
  }
  if (bustwoCount > 8) {
  if (!sensor_bustwo.getAddress(add2I, 8)) Serial.println("NO add2A");
  }
  if (bustwoCount > 9) {
  if (!sensor_bustwo.getAddress(add2J, 9)) Serial.println("NO add2A");
  }

  busthreeCount = sensor_busthree.getDeviceCount();
    if (busthreeCount > 0) {
  if (!sensor_busthree.getAddress(add3A, 0)) Serial.println("NO add3A");
  }
  if (busthreeCount > 1) {
  if (!sensor_busthree.getAddress(add3B, 1)) Serial.println("NO add3B");
  }
  if (busthreeCount > 2) {
  if (!sensor_busthree.getAddress(add3C, 2)) Serial.println("NO add3C");
  }
  if (busthreeCount > 3) {
  if (!sensor_busthree.getAddress(add3D, 3)) Serial.println("NO add3D");
  }
  if (busthreeCount > 4) {
  if (!sensor_busthree.getAddress(add3E, 4)) Serial.println("NO add3A");
  }
  if (busthreeCount > 5) {
  if (!sensor_busthree.getAddress(add3F, 5)) Serial.println("NO add3A");
  }
  if (busthreeCount > 6) {
  if (!sensor_busthree.getAddress(add3G, 6)) Serial.println("NO add3A");
  }
  if (busthreeCount > 7) {
  if (!sensor_busthree.getAddress(add3H, 7)) Serial.println("NO add3A");
  }
  if (busthreeCount > 8) {
  if (!sensor_busthree.getAddress(add3I, 8)) Serial.println("NO add3A");
  }
  if (busthreeCount > 9) {
  if (!sensor_busthree.getAddress(add3J, 9)) Serial.println("NO add3A");
  }

  busfourCount = sensor_busfour.getDeviceCount();
    if (busfourCount > 0) {
  if (!sensor_busfour.getAddress(add4A, 0)) Serial.println("NO add4A");
  }
  if (busfourCount > 1) {
  if (!sensor_busfour.getAddress(add4B, 1)) Serial.println("NO add4B");
  }
  if (busfourCount > 2) {
  if (!sensor_busfour.getAddress(add4C, 2)) Serial.println("NO add4C");
  }
  if (busfourCount > 3) {
  if (!sensor_busfour.getAddress(add4D, 3)) Serial.println("NO add4D");
  }
  if (busfourCount > 4) {
  if (!sensor_busfour.getAddress(add4E, 4)) Serial.println("NO add4A");
  }
  if (busfourCount > 5) {
  if (!sensor_busfour.getAddress(add4F, 5)) Serial.println("NO add4A");
  }
  if (busfourCount > 6) {
  if (!sensor_busfour.getAddress(add4G, 6)) Serial.println("NO add4A");
  }
  if (busfourCount > 7) {
  if (!sensor_busfour.getAddress(add4H, 7)) Serial.println("NO add4A");
  }
  if (busfourCount > 8) {
  if (!sensor_busfour.getAddress(add4I, 8)) Serial.println("NO add4A");
  }
  if (busfourCount > 9) {
  if (!sensor_busfour.getAddress(add4J, 9)) Serial.println("NO add4A");
  }
  int deviceCount = busoneCount + bustwoCount + busthreeCount + busfourCount ;
          Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");

    Serial.println("Requesting temperatures...");
    sensor_busone.requestTemperatures();
            Serial.print("Bus 1A: ");
            printAddress(add1A);
            Serial.print("   ");
    Serial.println(sensor_busone.getTempCByIndex(0)); //,0 crops the decimal places
        //sensor1Avalue = (sensor1Atwodec);
        //Serial.println(sensor1Avalue);
    //busoneraw = (sensor_busone.getTemp(0));
    //Serial.println(busoneraw, 16); //raw value -- doesn't work
    delay(500);
            Serial.print("Bus 1B: ");
            printAddress(add1B);
            Serial.print("   ");
    Serial.println(sensor_busone.getTempCByIndex(1));
    delay(500);
            Serial.print("Bus 1C: ");
            printAddress(add1C);
            Serial.print("   ");
    Serial.println(sensor_busone.getTempCByIndex(2));
    delay(500);
            Serial.print("Bus 1D: ");
            printAddress(add1D);
            Serial.print("   ");
    Serial.println(sensor_busone.getTempCByIndex(3));
    delay(500);
            Serial.print("Bus 1E: ");
            printAddress(add1E);
            Serial.print("   ");            
    Serial.println(sensor_busone.getTempCByIndex(4));
    delay(500);
            Serial.print("Bus 1F: ");
            printAddress(add1F);
            Serial.print("   ");            
    Serial.println(sensor_busone.getTempCByIndex(5));
    delay(500);
            Serial.print("Bus 1G: ");
            printAddress(add1G);
            Serial.print("   ");            
    Serial.println(sensor_busone.getTempCByIndex(6));
    delay(500);
            Serial.print("Bus 1H: ");
            printAddress(add1H);
            Serial.print("   ");            
    Serial.println(sensor_busone.getTempCByIndex(7));
    delay(500);
            Serial.print("Bus 1I: ");
            printAddress(add1I);
            Serial.print("   ");            
    Serial.println(sensor_busone.getTempCByIndex(8));
    delay(500);
            Serial.print("Bus 1J: ");
            printAddress(add1J);
            Serial.print("   ");            
    Serial.println(sensor_busone.getTempCByIndex(9));
    delay(500);

    sensor_bustwo.requestTemperatures();
            Serial.print("Bus 2A: ");
            printAddress(add2A);
            Serial.print("   ");
    Serial.println(sensor_bustwo.getTempCByIndex(0));
    //Serial.println(sensor_bustwo.getTemp(0));
    delay(500);
            Serial.print("Bus 2B: ");
            printAddress(add2B);
            Serial.print("   ");
    Serial.println(sensor_bustwo.getTempCByIndex(1));
    delay(500);
            Serial.print("Bus 2C: ");
            printAddress(add2C);
            Serial.print("   ");
    Serial.println(sensor_bustwo.getTempCByIndex(2));
    delay(500);
            Serial.print("Bus 2D: ");
            printAddress(add2D);
            Serial.print("   ");
    Serial.println(sensor_bustwo.getTempCByIndex(3));
    delay(500);
            Serial.print("Bus 2E: ");
            printAddress(add2E);
            Serial.print("   ");            
    Serial.println(sensor_bustwo.getTempCByIndex(4));
    delay(500);
            Serial.print("Bus 2F: ");
            printAddress(add2F);
            Serial.print("   ");            
    Serial.println(sensor_bustwo.getTempCByIndex(5));
    delay(500);
            Serial.print("Bus 2G: ");
            printAddress(add2G);
            Serial.print("   ");            
    Serial.println(sensor_bustwo.getTempCByIndex(6));
    delay(500);
            Serial.print("Bus 2H: ");
            printAddress(add2H);
            Serial.print("   ");            
    Serial.println(sensor_bustwo.getTempCByIndex(7));
    delay(500);
            Serial.print("Bus 2I: ");
            printAddress(add2I);
            Serial.print("   ");            
    Serial.println(sensor_bustwo.getTempCByIndex(8));
    delay(500);
            Serial.print("Bus 2J: ");
            printAddress(add2J);
            Serial.print("   ");            
    Serial.println(sensor_bustwo.getTempCByIndex(9));
    delay(500);


    sensor_busthree.requestTemperatures();
            Serial.print("Bus 3A: ");
            printAddress(add3A);
            Serial.print("   ");
    Serial.println(sensor_busthree.getTempCByIndex(0));
    delay(500);
            Serial.print("Bus 3B: ");
            printAddress(add3B);
            Serial.print("   ");
    Serial.println(sensor_busthree.getTempCByIndex(1));
    delay(500);
            Serial.print("Bus 3C: ");
            printAddress(add3C);
            Serial.print("   ");
    Serial.println(sensor_busthree.getTempCByIndex(2));
    delay(500);
            Serial.print("Bus 3D: ");
            printAddress(add3D);
            Serial.print("   ");
    Serial.println(sensor_busthree.getTempCByIndex(3));
    delay(500);
            Serial.print("Bus 3E: ");
            printAddress(add3E);
            Serial.print("   ");            
    Serial.println(sensor_busthree.getTempCByIndex(4));
    delay(500);
            Serial.print("Bus 3F: ");
            printAddress(add3F);
            Serial.print("   ");            
    Serial.println(sensor_busthree.getTempCByIndex(5));
    delay(500);
            Serial.print("Bus 3G: ");
            printAddress(add3G);
            Serial.print("   ");            
    Serial.println(sensor_busthree.getTempCByIndex(6));
    delay(500);
            Serial.print("Bus 3H: ");
            printAddress(add3H);
            Serial.print("   ");            
    Serial.println(sensor_busthree.getTempCByIndex(7));
    delay(500);
            Serial.print("Bus 3I: ");
            printAddress(add3I);
            Serial.print("   ");            
    Serial.println(sensor_busthree.getTempCByIndex(8));
    delay(500);
            Serial.print("Bus 3J: ");
            printAddress(add3J);
            Serial.print("   ");            
    Serial.println(sensor_busthree.getTempCByIndex(9));
    delay(500);

    sensor_busfour.requestTemperatures();
        Serial.print("Bus 4A: ");
            printAddress(add4A);
            Serial.print("   ");        
    Serial.println(sensor_busfour.getTempCByIndex(0));
    delay(500);
            Serial.print("Bus 4B: ");
            printAddress(add4B);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(1));
    delay(500);
            Serial.print("Bus 4C: ");
            printAddress(add4C);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(2));
    delay(500);
            Serial.print("Bus 4D: ");
            printAddress(add4D);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(3));
    delay(500);
            Serial.print("Bus 4E: ");
            printAddress(add4E);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(4));
    delay(500);
            Serial.print("Bus 4F: ");
            printAddress(add4F);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(5));
    delay(500);
            Serial.print("Bus 4G: ");
            printAddress(add4G);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(6));
    delay(500);
            Serial.print("Bus 4H: ");
            printAddress(add4H);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(7));
    delay(500);    
            Serial.print("Bus 4I: ");
            printAddress(add4I);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(8));
    delay(500);    
            Serial.print("Bus 4J: ");
            printAddress(add4J);
            Serial.print("   ");            
    Serial.println(sensor_busfour.getTempCByIndex(9));            

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }

    delay(2000);
}
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

