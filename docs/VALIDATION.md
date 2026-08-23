# Validation Record

Rev A functional hardware bring-up was completed on 2026-08-22.

## Completed checks

| Check | Result | Evidence / notes |
|---|---|---|
| Schematic electrical-rules check | Pass | KiCad 10.0.4 CLI reported 0 errors and 0 warnings on 2026-08-05. |
| PCB design-rules check | Pass with one expected warning | KiCad PCB Editor reported 0 errors and 1 footprint/library mismatch warning. The warning is expected because the ESP32 socket pad sizes were customized in the board copy. |
| Schematic/PCB parity | Pass | KiCad PCB Editor reported 0 parity issues. |
| Routed connections | Pass | KiCad status and DRC reported 0 unconnected items. |
| Manufacturing archive | Complete | Final two-layer Gerber and drill archive is stored in `fabrication/`. |
| Manufacturer preview | Reviewed | Top/bottom copper, solder mask, silkscreen, board outline, and drill layers were reviewed before ordering. |
| PCB fabrication and delivery | Complete | The manufactured PCBs arrived and Rev A was selected for assembly. |
| Bare-board visual inspection | Pass | No obvious fabrication defects were found. |
| Initial power-off continuity checks | Pass | No 3V3-to-GND short was found, and expected continuity was confirmed on known power and connector nets. |
| Physical assembly | Complete | Rev A through-hole components, sockets, header, and supporting circuitry were hand-soldered and inspected. |
| Post-assembly power-off check | Pass | No 3V3-to-GND short was found before powered bring-up. |
| 3.3 V operation | Pass | The assembled board powered and ran from the ESP32-C3 3.3 V rail. |
| Firmware compilation and upload | Pass | Arduino IDE 2.3.10, ESP32 core 3.3.11, target `ESP32C3 Dev Module`, Adafruit BME280 Library 2.3.0. Upload completed and the flashed image hash was verified. |
| Serial CSV output | Pass | Firmware emitted the expected header and one data row per second at 115200 baud. |
| Status LED | Pass | A brief firmware-driven activity blink was observed. |
| BME280 discovery | Pass | Serial Monitor reported `BME280 detected` over I2C. |
| BME280 sensor plausibility | Pass | Captured readings were approximately 25.2-26.0 C, 47-49% RH, and 1009.7-1009.9 hPa during bring-up. |
| End-to-end light-channel response | Pass | Covered: approximately 247-265 counts (6.0-6.5%); room light: approximately 1887-2134 counts (46.1-52.1%); flashlight: 4095 counts (100.0%). |

## Scope and remaining characterization

- `light_percent` is ADC full-scale percentage, not calibrated lux.
- The light response validates the complete photoresistor-divider, MCP6002-buffer, ESP32 ADC, firmware, and serial-output path. TP3-to-TP4 transfer accuracy has not been independently measured.
- Temperature, humidity, and pressure were checked for plausible live response but were not calibrated against reference instruments.
- The planned one-hour serial logging stability test has not been completed.

