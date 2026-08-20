# Assembly and Hardware Test Plan

This plan is intentionally staged so that a soldering or power fault can be found before expensive modules are inserted.

## 1. Bare-board inspection

- Confirm the board outline is intact and flat.
- Inspect every plated hole for complete copper plating.
- Confirm the U1 square pad identifies pin 1.
- Confirm the J1 silkscreen mapping: pin 1 = 3V3, pin 2 = GND, pin 3 = SDA, pin 4 = SCL.
- Check for scratches, solder-mask damage, or copper bridges.

## 2. Power-off electrical checks

Use continuity or resistance mode before inserting U1, U2, or the BME280.

- TP1 (3V3) to TP2 (GND) must not be a short.
- J1 pin 1 must connect to TP1.
- J1 pin 2 must connect to TP2.
- J1 pin 3 must connect to TP5.
- J1 pin 4 must connect to TP6.
- Verify the LED polarity marking and the DIP-8 socket notch orientation.

Stop and correct the board if the 3V3-to-GND measurement is near zero ohms.

## 3. Assembly order

1. Solder the resistors and C1.
2. Solder the DIP-8 socket; leave the MCP6002 out initially.
3. Solder the photoresistor, LED, and J1 header.
4. Solder both 1x15 ESP32 socket rows using the ESP32 module only as a temporary alignment guide.
5. Clean and inspect every joint.
6. Repeat the 3V3-to-GND short check.
7. Insert the MCP6002 with its pin-1 notch aligned to the footprint.
8. Insert the ESP32-C3 in the correct orientation.

## 4. First power-up

- Disconnect the BME280 for the first power-up.
- Connect the ESP32 by USB through a current-limited USB source when available.
- Measure TP1 relative to TP2; expected value is approximately 3.3 V.
- Disconnect power immediately if a component becomes hot, the voltage collapses, or excessive current is observed.

## 5. Firmware upload

1. Open `firmware/ESP32_Sensor_DAQ_Firmware/ESP32_Sensor_DAQ_Firmware.ino` in Arduino IDE.
2. Select `ESP32C3 Dev Module` and the connected serial port.
3. Compile and upload.
4. Open Serial Monitor at 115200 baud.
5. Confirm the CSV header appears and one data row is emitted each second.

With the BME280 disconnected, `NA,NA,NA` is expected for its three fields.

## 6. BME280 test

- Power off before connecting the breakout to J1.
- Connect 3V3, GND, SDA, and SCL exactly as labeled.
- Reapply power and confirm `BME280 detected` in Serial Monitor.
- Confirm temperature, humidity, and pressure values are plausible and stable.
- The firmware tries I2C address `0x77`, then `0x76`.

## 7. Light channel test

- Record TP3 (`RAW`) and TP4 (`ADC`) voltages under normal room light.
- Cover the photoresistor and confirm both values change.
- Illuminate the photoresistor and confirm both values change in the opposite direction.
- Confirm `light_raw` remains within 0–4095 and changes with illumination.
- Compare TP3 and TP4 to confirm the op-amp buffer follows the raw signal without obvious clipping.

## 8. Stability test

- Log serial output for at least one hour.
- Check for resets, malformed CSV rows, missing BME280 readings, or values stuck at a rail.
- Save a sample log and a plot for the portfolio README after successful testing.

## Test record

| Item | Result | Measurement / notes |
|---|---|---|
| Bare-board inspection | Pass | No obvious fabrication defects found. |
| 3V3-to-GND short check | Pass | No short found during the initial bare-board check. |
| Known power/connector net continuity | Pass | Expected continuity confirmed on known power and connector nets. |
| TP1 voltage | Pending | Requires powered hardware. |
| Firmware upload | Pending | |
| Status LED | Pending | |
| BME280 detected | Pending | |
| Temperature plausible | Pending | |
| Humidity plausible | Pending | |
| Pressure plausible | Pending | |
| Light response | Pending | |
| One-hour logging test | Pending | |
