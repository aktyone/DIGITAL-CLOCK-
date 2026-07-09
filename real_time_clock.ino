#include <WiFi.h>
#include "time.h"

const char* ssid = "AndroidBauU";
const char* password = "aramis1234";

// Corrected from your PCB:
// A B C D E F G DP
int segPins[] = {32,33,25,26,27,14,12,13};

// D1 D2 D3 D4
int digits[] = {5,17,16,4};

byte numbers[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int displayDigits[4] = {0,0,0,0};

void setup() {
  Serial.begin(115200);

  for(int i=0; i<8; i++) {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], LOW);
  }

  for(int i=0; i<4; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH); // off for common cathode
  }

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  configTime(0, 0, "pool.ntp.org");
  setenv("TZ", "GMT0BST,M3.5.0/1,M10.5.0/2", 1);
  tzset();
}

void updateTime() {
  struct tm timeinfo;

  if(!getLocalTime(&timeinfo)) {
    Serial.println("Failed to get time");
    return;
  }

  int hour = timeinfo.tm_hour;
  int minute = timeinfo.tm_min;

  displayDigits[0] = hour / 10;
  displayDigits[1] = hour % 10;
  displayDigits[2] = minute / 10;
  displayDigits[3] = minute % 10;
}

void showDigit(int digitIndex, int num, bool dot) {
  // turn all digits off
  for(int i=0; i<4; i++) {
    digitalWrite(digits[i], HIGH);
  }

  // turn all segments off
  for(int i=0; i<8; i++) {
    digitalWrite(segPins[i], LOW);
  }

  // set number segments
  for(int i=0; i<7; i++) {
    digitalWrite(segPins[i], numbers[num][i]);
  }

  // decimal point
  digitalWrite(segPins[7], dot ? HIGH : LOW);

  // turn selected digit on
  digitalWrite(digits[digitIndex], LOW);

  delay(2);
}

void loop() {
  static unsigned long lastUpdate = 0;
  static bool dotState = false;

  if(millis() - lastUpdate >= 1000) {
    updateTime();
    dotState = !dotState;
    lastUpdate = millis();
  }

  for(int i=0; i<4; i++) {
    showDigit(i, displayDigits[i], i == 1 ? dotState : false);
  }
}