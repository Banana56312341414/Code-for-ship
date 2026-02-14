# Arduino Morse Code Translator

## Description
This Arduino project allows you to translate text to Morse code and vice versa using buttons and the Serial Monitor. You can type a message in the Serial Monitor to see it in Morse code or input Morse code using a button to get the text output.

## Demo
You can try the project live if uploaded to your Arduino:  
*Open the Serial Monitor at 9600 baud rate to interact with it.*

## Features
- Translate letters and numbers to Morse code.
- Input Morse code using a button for dots and dashes.
- LED indicator shows button presses.
- Print current message and translated text to Serial Monitor.

## How to Use
1. Connect your Arduino and upload the sketch.
2. Open the Serial Monitor at 9600 baud.
3. Type any letter or number to see its Morse code output.
4. Press the **Start/Stop button** to activate Morse input mode.
5. Use the **Input button**: short press = dot, long press = dash.
6. Press the **Send button** to translate the Morse code to text.

## Circuit
- Pin 6 → Start/Stop button (INPUT_PULLUP)
- Pin 7 → Send button (INPUT_PULLUP)
- Pin 8 → LED output
- Pin 9 → Input button (INPUT_PULLUP)
- All buttons connected with pull-down logic handled via INPUT_PULLUP.
