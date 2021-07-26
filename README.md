# rp-pico-tlc5940
Example code for how to use a tlc5940 chip with the raspberry pi pico

Requires:
  Pins 1-5 (can be changed manually, but must be consecutive)
  PIO0 (can not run concurently with other programs even though it only uses SM0)

Supports:
  Gray Scale Output (12 bit, 16 channel)
  Encoding

Does not currently support:
  Dot Correction
  Varied Refresh Rates (although it is not to complex to change manually)
  LOD: Led Open Detection
  TEF: Thermal Error Flag
  
Pinout-RP-Pico:
  GPIO 1 --> SIN
  GPIO 2 --> SCLK
  GPIO 3 --> BLANK
  GPIO 4 --> XLAT
  GPIO 5 --> GSCLK
  3.3v   --> Vsys
  GND    --> GND
  
Pinout-tlc5940:
  VPRG  --> GND
  VCC   --> Vsys
  DCPRG --> Vsys
  GND   --> GND
  IREF  --> R1 --> GND (R1 sets current limmiting, 1k ohm, reference datasheeet for other values)
  
  Vsys --> c1&c2 --> GND (decoupling capacitors, not strictly necessary but highly recomended)
  
  
If using to controll leds connect the cathode of the led to the outputs of the tlc5940
  
