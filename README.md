# HM-LC-Sw4-Ba-PCB-Switch-Extension
Toggle the outputs of the HM-LC-Sw4-Ba-PCB w/ external Switches using an Arduino as interface

The HM-LC-Sw4-Ba-PCB is a 4 channel actuator for the Homematic system made by eq-3.

The Arduino monitors up to 7 switches (S1 to S7) on pins 2 to 5 and 10 to 12. The switches pull the pins to GND or leave them floating, which brings them to VCC through the internal pull-up resistors. Output pins 6 to 9 are floating and will be pulled to GND for approximately 100 milliseconds once a change in state of one of the corresponding switches is detected, thus simulation a short keypress on the HM-LC-Sw4-Ba-PCB. After a change in state has been detected, all actions on the corresponding output will be blocked for approximately 250 milliseconds.

Change in state of S1 (on pin 2) or S5 (on pin 10) toggles output 1 (on pin 6)
Change in state of S2 (on pin 3) or S6 (on pin 11) toggles output 2 (on pin 7)
Change in state of S3 (on pin 4) or S7 (on pin 12) toggles output 3 (on pin 8)
Change in state of S4 (on pin 5) toggles output 4 (on pin 9)
Each switch / output is optional

Please see "[/Schematics/wiring.sch](/Schematics/wiring.sch)" or "[/Schematics/wiring.png](/Schematics/wiring.png)" for a wiring diagram.
