# ESP32-C3 sensor board: design and bring-up

Eldin Lozic · Electrical Engineer Intern challenge

I designed this two-layer KiCad carrier board to collect light, temperature, humidity, and pressure data. It combines an ESP32-C3 DevKitM-1, an MCP6002-buffered photoresistor channel, and a BME280 breakout connected over I2C. I hand-assembled Rev A and brought it up with Arduino firmware that streams CSV over USB serial.

## Finished hardware

![Hand-assembled Rev A PCB with socketed ESP32-C3](../images/rev-a-assembled-angle.jpeg)

![Rev A PCB connected to the BME280 breakout](../images/rev-a-full-system.jpeg)

## A small feature that makes debugging easier

I brought the light signal out to two labeled test points: TP3 (`RAW`), before the MCP6002, and TP4 (`ADC`), after it. The op-amp is wired as a voltage follower, which buffers the photoresistor divider before the ESP32 ADC samples it.

The useful part is being able to probe both sides of that buffer without soldering temporary wires onto component leads. If the serial reading is wrong, I can check whether the divider changes with light, whether the buffer follows it, and whether the ADC reading agrees with its input. This gives a direct way to narrow the fault to the sensor/divider, buffer, or ADC/firmware path.

The board also exposes 3V3, GND, SDA, and SCL. The ESP32 sits in removable socket headers, and the through-hole parts are accessible for hand assembly and rework.

![Schematic exported from the Rev A KiCad source](../images/rev-a-schematic.png)

[KiCad schematic source](../hardware/ESP32_Sensor_Data_Acquisition_Board.kicad_sch) · [PCB layout source](../hardware/ESP32_Sensor_Data_Acquisition_Board.kicad_pcb)

## What I checked on hardware

The recorded Rev A bring-up was completed on August 22, 2026. Power-off checks found no 3V3-to-GND short, firmware uploaded successfully, and the board produced serial CSV output at 115200 baud. The BME280 was detected over I2C, with live readings around 25.2–26.0 °C, 47–49% RH, and 1009.7–1009.9 hPa.

The light channel responded across these conditions:

- Covered: about 247–265 ADC counts.
- Room light: about 1887–2134 counts.
- Flashlight: 4095 counts, the 12-bit ADC full-scale value.

Those readings verify the complete light-sensor-to-serial path. They do not establish calibrated lux, standalone buffer accuracy, or long-term stability. Direct TP3-to-TP4 characterization and the planned one-hour logging test are still pending. This board has not been tested for outdoor or balloon-flight conditions.

[Validation record](VALIDATION.md) · [Bring-up procedure](TEST_PLAN.md) · [Firmware](../firmware/ESP32_Sensor_DAQ_Firmware/ESP32_Sensor_DAQ_Firmware.ino)
