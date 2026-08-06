# Resume and Interview Notes

## Current truthful project summary

Designed a two-layer ESP32-C3 sensor data-acquisition PCB in KiCad, integrating a buffered photoresistor analog front end, BME280 I2C interface, status LED, decoupling, and six labeled test points. Routed and prepared fabrication files, ordered prototype PCBs, and wrote compile-verified Arduino C++ firmware that exports timestamped environmental data as CSV. Physical bring-up is pending hardware arrival and assembly.

## Resume bullet — current stage

- Designed and routed a 65.5 mm × 73.5 mm two-layer ESP32-C3 sensor data-acquisition PCB in KiCad, integrating an MCP6002-buffered light sensor, BME280 I2C interface, status LED, and six debug test points; generated production Gerbers and compile-verified Arduino C++ firmware for CSV telemetry.

## Resume bullet — use only after successful hardware validation

- Designed, assembled, and validated a custom ESP32-C3 environmental data-acquisition PCB, integrating analog light sensing and BME280 temperature/humidity/pressure telemetry; developed Arduino C++ firmware and verified power, I2C, ADC, and serial logging through a structured test-point bring-up plan.

## Interview talking points

- Placement was organized by functional blocks: analog sensing, I2C interface, status indication, and accessible test points.
- The MCP6002 buffers the photoresistor divider so the ADC sees a low-impedance signal.
- The firmware handles both common BME280 I2C addresses and continues logging light data when the BME280 is unavailable.
- Test points were designed in from the start so power, raw analog, buffered analog, SDA, and SCL can be measured directly.
- The project status is documented explicitly so compile checks are not confused with physical validation.

