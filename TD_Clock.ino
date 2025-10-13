#include "TFT_eSPI.h"
#include "SPI.h"

#define L_BUTTON 0
#define R_BUTTON 35
#define HEIGHT 135
#define WIDTH 240

TFT_eSPI tft = TFT_eSPI();

#include "FastTrig.h"
#define PI 3.14159

#include "time.h"
#define NTP "pool.ntp.org"
#define GMT_OFFSET 0
#define DAYLIGHT_OFFSET 3600

struct tm t_struct;
char t_str[9];
float lastSecTheta = 0;
float lastMinTheta = 0;
float lastHourTheta = 0;
bool isAnalog = false;
bool clearedScreen = false;

#define DEBOUNCE_TIME 200
unsigned long debounceTime;

#include "WiFi.h"
#include "esp_eap_client.h"
#include "secrets.h"

void setupWifi() {
  const char* USER = USERNAME;
  const char* PASS = PASSWORD;
  
  WiFi.mode(WIFI_STA);

  esp_eap_client_set_identity((uint8_t *)USER, strlen(USER));
  esp_eap_client_set_username((uint8_t *)USER, strlen(USER));
  esp_eap_client_set_password((uint8_t *)PASS, strlen(PASS));

  esp_wifi_sta_enterprise_enable();
  WiFi.begin("eduroam");
  
  while ((WiFi.status() != WL_CONNECTED))
  {
    delay(500);
  }
}

void ButtonPressed(){
  if ((millis() - debounceTime) < DEBOUNCE_TIME) { return; }
  debounceTime = millis();

  isAnalog = !isAnalog;
  clearedScreen = false;
}

void lButtonPressed() {
  ButtonPressed();
}
void rButtonPressed() {
  ButtonPressed();
}

void render() {
  strftime(t_str, 9, "%T", &t_struct);

  if (!clearedScreen) {
    tft.fillScreen(TFT_BLACK);
    clearedScreen = true;
    if (isAnalog) { tft.drawSmoothCircle(WIDTH*.5, HEIGHT*.5, HEIGHT*.5, TFT_WHITE, TFT_WHITE); }
  }
  getLocalTime(&t_struct);
  if (isAnalog) {
    
    uint8_t h_centre = HEIGHT*.5;
    uint8_t w_centre = WIDTH*.5;

    uint8_t radius = h_centre-1;

    uint8_t x;
    uint8_t y;

    //hour hand
    float hourtheta = t_struct.tm_hour*60 + t_struct.tm_min;
    if (hourtheta != lastHourTheta) {
      tft.drawLine(w_centre, h_centre, w_centre + (radius-35)*cos(lastHourTheta * (PI/360) - (PI/2)), h_centre + (radius-35)*sin(lastHourTheta * (PI/360) - (PI/2)), TFT_BLACK);
    }
    lastHourTheta;
    tft.drawLine(w_centre, h_centre, w_centre + (radius-35)*cos(hourtheta * (PI/360) - (PI/2)), h_centre + (radius-35)*sin(hourtheta * (PI/360) - (PI/2)), TFT_WHITE);

    //min hand
    float mintheta  = t_struct.tm_min*60 + t_struct.tm_sec;
    if (mintheta != lastMinTheta) {
      tft.drawLine(w_centre, h_centre, w_centre + (radius-15)*cos(lastMinTheta * (PI/1800) - (PI/2)), h_centre + (radius-15)*sin(lastMinTheta * (PI/1800) - (PI/2)), TFT_BLACK);   
    }
    lastMinTheta = mintheta;
    tft.drawLine(w_centre, h_centre, w_centre + (radius-15)*cos(mintheta * (PI/1800) - (PI/2)), h_centre + (radius-15)*sin(mintheta * (PI/1800) - (PI/2)), TFT_WHITE);   

    //second hand
    float secstheta = t_struct.tm_sec;
    if (secstheta != lastSecTheta) {
      tft.drawLine(w_centre, h_centre, w_centre + (radius-5)*cos(lastSecTheta * (PI/30) - (PI/2)), h_centre + (radius-5)*sin(lastSecTheta * (PI/30) - (PI/2)), TFT_BLACK);
    }
    lastSecTheta = secstheta;
    tft.drawLine(w_centre, h_centre, w_centre + (radius-5)*cos(secstheta * (PI/30) - (PI/2)), h_centre + (radius-5)*sin(secstheta * (PI/30) - (PI/2)), TFT_RED);

  } 
  else {
    tft.drawString(t_str, WIDTH/2, HEIGHT/2);
  }
}

void setup() {
  Serial.begin(9600);
  
  setupWifi();
  configTime(GMT_OFFSET, DAYLIGHT_OFFSET, NTP);
  
  tft.init();
  tft.setRotation(1);

  tft.setTextDatum(MC_DATUM);
  tft.setTextFont(7);
  tft.setTextSize(1);

  debounceTime = millis();
  attachInterrupt(digitalPinToInterrupt(L_BUTTON), lButtonPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(R_BUTTON), rButtonPressed, RISING);
}

void loop() {
  render();
  //Serial.println(t_str);
}
