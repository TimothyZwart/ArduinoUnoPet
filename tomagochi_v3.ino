#include <LiquidCrystal.h>
byte crymouth[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001,
  0b11111
};
byte cryright[8] = {
  0b00000,
  0b10000,
  0b00100,
  0b00000,
  0b00010,
  0b00000,
  0b00001,
  0b00000
};
byte cryleft[8] = {
  0b00000,
  0b00001,
  0b00100,
  0b00000,
  0b01000,
  0b00000,
  0b10000,
  0b00000
};
byte death1[8] = {
  0b01111,
  0b10000,
  0b10111,
  0b10101,
  0b10111,
  0b10110,
  0b10101,
  0b00000
};
byte death2[8] = {
  0b11111,
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};
byte death3[8] = {
  0b11110,
  0b00001,
  0b11101,
  0b10101,
  0b11101,
  0b10001,
  0b10001,
  0b00000
};
byte death4[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b11111
};
byte death5[8] = {
  0b00000,
  0b11011,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b11111
};
byte death6[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b11111
};
byte mouthopenside[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b00100,
  0b00100,
  0b00111,
  0b00000
};

byte feedopenmouth[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b10001,
  0b10001,
  0b01110
};

byte smalleye[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte fullfood[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte halffood[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00110,
  0b00011,
  0b00111,
  0b00011,
  0b00111
};

byte gonefood[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};

byte mouthclosedside[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00111,
  0b00111,
  0b00000
};

byte throwup1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b00000,
  0b00000,
  0b00000
};

byte throwup2[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01000,
  0b10000,
  0b00000,
  0b00000
};

byte throwup3[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b01000,
  0b10000,
  0b00000
};

byte throwup4[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00010,
  0b00100,
  0b01000,
  0b10000
};

byte throwup5[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};

byte poop1[8] = {
  0b01010,
  0b10100,
  0b10010,
  0b01000,
  0b00110,
  0b01111,
  0b11111,
  0b11111
};

byte poop2[8] = {
  0b01010,
  0b10010,
  0b01001,
  0b01010,
  0b00110,
  0b01111,
  0b11111,
  0b11111
};

//event timers
unsigned long lastsadtime = 0;
unsigned long sadDelay = 5000;
unsigned long eventtimer = 0;
//event timers

//Tilt Switch
const int switchPin = 7;
int switchState = 0;
//tiltSwitch end

//Setup LCD Screen
int Contrast = 0;
int contrast_pin6 = 6;
int backlight_pin9 = 9;
int brightness = 128;
int column = 0;
int row = 0;
int lastcolumn = 0;

// Buttons Setup
int button1 = 10;
int button2 = 8;
int buttonState = 0;
int buttonState2 = 0;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int buttonStatedo1;
int buttonStatedo2;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
//Buttons End

//Screen state and Pet States
int screenState1 = 0;
int screenState2 = 0;
int sadState = 0;
int sadgrowth = 0;
int sadmax = 15;
int hunger = 20;
int hungerminvalue = 15;
int binarynumber = 0;
unsigned long hungergrowth = 0;
int dirtyState = 0;
int randompoop = 0;
int paceState = 0;
//end of screen pet states

//Pet Movement
unsigned long lastMovementTime = 0;
unsigned long movementDelay = 500;
int movementpattern = 1;
//end Pet movement


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
  analogWrite(contrast_pin6, Contrast);
  analogWrite(backlight_pin9, brightness);
  lcd.begin(16, 2);
  lcd.setCursor (column, row);
  lcd.print("Hello");
  lcd.setCursor (0, 1);
  lcd.print("I am BOB");
  pinMode(backlight_pin9, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(contrast_pin6, OUTPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
  delay(2000);
  column = 6;
  row = 0;
  lcd.setCursor (column, row);
  pinMode(switchPin, INPUT);
}

void loop()
{
  analogWrite(backlight_pin9, brightness); // PWM values from 0 to 255 (0% – 100% duty cycle)
  analogWrite(contrast_pin6, Contrast);
  buttonState = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  switchState = digitalRead(switchPin);
  if (screenState1 == 0) {
    lcd.createChar(6, poop1);
    lcd.createChar(7, poop2);
  }

  if (buttonState != lastButtonState1 && buttonState2 != lastButtonState2 || buttonState2 != lastButtonState2 || buttonState != lastButtonState1) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (buttonState != buttonStatedo1  || buttonState2 != buttonStatedo2) {
      buttonStatedo1 = buttonState;
      buttonStatedo2 = buttonState2;
      if (buttonStatedo1 == HIGH || buttonStatedo2 == HIGH) {
        mainprogram();
      }

    }
  }
  lastButtonState1 = buttonState;
  lastButtonState2 = buttonState2;
  if (screenState1 == 0 && hunger >= 0 && hunger < hungerminvalue && sadgrowth < sadmax) {
    column = 5;
    row = 1;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(xoX)");
  }
  if (screenState1 == 0 && sadgrowth == sadmax) {
    row = 1;
    column = 5;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(>_<)");
  }
  if (screenState1 == 0 && dirtyState == 1) {
    lcd.setCursor(15, 1);
    lcd.print(char(6));
  }

  if (((millis() - eventtimer) > 1000 ) && screenState1 == 0 && hunger > 0 && sadgrowth < sadmax && dirtyState == 0) {
    randompoop = random(100);
    if (randompoop >= 90) {
      poopevent();
    }
    eventtimer = millis();
  }
  if (sadgrowth == sadmax && screenState1 == 0 && millis() - lastsadtime > 2000) {
    sadness();
    lastsadtime = millis();
  }
  if (((millis() - hungergrowth) > 2000 ) && screenState1 == 0 && hunger > 0 && hunger < hungerminvalue && sadgrowth < sadmax) {
    hunger = hunger - 1;
    if (hunger <= 0) {
      death();
    } else {
      feedme();
      hungergrowth = millis();
    }

  }
  if (millis() - lastsadtime > sadDelay && screenState1 == 0 && sadgrowth < sadmax) {
    sadgrowth = sadgrowth + 1;
    lastsadtime = millis();
  }
  if (millis() - hungergrowth > 4000 && screenState1 == 0 && sadgrowth < sadmax && hunger >= hungerminvalue) {
    hunger = hunger - 1;
    hungergrowth = millis();
  }
  if (millis() - lastMovementTime > movementDelay && screenState1 == 0 && sadgrowth < sadmax && hunger >= hungerminvalue) {
    if (dirtyState == 0) {
      movement();
    }
    else {
      pace();
    }
  }
  switchState = digitalRead(switchPin);
  if (switchState == HIGH && screenState1 == 0 && sadgrowth < sadmax) {
    throwup();
  }

}

void mainprogram() {
  if (screenState1 == 3) {
    if (buttonState == LOW && buttonState2 == HIGH)
    {
      if (screenState2 < 3 ) {
        screenState2 = screenState2 + 1;
      } else {
        screenState2 = 0;
      }
      selectscreen();
    }
    if (buttonState == HIGH && buttonState2 == LOW) {
      doscreen();
    }
    return;
  }
  if (screenState1 == 0) {
    if (buttonState == HIGH && buttonState2 == HIGH) {
      contrast();
    }
    if (buttonState == HIGH && buttonState2 == LOW)
    {
      summary();
    }
    if (buttonState == LOW && buttonState2 == HIGH) {
      actions();
    }
    return;
  }
  if (screenState1 == 2) {
    if (buttonStatedo1 == HIGH && buttonStatedo2 == HIGH) {
      reset();
    }
    return;
  }
  if (screenState1 == 1) {
    if (buttonStatedo1 == LOW && buttonStatedo2 == HIGH) {
      lcd.clear();
      lcd.setCursor(column, row);
      screenState1 = 0;
    }
    return;
  }
  if (screenState1 == 4) {}
  if (screenState1 == 8) {
    if (buttonState == HIGH && buttonState2 == LOW) {
      if (buttonState == HIGH)
        {
        brightness = brightness + 32;
        }
      if (brightness >= 256)
      {
      brightness = 0;
      }
    } else if (buttonState == LOW && buttonState2 == HIGH)
    {
      if(Contrast >= 100){
    Contrast = 0;
    }
    else{  
    Contrast = Contrast + 10;
  }
    }
    else if (buttonState == HIGH && buttonState2 == HIGH){
      screenState1 = 0;
      }
  }
}

void feed() {
  lcd.createChar(0, feedopenmouth);
  lcd.createChar(1, smalleye);
  lcd.createChar(2, fullfood);
  lcd.createChar(3, halffood);
  lcd.createChar(4, gonefood);
  row = 1;
  column = 0;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(0_0) ");
  lcd.print(char(2));
  delay(500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( 0_0)");
  lcd.print(char(2));
  delay(500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( ");
  lcd.print(char(1));
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.print(")");
  lcd.print(char(2));
  tone(13, 440, 250); //a
  delay(500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( ");
  lcd.print(char(1));
  lcd.print("-");
  lcd.print(char(1));
  lcd.print(")");
  lcd.print(char(3));
  delay(500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( ");
  lcd.print(char(1));
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.print(")");
  lcd.print(char(3));
  tone(13, 440, 250); //a
  delay(500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( ");
  lcd.print(char(1));
  lcd.print("-");
  lcd.print(char(1));
  lcd.print(")");
  lcd.print(char(4));
  delay (500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( ");
  lcd.print(char(1));
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.print(")");
  lcd.print(char(4));
  tone(13, 440, 250); //a
  delay (500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("( ");
  lcd.print(char(1));
  lcd.print("-");
  lcd.print(char(1));
  lcd.print(")");
  delay(500);
  hunger = hunger + 30;
  hungergrowth = 0;
  if (hunger > 100) {
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(x");
    lcd.print("o");
    lcd.print("x)");
    tone(13, 349, 100); //f
    delay(250);
    lcd.setCursor(column, row);
    lcd.print("(X");
    lcd.print("o");
    lcd.print("X)");
    tone(13, 349, 100); //f
    delay(250);
    lcd.setCursor(column, row);
    lcd.print("(x");
    lcd.print("o");
    lcd.print("x)");
    tone(13, 349, 100); //f
    delay(250);
    lcd.setCursor(column, row);
    lcd.print("(X");
    lcd.print("o");
    lcd.print("X)");
    tone(13, 349, 100); //f
    delay(250);
    death();
  } else {
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, 0);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, 0);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    delay (500);
    screenState1 = 0;
  }
}
void praise() {
  movementpattern = 1;
  screenState1 = 4;
  column = 5;
  row = 1;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(^");
  lcd.print("-");
  lcd.print("^)");
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  lcd.clear();
  lcd.setCursor(column, 0);
  lcd.print("(^");
  lcd.print("-");
  lcd.print("^)");
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(^");
  lcd.print("-");
  lcd.print("^)");
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  lcd.clear();
  lcd.setCursor(column, 0);
  lcd.print("(^");
  lcd.print("-");
  lcd.print("^)");
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  tone(13, 440, 150); //a
  tone(13, 466, 250); //b
  delay(250);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(^");
  lcd.print("-");
  lcd.print("^)");
  delay (500);
  sadgrowth = 0;
  sadState = 0;
  delay(2000);
  screenState1 = 0;
}

void doscreen() {
  if (screenState2 == 0) {
    screenState1 = 0;
  }
  else if (screenState2 == 1) {
    feed();
  }
  else if (screenState2 == 2) {
    praise();
  }
  else if (screenState2 == 3) {
    clean();
  }
}

void clean() {
  screenState1 = 50;
  if (hunger > 0 && hunger < hungerminvalue && sadgrowth < sadmax) {
    column = 5;
    row = 1;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(xoX)");
  }
  else if (screenState1 == 0 && sadgrowth == sadmax) {
    row = 1;
    column = 5;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(>_<)");
  }
  else {
    row = 1;
    column = 5;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(0_0)");
  }
  if (dirtyState == 1) {
    lcd.setCursor(15, 1);
    lcd.print(char(6));
    delay(500);
    lcd.setCursor(15, 1);
    lcd.print(char(7));
    delay(500);
  }
  row = 0;
  column = 0;
  for (int cleaning = 0; cleaning < 16; cleaning++) {
    lcd.setCursor(cleaning, 0);
    lcd.print(">");
    lcd.setCursor(cleaning, 1);
    lcd.print(">");
    tone(13, 440, 50); //a
    delay(50);
  }
  if (dirtyState == 1) {
    row = 1;
    column = 5;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, 0);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, 0);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    tone(13, 440, 150); //a
    tone(13, 466, 250); //b
    delay(250);
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(^");
    lcd.print("-");
    lcd.print("^)");
    delay (500);
  }
  dirtyState = 0;
  screenState1 = 0;
}
void actions() {
  screenState1 = 3;
  screenState2 = 1;
  selectscreen();
}

void selectscreen() {
  if (screenState2 == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1. Feed");
    lcd.setCursor(0, 1);
    lcd.print("Next");
    lcd.setCursor(9, 1);
    lcd.print("Select");
  }
  else if (screenState2 == 2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("2. Praise");
    lcd.setCursor(0, 1);
    lcd.print("Next");
    lcd.setCursor(9, 1);
    lcd.print("Select");
  } else if (screenState2 == 3) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("3. Clean");
    lcd.setCursor(0, 1);
    lcd.print("Next");
    lcd.setCursor(9, 1);
    lcd.print("Select");
  } else if (screenState2 == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("4. Exit");
    lcd.setCursor(0, 1);
    lcd.print("Next");
    lcd.setCursor(9, 1);
    lcd.print("Select");
  }
}

void summary() {
  lastcolumn = column;
  screenState1 = 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  if (sadgrowth >= sadmax && hunger <= hungerminvalue) {
    lcd.print("Pet:Sad & Hungry");
  }
  else if (sadgrowth >= sadmax) {
    lcd.print("Pet:Is Sad");
  }
  else if (hunger <= hungerminvalue) {
    lcd.print("Pet:Is Hungry");
  } else if (dirtyState == 1) {
    lcd.print("Pet:Is Dirty");
  } else {
    lcd.print("Pet:Is Healthy");
  }
  lcd.setCursor(0, 1);
  lcd.print("<<Return");
  column = lastcolumn;
  if (movementpattern == 1) {
    movementpattern = 0;
  } else {
    movementpattern = 1;
  }

}
void throwup() {
  lcd.createChar(0, mouthopenside);
  lcd.createChar(1, mouthclosedside);
  lcd.createChar(2, throwup1);
  lcd.createChar(3, throwup2);
  lcd.createChar(4, throwup3);
  lcd.createChar(5, throwup4);
  lcd.createChar(6, throwup5);
  screenState1 = 7;
  row = 0;
  column = 6;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(1));
  delay(500);
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(0));
  tone(13, 349, 500); //f
  delay(500);
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(0));
  lcd.print(char(2));
  tone(13, 349, 500); //f
  delay(500);
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(0));
  lcd.print(char(3));
  tone(13, 349, 500); //f
  delay(500);
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(0));
  lcd.print(char(4));
  tone(13, 349, 500); //f
  delay(500);
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(0));
  lcd.print(char(5));
  tone(13, 349, 500); //f
  delay(500);
  lcd.setCursor(column, row);
  lcd.print("(0");
  lcd.print(char(1));
  lcd.print(char(6));
  tone(13, 349, 500); //f
  delay(500);
  hunger = hunger - 5;
  sadgrowth = sadmax;
  screenState1 = 0;
}
void reset() {
  screenState1 = 0;
  hunger = 20;
  dirtyState = 0;
  hungergrowth = 0;
  sadgrowth = 0;
  sadState = 0;
  eventtimer = 0;
  lastMovementTime = millis();
  lastDebounceTime = millis();
}
void feedme() {
  if ((hunger > 0) && (hunger < hungerminvalue) && screenState1 == 0 && sadgrowth < sadmax) {
    screenState1 = 50;
    lcd.clear();
    column = 5;
    row = 1;
    lcd.setCursor(column, row);
    lcd.print("(XoX)");
    lcd.setCursor(6, 0);
    lcd.print("FEED ME!");
    lcd.print(hunger);
    tone(13, 349, 750); //f
    delay(1000);
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(xoX)");
    screenState1 = 0;
  }
}
void poopevent() {
  screenState1 = 50;
  lcd.createChar(6, poop1);
  lcd.createChar(7, poop2);
  row = 1;
  column = 5;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(!_!)");
  delay(500);
  row = 1;
  column = 4;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(!_!)");
  tone(13, 440, 100); //a
  delay(100);
  tone(13, 466, 100); //b
  delay(100);
  tone(13, 440, 100); //a
  delay(100);
  delay(200);
  row = 1;
  column = 5;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(!_!)");
  tone(13, 440, 100); //a
  delay(100);
  tone(13, 466, 100); //b
  delay(100);
  tone(13, 440, 100); //a
  delay(100);
  delay(200);
  row = 1;
  column = 6;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(!_!)");
  tone(13, 440, 100); //a
  delay(100);
  tone(13, 466, 100); //b
  delay(100);
  tone(13, 440, 100); //a
  delay(100);
  delay(200);
  row = 1;
  column = 5;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(!_!)");
  tone(13, 440, 100); //a
  delay(100);
  tone(13, 466, 100); //b
  delay(100);
  tone(13, 440, 100); //a
  delay(100);
  delay(200);
  row = 1;
  column = 5;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(0_0)");
  lcd.print(char(6));
  delay(500);
  row = 1;
  column = 5;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(0_0)");
  lcd.print(char(7));
  delay(500);
  row = 1;
  column = 5;
  lcd.clear();
  lcd.setCursor(column, row);
  lcd.print("(0_0)");
  lcd.print(char(6));
  dirtyState = 1;
  delay(500);
  screenState1 = 0;
}
void sadness() {
  if (sadState < 10) {
    screenState1 = 50;
    lcd.createChar(0, crymouth);
    lcd.createChar(1, cryleft);
    lcd.createChar(2, cryright);
    sadState = sadState + 1;
    row = 1;
    column = 5;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print("(>_<)");
    delay(500);
    column = 4;
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print(char(1));
    lcd.print("(>");
    lcd.print(char(0));
    lcd.print("<)");
    lcd.print(char(2));
    tone(13, 349, 250);
    delay(250);
    tone(13, 349, 250);
    delay(250);
    tone(13, 349, 250);
    screenState1 = 0;
  }
  else {
    death();
  }
}
void death() {
  screenState1 = 2;
  lcd.createChar(3, death1);
  lcd.createChar(4, death2);
  lcd.createChar(5, death3);
  lcd.createChar(6, death4);
  lcd.createChar(7, death5);
  lcd.createChar(0, death6);
  lcd.clear();
  row = 0;
  column = 6;
  lcd.setCursor(column, row);
  lcd.print(char(3));
  lcd.print(char(4));
  lcd.print(char(5));
  row = 1;
  column = 0;
  lcd.setCursor(column, row);
  lcd.print("______");
  lcd.print(char(6));
  lcd.print(char(7));
  lcd.print(char(0));
  lcd.print("_______");
  column = 5;
  tone(13, 349, 500); //f
  delay(500);
  tone(13, 349, 500); //f
  delay(500);
  tone(13, 466, 500); //b
  delay(500);
  tone(13, 349, 500); //f
  delay(500);
  tone(13, 466, 500); //b
  tone(13, 349, 750); //f
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Click Both Btns");
  lcd.setCursor(0, 1);
  lcd.print("To Revive");

  if (movementpattern == 1) {
    movementpattern = 0;
  } else {
    movementpattern = 1;
  }
}

void contrast() {
  screenState1 = 8;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Con       Bright");
  lcd.setCursor(1, 0);
}
void movement() {
  if (movementpattern == 1) {
    if (column < 16) {
      column = column + 1;
    }
    else {
      column = -4;
    }
  } else {
    if (column > -4) {
      column = column - 1;
    }
    else {
      column = 16;
    }
  }
  lcd.clear();
  if (column == -4) {
    lcd.setCursor(0, row);
    lcd.print(")");
  } else if (column == -3) {
    lcd.setCursor(0, row);
    lcd.print("0)");
  } else if (column == -2) {
    lcd.setCursor(0, row);
    lcd.print("_0)");
  }
  else if (column == -1) {
    lcd.setCursor(0, row);
    lcd.print("0_0)");
  }
  else if (column >= 0  && column < 12 ) {
    lcd.setCursor(column, row);
    lcd.print("(0_0)");
  }
  else if (column == 12 ) {
    lcd.setCursor(column, row);
    lcd.print("(0_0");
  }
  else if (column == 13 ) {
    lcd.setCursor(column, row);
    lcd.print("(0_");
  }
  else if (column == 14 ) {
    lcd.setCursor(column, row);
    lcd.print("(0");
  }
  else if (column == 15 ) {
    lcd.setCursor(column, row);
    lcd.print("(");
  }
  else if (column == 16 ) {
    lcd.setCursor(column, row);
    lcd.print("");
    if (row == 0) {
      row = 1;
    }
    else {
      row = 0;
    }
  }
  lastMovementTime = millis();
}
void pace() {
  if (paceState == 0) {
    lcd.clear();
    row = 1;
    column = 5;
    lcd.setCursor(column, row);
    lcd.print("(0_0)");
    lcd.setCursor(15, 1);
    lcd.print(char(6));
    paceState = paceState = 1;
  } else if (paceState == 1) {
    lcd.clear();
    row = 1;
    column = 6;
    lcd.setCursor(column, row);
    lcd.print("(0_0)");
    lcd.setCursor(15, 1);
    lcd.print(char(6));
    paceState = paceState = 0;
  }
  lastMovementTime = millis();
}


