#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>

// ==========================
// IR SENSOR PINS
// ==========================

#define IR1 D5
#define IR2 D6


// ==========================
// WIFI
// ==========================

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";


// ==========================
// FIREBASE
// ==========================

const char* firebaseURL =
  "https://library-seat-availability-default-rtdb.asia-southeast1.firebasedatabase.app";


void setup() {

  // Start Serial Monitor
  Serial.begin(115200);

  // IR sensor pins
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);


  // ==========================
  // CONNECT TO WIFI
  // ==========================

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  Serial.print("ESP8266 IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
  Serial.println("System Started!");
}


void loop() {

  // ==========================
  // READ IR SENSORS
  // ==========================

  int sensor1 = digitalRead(IR1);
  int sensor2 = digitalRead(IR2);


  // ==========================
  // SEAT STATUS
  // ==========================

  // Your sensor:
  // 1 = No object = AVAILABLE
  // 0 = Object detected = OCCUPIED

  bool seat1Available = (sensor1 == 1);
  bool seat2Available = (sensor2 == 1);


  // ==========================
  // COUNT AVAILABLE SEATS
  // ==========================

  int availableSeats = 0;

  if (seat1Available) {
    availableSeats++;
  }

  if (seat2Available) {
    availableSeats++;
  }


  // ==========================
  // SHOW STATUS
  // ==========================

  Serial.println();
  Serial.println("--------------------------");

  Serial.print("IR1 = ");
  Serial.println(sensor1);

  Serial.print("IR2 = ");
  Serial.println(sensor2);

  Serial.print("Seat 1: ");

  if (seat1Available) {
    Serial.println("AVAILABLE");
  } 
  else {
    Serial.println("OCCUPIED");
  }


  Serial.print("Seat 2: ");

  if (seat2Available) {
    Serial.println("AVAILABLE");
  } 
  else {
    Serial.println("OCCUPIED");
  }


  Serial.print("Available Seats: ");
  Serial.print(availableSeats);
  Serial.println(" / 2");


  // ==========================
  // SEND DATA TO FIREBASE
  // ==========================

  WiFiClientSecure client;

  // Temporary for prototype testing
  client.setInsecure();

  HTTPClient https;

  String url = String(firebaseURL) + "/seats.json";


  if (https.begin(client, url)) {

    https.addHeader("Content-Type", "application/json");


    // Create Firebase data
    String data = "{";

    data += "\"seat1\":";
    data += seat1Available ? "true" : "false";

    data += ",";

    data += "\"seat2\":";
    data += seat2Available ? "true" : "false";

    data += "}";


    Serial.println();
    Serial.println("Sending data to Firebase...");
    Serial.println(data);


    // Send data
    int httpCode = https.PUT(data);


    Serial.print("Firebase HTTP Code: ");
    Serial.println(httpCode);


    if (httpCode > 0) {

      Serial.println("Firebase Response:");
      Serial.println(https.getString());

    } 
    else {

      Serial.println("Firebase request failed.");
      Serial.println(https.errorToString(httpCode));

    }


    https.end();

  } 
  else {

    Serial.println("Unable to connect to Firebase.");

  }


  // Wait 2 seconds
  delay(2000);
}
