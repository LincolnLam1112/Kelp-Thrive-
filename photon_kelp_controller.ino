// Photon 2 Kelp Controller
//
// Reads four potentiometers on A0-A3, maps each 12-bit ADC value to 0-100,
// and sends one clean serial line every 100 ms using the protocol expected by
// the Kelp Health Simulator web app:
//
//   light=72,temp=58,nutrients=80,pollution=15
//
// Wire each potentiometer as:
//   3V3 -> one outer pin
//   GND -> other outer pin
//   wiper -> analog input

SYSTEM_MODE(SEMI_AUTOMATIC);

const pin_t LIGHT_PIN = A0;
const pin_t TEMP_PIN = A1;
const pin_t NUTRIENT_PIN = A2;
const pin_t POLLUTION_PIN = A3;

const unsigned long SAMPLE_INTERVAL_MS = 100;
unsigned long lastSampleAt = 0;

// Maps Photon 2 ADC readings (0-4095) into the 0-100 range used by the game.
int mapPotToPercent(int rawValue) {
  rawValue = constrain(rawValue, 0, 4095);
  return (rawValue * 100) / 4095;
}

void setup() {
  pinMode(LIGHT_PIN, INPUT);
  pinMode(TEMP_PIN, INPUT);
  pinMode(NUTRIENT_PIN, INPUT);
  pinMode(POLLUTION_PIN, INPUT);

  Serial.begin(115200);

  // Give the browser a moment to open the USB serial port after reset.
  waitFor(Serial.isConnected, 5000);
}

void loop() {
  if (millis() - lastSampleAt < SAMPLE_INTERVAL_MS) {
    return;
  }
  lastSampleAt = millis();

  const int light = mapPotToPercent(analogRead(LIGHT_PIN));
  const int temp = mapPotToPercent(analogRead(TEMP_PIN));
  const int nutrients = mapPotToPercent(analogRead(NUTRIENT_PIN));
  const int pollution = mapPotToPercent(analogRead(POLLUTION_PIN));

  // Send exactly one line in the web app's expected key=value format.
  Serial.printf(
    "light=%d,temp=%d,nutrients=%d,pollution=%d\n",
    light,
    temp,
    nutrients,
    pollution
  );
}
