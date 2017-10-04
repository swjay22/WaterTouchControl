#include "Arduino.h"
#include "Menu.h"
#include "DwellTank.h"
#include "Status.h"
#include "Power.h"
#include "Schedule.h"
#include "Flow.h"
#include "Monitoring.h"
#include "WoolFeed.h"

// Set to true to debug crashes
#define DEBUG_MAIN false // NOTE: you must disable debugging in other files first

void setup() {
  // put your setup code here, to run once:
  if (DEBUG_MAIN)Serial.begin(9600);
  initMenu();
  initSchedule();
  initStatus();
  initDwellTank();
  if (DEBUG_MAIN)Serial.println("finsihed dwell tank");
  initPower();
  initFlow();
  initMonitoring();
  initWoolFeed();
  if (DEBUG_MAIN)Serial.println("finsihed setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (DEBUG_MAIN)Serial.println("started loop");
  updateStatus();
  if (DEBUG_MAIN)Serial.println("finsihed status");
  updateDwellTank();
  if (DEBUG_MAIN)Serial.println("finsihed dwell tank");
  updatePower();
  updateSchedule();
  updateFlow();
  updateMonitoring();
  if (DEBUG_MAIN)Serial.println("finsihed monitoring");
  updateWoolFeed();
  updateMenu(50);
  if (DEBUG_MAIN)Serial.println("finsihed loop");
  while (millis() % 50 > 1) {
    delay(1);
  }
}
