// *VARIABLE DECLARATIONS*

// *Delays*
#define DELAY_1 10
#define DELAY_2 15
#define delayTime 50

// *Colors*
#define RED 50,0,0
#define ORANGE 247,84,2
#define YELLOW 247,243,2
#define GREEN 0,50,0
#define BLUE 42,3,181
#define INDIGO 127,3,181
#define VIOLET 186,0,148
#define BLACK 0,0,0

// *Pins*
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int buttonPin = 8;

#define COMMON_ANODE

// *Button*
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW; 
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 200;    // the debounce time; increase if the output flickers

// *Patterns*
int nPatterns = 5; //number of patterns
int lightPattern = 1; //current pattern

//==================================
// *Setup*
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);    
  pinMode(buttonPin, INPUT);
  setColourRgb(0,0,0);
  digitalWrite(buttonPin, HIGH);  // button pin is HIGH, so it drops to 0 if pressed
}

//=================================================
// *Animation Programs*
 
void Solid(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void Strobe2 (int red1, int green1, int blue1, int red2, int green2, int blue2)
{
 #ifdef COMMON_ANODE
    red1 = 255 - red1;
    green1 = 255 - green1;
    blue1 = 255 - blue1;
    red2 = 255 - red2;
    green2 = 255 - green2;
    blue2 = 255 - blue2;
  #endif  
  analogWrite(redPin, red1);
  analogWrite(greenPin, green1);
  analogWrite(bluePin, blue1);  
  delay(15);
  analogWrite(redPin, red2);
  analogWrite(greenPin, green2);
  analogWrite(bluePin, blue2);  
  delay(15);
}

void Strobe3 (int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3)
{
 #ifdef COMMON_ANODE
    red1 = 255 - red1;
    green1 = 255 - green1;
    blue1 = 255 - blue1;
    red2 = 255 - red2;
    green2 = 255 - green2;
    blue2 = 255 - blue2;
    red3 = 255 - red3;
    green3 = 255 - green3;
    blue3 = 255 - blue3;
  #endif  
  analogWrite(redPin, red1);
  analogWrite(greenPin, green1);
  analogWrite(bluePin, blue1);  
  delay(10);
  analogWrite(redPin, red2);
  analogWrite(greenPin, green2);
  analogWrite(bluePin, blue2);  
  delay(15);
  analogWrite(redPin, red3);
  analogWrite(greenPin, green3);
  analogWrite(bluePin, blue3); 
  delay(10);
  
}

void RainbowStrobe (int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3, 
int red4, int green4, int blue4, int red5, int green5, int blue5, int red6, int green6, int blue6, int red7, int green7,
int blue7)
{
 #ifdef COMMON_ANODE
    red1 = 255 - red1;
    green1 = 255 - green1;
    blue1 = 255 - blue1;
    red2 = 255 - red2;
    green2 = 255 - green2;
    blue2 = 255 - blue2;
    red3 = 255 - red3;
    green3 = 255 - green3;
    blue3 = 255 - blue3;
    red4 = 255 - red4;
    green4 = 255 - green4;
    blue4 = 255 - blue4;
    red5 = 255 - red5;
    green5 = 255 - green5;
    blue5 = 255 - blue5;
    red6 = 255 - red6;
    green6 = 255 - green6;
    blue6 = 255 - blue6;
    red7 = 255 - red7;
    green7 = 255 - green7;
    blue7 = 255 - blue7;
  #endif  
  analogWrite(redPin, red1);
  analogWrite(greenPin, green1);
  analogWrite(bluePin, blue1);  
  delay(10);
  analogWrite(redPin, red2);
  analogWrite(greenPin, green2);
  analogWrite(bluePin, blue2);  
  delay(15);
  analogWrite(redPin, red3);
  analogWrite(greenPin, green3);
  analogWrite(bluePin, blue3); 
  delay(10);
  analogWrite(redPin, red4);
  analogWrite(greenPin, green4);
  analogWrite(bluePin, blue4);  
  delay(15);
  analogWrite(redPin, red5);
  analogWrite(greenPin, green5);
  analogWrite(bluePin, blue5);  
  delay(10);
  analogWrite(redPin, red6);
  analogWrite(greenPin, green6);
  analogWrite(bluePin, blue6); 
  delay(15);
  analogWrite(redPin, red7);
  analogWrite(greenPin, green7);
  analogWrite(bluePin, blue7);  
  delay(10);
}


void Rainbow() 
{
unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(30);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }

//==================================

// *Main Program Loop*

void loop() {
  // read that state of the pushbutton value;
  int reading = digitalRead(buttonPin);
// If the switch changed, due to noise or pressing:
  if (buttonState != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  // whatever the reading is at, it's been there for longer than the debounce
  // delay, so take it as the actual current state:
  if ((millis() - lastDebounceTime) > debounceDelay) {

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        
        // increment the pattern by 1
        lightPattern = lightPattern + 1;
      }
    }
  }



 //when you go over the number of patterns, reset the pattern loop
  if (lightPattern > nPatterns) lightPattern = 1;
  lastButtonState = reading;

// *Animation Parameters*
  switch(lightPattern) {
  case 1:
      Strobe2(GREEN,YELLOW);  // 
      break;
  case 2:
      Strobe3(INDIGO,GREEN,ORANGE);  // 
      break; 
  case 3:
      RainbowStrobe(RED,ORANGE,YELLOW,GREEN,BLUE,INDIGO,VIOLET);
      break;
  case 4:
      Solid(GREEN);
      break;
  case 5:
      Rainbow();
      break;
  }
}

