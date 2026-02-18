#include <Arduino.h>
#include <SPI.h>
#include <RH_RF95.h>
#include <alarmServer.hpp>
// ---------- Pin config (edit to match your wiring) ----------
static constexpr int PIN_LORA_CS   = 5;   // NSS / CS
static constexpr int PIN_LORA_RST  = 22;  // RESET
static constexpr int PIN_LORA_IRQ  = 21;  // DIO0 (interrupt)



AlarmServer server(PIN_LORA_CS, PIN_LORA_RST, PIN_LORA_IRQ);
void setup() {
Serial.begin(115200);
 server.init();
  pinMode(34,INPUT );
}

void loop() {
  delay(1000);  
  if (digitalRead(34)){
    Serial.println("Pressed");
    server.send_alarm();
    delay(300);
  }

}
