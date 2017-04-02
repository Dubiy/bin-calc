/*
byte-shield
right-side connectors
SHLD - Arduino (8)
CLK  - Arduino (12)
CE   - Arduino (9)
+5V  - Arduino (+5V)
GND  - Arduino (GND)
DATA - Arduino (11)
*/

/*
output-shield
right-side connectors

DATA  - Arduino (7)
CLOCK - Arduino (10)
LATCH - Arduino (6)
+5V   - Arduino (+5V)
GND   - Arduino (GND)
*/

const int SHIFT_IN_DATA = 11; // 9  Connect Pin 11 to SER_OUT (serial data out)
const int SHIFT_IN_SHLD = 8; // 1 Connect Pin 8 to SH/!LD (shift or active low load)
const int SHIFT_IN_CLK = 12; // 2 Connect Pin 12 to CLK (the clock that times the shifting)
const int SHIFT_IN_CE = 9; // 15 Connect Pin 9 to !CE (clock enable, active low)

const int SHIFT_OUT_LATCH =  6;
const int SHIFT_OUT_CLOCK =  10;
const int SHIFT_OUT_DATA =  7;



void setup() {
  Serial.begin(115200);
  Serial.println("start");

  pinMode(SHIFT_IN_DATA, INPUT);
  pinMode(SHIFT_IN_SHLD, OUTPUT);
  pinMode(SHIFT_IN_CLK, OUTPUT);
  pinMode(SHIFT_IN_CE, OUTPUT);
  digitalWrite(SHIFT_IN_CLK, HIGH);
  digitalWrite(SHIFT_IN_SHLD, HIGH);

  pinMode(SHIFT_OUT_LATCH, OUTPUT);
  pinMode(SHIFT_OUT_CLOCK, OUTPUT);
  pinMode(SHIFT_OUT_DATA, OUTPUT);
}

byte byte1 = 0,
     byte2 = 0;
byte operation = 0;


void loop() {
  byte1 = read_shift_regs();

  Serial.println("\nThe incoming values of the shift register are: ");
  Serial.print("BITS : ");
  Serial.print(byte1);
  Serial.print(" ");
  print_byte(byte1);

  delay(300);



    // for (int i = 0; i < 256; i++) {

      // digitalWrite(SHIFT_OUT_LATCH, LOW);
      shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, byte1);
      shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, byte1);
      // shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, i);
      // digitalWrite(SHIFT_OUT_LATCH, HIGH);
      // delay(300);

      // digitalWrite(SHIFT_OUT_LATCH, LOW);
      // shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, 0);
      // shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, 0);
      // // shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, i);
      // digitalWrite(SHIFT_OUT_LATCH, HIGH);
      // delay(500);
    // }


//
//     delay(300);
//
// digitalWrite(SHIFT_OUT_LATCH, LOW);
//
// shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, 0);
// shiftOut(SHIFT_OUT_DATA, SHIFT_OUT_CLOCK, MSBFIRST, 0);
// digitalWrite(SHIFT_OUT_LATCH, HIGH);
//
//



}

// This code is intended to trigger the shift register to grab values from it's A-H inputs
byte read_shift_regs()
{
  byte the_shifted = 0;  // An 8 bit number to carry each bit value of A-H

  // Trigger loading the state of the A-H data lines into the shift register
  digitalWrite(SHIFT_IN_SHLD, LOW);
  delayMicroseconds(5); // Requires a delay here according to the datasheet timing diagram
  digitalWrite(SHIFT_IN_SHLD, HIGH);
  delayMicroseconds(5);

  // Required initial states of these two pins according to the datasheet timing diagram
  pinMode(SHIFT_IN_CLK, OUTPUT);
  pinMode(SHIFT_IN_DATA, INPUT);
  digitalWrite(SHIFT_IN_CLK, HIGH);
  digitalWrite(SHIFT_IN_CE, LOW); // Enable the clock

  // Get the A-H values
  the_shifted = shiftIn(SHIFT_IN_DATA, SHIFT_IN_CLK, MSBFIRST);
  digitalWrite(SHIFT_IN_CE, HIGH); // Disable the clock

  return the_shifted;

}

// A function that prints all the 1's and 0's of a byte, so 8 bits +or- 2
void print_byte(byte val)
{
    byte i;
    for(byte i=0; i<=7; i++)
    {
      Serial.print(val >> i & 1, BIN); // Magic bit shift, if you care look up the <<, >>, and & operators
    }
    Serial.print("\n"); // Go to the next line, do not collect $200
}


/*const int SHIFT_IN_LATCH =  13;
const int SHIFT_IN_CLOCK =  12;
const int SHIFT_IN_DATA =  11;

*/
