#define debug 0

byte lastInputStates;
byte outcounter[] = {
  255, 255, 255, 255
};

void setup() {
  // put your setup code here, to run once:
  if(debug) Serial.begin(115200);
  pinMode(2,  INPUT_PULLUP);
  pinMode(3,  INPUT_PULLUP);
  pinMode(4,  INPUT_PULLUP);
  pinMode(5,  INPUT_PULLUP);
  pinMode(6,  INPUT);
  pinMode(7,  INPUT);
  pinMode(8,  INPUT);
  pinMode(9,  INPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  lastInputStates = getInputStates();
}

void loop() {
  // put your main code here, to run repeatedly:
  byte currentInputStates = getInputStates();
  for(int i=0; i<4; i++) {
    if(outcounter[i] >= 250) {
      if((lastInputStates^currentInputStates)&1<<i || (lastInputStates^currentInputStates)&1<<i+4) {
        if(debug) Serial.println("Pin " + String(2+i) + " or Pin " + String(10+i) + " changed!");
        if(debug) Serial.println("Pin " + String(6+i) + " out!");
        pinMode(6+i, OUTPUT);
        outcounter[i] = 0;
      }
    } else {
        if(outcounter[i] == 100) {
          pinMode(6+i, INPUT);
          if(debug) Serial.println("Pin " + String(6+i) + " in!");
        }
        outcounter[i]++;
    }
  }
  lastInputStates = currentInputStates;
  delay(1);
}

byte getInputStates() {
  byte state = 0;
  state |= digitalRead(2);
  state |= digitalRead(3)  << 1;
  state |= digitalRead(4)  << 2;
  state |= digitalRead(5)  << 3;
  state |= digitalRead(10) << 4;
  state |= digitalRead(11) << 5;
  state |= digitalRead(12) << 6;
  return state;
}

