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
| Firmware compilation | Pass | Arduino IDE 2.3.10, ESP32 core 3.3.11, target `ESP32C3 Dev Module`, Adafruit BME280 Library 2.3.0. |

## Pending checks

The following items require the manufactured PCB and components:

- Visual inspection of the bare PCB
- 3V3-to-GND short check
- Power-rail voltage measurement
- ESP32 programming and reset behavior
- Status LED operation
- BME280 discovery and sensor plausibility
- Photoresistor raw and buffered signal response
- One-hour serial logging stability test

No measured sensor values or physical-performance claims are included in this repository yet.

