# Arduino Multiplexing Scoreboard Project

## Overview
This repository is dedicated to an Arduino-based multiplexing scoreboard project. The project uses 7-segment displays, CD4511 7-segment decoders, resistors, NPN transistors (BJTs), and pushbuttons to simulate a functional scoreboard. It demonstrates how multiplexing can be used to create dynamic, interactive display systems.

## Project Description
The aim of this project is to create a scoreboard that can be used in games or sports events. It features four 7-segment displays controlled using CD4511 decoders and multiplexing techniques. Users can interact with the scoreboard using pushbuttons to increase or decrease scores, or reset them altogether. This setup provides a practical and educational example of how scoreboards function and can be modified.

## Circuit Diagram
Below is the circuit diagram for the Multiplexing Scoreboard:

![_Taisir- Multiplexing Scoreboard Project](https://github.com/taisirhassan/Multiplexing-Scoreboard-Project/assets/85134103/69cc2b2d-bb75-43ce-b5d2-8743079e03ba)

## Components
- Arduino (Uno, Mega, etc.)
- 4 x 7-Segment Displays
- CD4511 7-Segment Decoders
- Resistors
- NPN Transistors (BJTs)
- Pushbuttons
- Breadboard and Jumper Wires

## Code Structure
- `main.ino`: The main Arduino sketch for the scoreboard. This file contains the code for handling display multiplexing, button inputs, and score logic.

## Setup and Installation
### Hardware Setup
1. **Assemble the Circuit**: Construct the circuit on a breadboard following the provided diagram. Ensure correct placement of the 7-segment displays, CD4511 decoders, transistors, resistors, and pushbuttons.
2. **Verify Connections**: Double-check all connections for consistency with the circuit diagram.

### Software Installation
1. **Arduino IDE**: Ensure the Arduino IDE is installed on your computer.
2. **Load the Sketch**: Open the `main.ino` file in the Arduino IDE.
3. **Upload to Arduino**: Connect your Arduino to the computer, select the appropriate board and port in the IDE, and then upload the sketch.

## Testing the Project
After uploading the sketch to the Arduino, test the functionality by pressing the pushbuttons to increment, decrement, or reset the scores displayed on the 7-segment displays. Ensure that the multiplexing and button logic are working as intended.

## License
This project is open-source and available for use and modification under the MIT License.

