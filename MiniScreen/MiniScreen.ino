#include <TinyWireM.h>
#include <Tiny4kOLED.h>

const int BTN1 = 1;
const int BTN2 = 4;

int lastPress1 = 0;
int lastPress2 = 0;

boolean lastButtonState1 = LOW;
boolean lastButtonState2 = LOW;

int s1;
int s2;

void setup() {
  // put your setup code here, to run once
  //  pinMode(BTN1, INPUT);
  //  pinMode(BTN2, INPUT);

  oled.begin();

  // Two fonts are supplied with this library, FONT8X16 and FONT6X8
  oled.setFont(FONT8X16);
  oled.clear();
  oled.on();

  // Switch the half of RAM that we are writing to, to be the half that is non currently displayed
  oled.switchRenderFrame();
}

void loop() {
  s1 = digitalRead(BTN1);
  if (s1 == HIGH && s1 != lastButtonState1 && millis() > lastPress1 + 50) {
    lastButtonState1 = s1;
    lastPress1 = millis();
  }

  s2 = digitalRead(BTN2);
  if (s2 == HIGH && s2 != lastButtonState2 && millis() > lastPress2 + 50) {
    lastButtonState2 = s2;
    lastPress2 = millis();
  }

  updateDisplay();
}

void updateDisplay() {
  // Clear the half of memory not currently being displayed.
  oled.clear();

  // Position the text cursor
  // In order to keep the library size small, text can only be positioned
  // with the top of the font aligned with one of the four 8 bit high RAM pages.
  // The Y value therefore can only have the value 0, 1, 2, or 3.
  // usage: oled.setCursor(X IN PIXELS, Y IN ROWS OF 8 PIXELS STARTING WITH 0);
  oled.setCursor(0, 2);

  // Write the number of milliseconds since power on.
  oled.print(s1);

  oled.setCursor(16, 2);
  oled.print(s2);

  // Swap which half of RAM is being written to, and which half is being displayed.
  // This is equivalent to calling both switchRenderFrame and switchDisplayFrame.
  oled.switchFrame();
}
