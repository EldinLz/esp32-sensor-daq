# Validation Record

## Completed checks

| Check | Result | Evidence / notes |
|---|---|---|
| Schematic electrical-rules check | Pass | KiCad 10.0.4 CLI reported 0 errors and 0 warnings on 2026-08-05. |
| PCB design-rules check | Pass with one expected warning | KiCad PCB Editor reported 0 errors and 1 footprint/library mismatch warning. The warning is expected because the ESP32 socket pad sizes were customized in the board copy. |
| Schematic/PCB parity | Pass | KiCad PCB Editor reported 0 parity issues. |
| Routed connections | Pass | KiCad status and DRC reported 0 unconnected items. |
| Manufacturing archive | Complete | Final two-layer Gerber and drill archive is stored in `fabrication/`. |
| Manufacturer preview | Reviewed | Top/bottom copper, solder mask, silkscreen, board outline, and drill layers were reviewed before ordering. |
| PCB fabrication and delivery | Complete | The manufactured PCBs have arrived. |
| Bare-board visual inspection | Pass | No obvious fabrication defects were found. |
| Initial power-off continuity checks | Pass | No 3V3-to-GND short was found, and expected continuity was confirmed on known power and connector nets. |
| Firmware compilation | Pass | Arduino IDE 2.3.10, ESP32 core 3.3.11, target `ESP32C3 Dev Module`, Adafruit BME280 Library 2.3.0. |

## Pending checks

Assembly is in progress. The following powered and functional checks remain pending:

- Post-assembly 3V3-to-GND short check
- Power-rail voltage measurement
- ESP32 programming and reset behavior
- Status LED operation
- BME280 discovery and sensor plausibility
- Photoresistor raw and buffered signal response
- One-hour serial logging stability test

No powered measurements, sensor values, or physical-performance claims are included in this repository yet.

