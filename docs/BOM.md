# Bill of Materials

Quantities below are for one assembled board. Exact supplier stock can change; verify the footprint, lead pitch, and voltage rating before substituting a part.

| Ref. | Qty. | Component | Value / selected part | PCB footprint or interface |
|---|---:|---|---|---|
| U1 | 1 | ESP32-C3 development board | ESP32-C3 DevKitM-1 | Two 1x15, 2.54 mm socket rows |
| U2 | 1 | Dual rail-to-rail op-amp | MCP6002-I/P | DIP-8, 7.62 mm row spacing |
| — | 1 | DIP socket | 8-position | DIP-8 |
| R1 | 1 | CdS photoresistor | 5 mm class | 3.4 mm lead pitch footprint |
| R2 | 1 | Resistor | 10 kΩ, 1/4 W | Axial, 7.62 mm pitch |
| R3, R4 | 2 | I2C pull-up resistors | 4.7 kΩ, 1/4 W | Axial, 7.62 mm pitch |
| R5 | 1 | LED resistor | 330 Ω, 1/4 W | Axial, 7.62 mm pitch |
| C1 | 1 | Ceramic capacitor | 100 nF | Through-hole disc, 5.00 mm pitch |
| D1 | 1 | Status LED | 5 mm LED | 2.54 mm pitch |
| J1 | 1 | BME280 connector | 1x4 vertical pin header | 2.54 mm pitch |
| — | 1 | BME280 breakout | Adafruit BME280 I2C/SPI breakout | Connected to J1 over 3V3, GND, SDA, SCL |
| — | 2 | ESP32 socket strips | 1x15 female receptacle | 2.54 mm pitch |

## Test points

TP1 through TP6 are plated through-holes and do not require a separate component. Optional loop or turret test points may be installed if desired.

| Test point | Net |
|---|---|
| TP1 | 3V3 |
| TP2 | GND |
| TP3 | LIGHT_RAW |
| TP4 | LIGHT_ADC |
| TP5 | I2C_SDA |
| TP6 | I2C_SCL |

## Assembly supplies

- Solder and flux
- Female-to-female jumper wires for the BME280 breakout
- USB data cable for ESP32 programming
- Multimeter with continuity and DC-voltage modes

