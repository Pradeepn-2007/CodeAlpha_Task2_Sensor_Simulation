# CodeAlpha_Task2_Sensor_Simulation

**CodeAlpha Internet of Things (IoT) Internship — Task 2: Sensor-Based Simulation**

## Objective

Simulate a simple IoT system using Tinkercad Circuits (no physical hardware
required) that reads temperature from a sensor and controls an LED
automatically. This project — a **Temperature-Based IoT Alert System** —
turns an LED ON when the temperature reaches or exceeds 30°C, and OFF when
it drops below 30°C, while continuously printing the temperature to the
Serial Monitor.

## Components

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Runs the program and processes sensor data |
| LM35 Temperature Sensor | 1 | Measures ambient temperature |
| LED | 1 | Turns ON as a visual high-temperature alert |
| Resistor (220 Ω) | 1 | Protects the LED from excess current |
| Jumper wires | As needed | Connects everything together |
| Breadboard | 1 | Holds the components (virtual, in Tinkercad) |

## Circuit Connections

| From | To | Wire Type |
|---|---|---|
| LM35 – VCC | Arduino – 5V | Power |
| LM35 – GND | Arduino – GND | Ground |
| LM35 – OUT | Arduino – Analog pin A0 | Signal |
| Arduino – Digital pin 8 | Resistor (220 Ω) → LED Anode (+) | Signal |
| LED Cathode (–) | Arduino – GND | Ground |

See `circuit/circuit_diagram.png` for the full labeled diagram.

## How It Works

1. The Arduino reads the LM35's analog output on pin `A0`.
2. The raw reading (0–1023) is converted to a voltage, then to a temperature
   in Celsius (the LM35 outputs 10 mV per °C).
3. The temperature is printed to the Serial Monitor once per second.
4. If temperature **≥ 30°C**, the LED (Digital Pin 8) turns **ON**.
5. If temperature **< 30°C**, the LED turns **OFF**.

## How to Run the Simulation (Tinkercad Circuits)

1. Go to [tinkercad.com](https://www.tinkercad.com) → **Circuits** → **Create new Circuit**.
2. Drag in an **Arduino Uno**, an **LM35 Temperature Sensor**, an **LED**, and a **Resistor** (set to 220 Ω).
3. Wire everything exactly as shown in `circuit/circuit_diagram.png` and the table above.
4. Click the Arduino Uno → **Code** → switch the editor from "Blocks" to **"Text"**.
5. Paste in the full contents of `src/temperature_sensor.ino`.
6. Click **Start Simulation** and open the **Serial Monitor**.
7. Drag the LM35's temperature slider above and below 30°C to confirm the LED turns ON and OFF correctly.

Full step-by-step instructions, the algorithm, and a line-by-line code
explanation are in `documentation/Task2_Code_Explanation.pdf`.

## Expected Behavior

- Serial Monitor prints a new temperature reading approximately every second.
- Temperature **≥ 30°C** → LED turns **ON**, status prints as `ALERT`.
- Temperature **< 30°C** → LED turns **OFF**, status prints as `Normal`.

## Folder Structure

```
CodeAlpha_Task2_Sensor_Simulation/
│
├── README.md                              # This file
│
├── src/
│   └── temperature_sensor.ino             # Complete, commented Arduino sketch
│
├── circuit/
│   └── circuit_diagram.png                # Labeled circuit diagram
│
├── screenshots/
│   └── README.md                          # Instructions for screenshots you must capture yourself
│                                           # (simulation_setup.png, led_on.png, serial_monitor.png)
│
└── documentation/
    └── Task2_Code_Explanation.pdf         # Full write-up: objective, components,
                                            # circuit, working principle, algorithm,
                                            # code explanation, expected output,
                                            # simulation procedure, conclusion
```

## Important Note on Screenshots

This repository's Arduino code and circuit diagram were prepared and
syntax-verified, but the Tinkercad simulation itself was **not run** in the
environment that generated these files. The three simulation screenshots
(`simulation_setup.png`, `led_on.png`, `serial_monitor.png`) are **not**
included, and must be captured by you after building and testing the circuit
in Tinkercad — see `screenshots/README.md` for exact instructions on what to
capture.
