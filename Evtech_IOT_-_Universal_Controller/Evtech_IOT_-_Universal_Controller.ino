// Evtech IOT - Universal Controller (Blynk 2.0)
// Evtech | @earldanielph
// beacons.page/evtech

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;


#define button1_pin 26
#define button2_pin 25
#define button3_pin 16
#define button4_pin 17
#define button5_pin 27
#define button6_pin 32
#define button7_pin 4

#define relay1_pin 34
#define relay2_pin 33
#define relay3_pin 35
#define relay4_pin 18
#define relay5_pin 19
#define relay6_pin 23
#define relay7_pin 5

int relay1_state = 0;
int relay2_state = 0;
int relay3_state = 0;
int relay4_state = 0;
int relay5_state = 0;
int relay6_state = 0;
int relay7_state = 0;


//Change the virtual pins according to the rooms
#define button1_vpin    V1
#define button2_vpin    V2
#define button3_vpin    V3 
#define button4_vpin    V4
#define button5_vpin    V5
#define button6_vpin    V6
#define button7_vpin    V7

//------------------------------------------------------------------------------
// This function is called every time the device is connected to the Blynk.Cloud
// Request the latest state from the server
BLYNK_CONNECTED() {
  Blynk.syncVirtual(button1_vpin);
  Blynk.syncVirtual(button2_vpin);
  Blynk.syncVirtual(button3_vpin);
  Blynk.syncVirtual(button4_vpin);
  Blynk.syncVirtual(button5_vpin);
  Blynk.syncVirtual(button6_vpin);
  Blynk.syncVirtual(button7_vpin);
}

//--------------------------------------------------------------------------
// This function is called every time the Virtual Pin state changes
// i.e when the web push switch from Blynk App or Web Dashboard
BLYNK_WRITE(button1_vpin) {
  relay1_state = param.asInt();
  digitalWrite(relay1_pin, relay1_state);
}

//--------------------------------------------------------------------------
BLYNK_WRITE(button2_vpin) {
  relay2_state = param.asInt();
  digitalWrite(relay2_pin, relay2_state);
}

//--------------------------------------------------------------------------
BLYNK_WRITE(button3_vpin) {
  relay3_state = param.asInt();
  digitalWrite(relay3_pin, relay3_state);
}

//--------------------------------------------------------------------------
BLYNK_WRITE(button4_vpin) {
  relay4_state = param.asInt();
  digitalWrite(relay4_pin, relay4_state);
}

//--------------------------------------------------------------------------
BLYNK_WRITE(button5_vpin) {
  relay5_state = param.asInt();
  digitalWrite(relay5_pin, relay5_state);
}

//--------------------------------------------------------------------------
BLYNK_WRITE(button6_vpin) {
  relay6_state = param.asInt();
  digitalWrite(relay6_pin, relay6_state);
}

//--------------------------------------------------------------------------
BLYNK_WRITE(button7_vpin) {
  relay7_state = param.asInt();
  digitalWrite(relay7_pin, relay7_state);
}

//--------------------------------------------------------------------------

void setup()
{
  // Debug console
  Serial.begin(115200);
  
  //--------------------------------------------------------------------
  pinMode(button1_pin, INPUT_PULLUP);
  pinMode(button2_pin, INPUT_PULLUP);
  pinMode(button3_pin, INPUT_PULLUP);
  pinMode(button4_pin, INPUT_PULLUP);
  pinMode(button5_pin, INPUT_PULLUP);
  pinMode(button6_pin, INPUT_PULLUP);
  pinMode(button7_pin, INPUT_PULLUP);
  //--------------------------------------------------------------------
  pinMode(relay1_pin, OUTPUT);
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
  pinMode(relay4_pin, OUTPUT);
  pinMode(relay5_pin, OUTPUT);
  pinMode(relay6_pin, OUTPUT);
  pinMode(relay7_pin, OUTPUT);
  //--------------------------------------------------------------------
  // During starting, all relays should be turned off
  digitalWrite(relay1_pin, HIGH);
  digitalWrite(relay2_pin, HIGH);
  digitalWrite(relay3_pin, HIGH);
  digitalWrite(relay4_pin, HIGH);
  digitalWrite(relay5_pin, HIGH);
  digitalWrite(relay6_pin, HIGH);
  digitalWrite(relay7_pin, HIGH);
  //--------------------------------------------------------------------
  Blynk.begin(auth, ssid, pass);
  // You can also specify the server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  //--------------------------------------------------------------------
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  
  listen_push_buttons();
}

void listen_push_buttons() {
  if (digitalRead(button1_pin) == LOW) {
    delay(200);
    control_relay(1);
    Blynk.virtualWrite(button1_vpin, relay1_state); // Update button state
  }
  else if (digitalRead(button2_pin) == LOW) {
    delay(200);
    control_relay(2);
    Blynk.virtualWrite(button2_vpin, relay2_state); // Update button state
  }
  else if (digitalRead(button3_pin) == LOW) {
    delay(200);
    control_relay(3);
    Blynk.virtualWrite(button3_vpin, relay3_state); // Update button state
  }
  else if (digitalRead(button4_pin) == LOW) {
    delay(200);
    control_relay(4);
    Blynk.virtualWrite(button4_vpin, relay4_state); // Update button state
  }
  else if (digitalRead(button5_pin) == LOW) {
    delay(200);
    control_relay(5);
    Blynk.virtualWrite(button5_vpin, relay5_state); // Update button state
  }
  else if (digitalRead(button6_pin) == LOW) {
    delay(200);
    control_relay(6);
    Blynk.virtualWrite(button6_vpin, relay6_state); // Update button state
  }
  else if (digitalRead(button7_pin) == LOW) {
    delay(200);
    control_relay(7);
    Blynk.virtualWrite(button7_vpin, relay7_state); // Update button state
  }
}

void control_relay(int relay) {
  if (relay == 1) {
    relay1_state = !relay1_state;
    digitalWrite(relay1_pin, relay1_state);
    Serial.print("Relay1 State = ");
    Serial.println(relay1_state);
    delay(50);
  }
  else if (relay == 2) {
    relay2_state = !relay2_state;
    digitalWrite(relay2_pin, relay2_state);
    delay(50);
  }
  else if (relay == 3) {
    relay3_state = !relay3_state;
    digitalWrite(relay3_pin, relay3_state);
    delay(50);
  }
  else if (relay == 4) {
    relay4_state = !relay4_state;
    digitalWrite(relay4_pin, relay4_state);
    delay(50);
  }
  else if (relay == 5) {
    relay5_state = !relay5_state;
    digitalWrite(relay5_pin, relay5_state);
    delay(50);
  }
  else if (relay == 6) {
    relay6_state = !relay6_state;
    digitalWrite(relay6_pin, relay6_state);
    delay(50);
  }
  else if (relay == 7) {
    relay7_state = !relay7_state;
    digitalWrite(relay7_pin, relay7_state);
    delay(50);
  }
}

// Evtech IOT - Universal Controller (Blynk 2.0)
// Evtech | @earldanielph
// beacons.page/evtech
