/*
   Name: Taisir Hassan
   Teacher: Mr. Gunby TDR4M1
   Date: January. 21, 2021
   Project: Multiplexing Scoreboard Project
   Description: Using Multiplexing, buttons, and a 7-segment display,
   I will attempt to simulate how a scoreboard can and will work and modify.
   With options to add to the score, reset all scores, or decrease scores.
*/
// Global Variables
int input[] {2, 3, 4, 5}; // Array with input pin values
int input2[] {6, 7, 8, 9}; // Array with more input pin values
int dig2[] {A1, A2}; // Array with analog values
int dig[] {1, A0}; // Array with analog pin values
int puls[] {10, 11, 12, 13, A5}; // Array representing pins which will incorporate pulse command
int y = 0, x = 0; // these 3 lines represent integers for different x and y values
int y1 = 0, y2 = 0;
int x1 = 0, x2 = 0;
// Note arrays range starting from 0, meaning if 0 is displayed, it represents the first number in the array list
void setup() { // the setup function runs once when you press reset or power the board
  for (int i = 0; i < 4; i++) { // runs for loop for value 0, where if it is less than 4, it increases in an increment of 1
    pinMode(input[i], OUTPUT); // intializes the values of the array for both inputs as an output
    pinMode(input2[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) { // runs for loop for value zero, for analog pin values, where if it is less than 2, it increases by increments of 1
    pinMode(dig[i], OUTPUT); // initializes the values of the analog input for both arrays as output
    pinMode(dig2[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++) { // runs for loop for value 0, where if it is less than 5, it increases incrementally
    pinMode(puls[i], INPUT); // initializes the value of pulse pins as inputs
  }
}

void loop() {  // the loop function runs over and over again forever
  if (digitalRead(puls[0]) == HIGH) { // if the 0 value from the pulse array is on the y int value increases
    y++;
    while (digitalRead(puls[0]) == HIGH) { // this will loop continuously over and over until it reaches its upper bound
      /*bound*/
    }
    y1 = y / 10; // the y1 value is y divided by 10
    y2 = y % 10; // the y2 value is y mod of 10
    number2(y1, 0);
    delay(50);
    number2(y2, 1);
    delay(50);
  }
  else if (digitalRead(puls[1]) == HIGH) { // else if it reads the first value of the array as on, y will decrease incrementally
    y--;
    if (y < 0) // if y value is less than 0, y will be zero on the display
      y = 0;
    while (digitalRead(puls[1]) == HIGH) { // loops continuously until it reaches its upper bound
      /*bound*/
    }
    y1 = y / 10; // the y1 value is y divided by 10
    y2 = y % 10; // the y2 value is y mod of 10
    number2(y1, 0);
    delay(50);
    number2(y2, 1);
    delay(50);
  }
  // The same else if will run for the 3rd value of the array except the x value will increase incrementally, going to a upper bound
  else if (digitalRead(puls[2]) == HIGH) {
    x++;
    while (digitalRead(puls[2]) == HIGH) {
      /*bound*/
    }
    x1 = x / 10;  //Same calculatiions as y-values
    x2 = x % 10;
    number(x1, 0);
    delay(50);
    number(x2, 1);
    delay(50);
  }
  // The same else if will run for the 4th value of the array except the x value will decrease incrementally, going to a lower bound
  else if (digitalRead(puls[3]) == HIGH) {
    x--;
    if (x < 0)
      x = 0;
    while (digitalRead(puls[3]) == HIGH) {
      /*bound*/
    }
    x1 = x / 10;
    x2 = x % 10;
    number(x1, 0);
    delay(50);
    number(x2, 1);
    delay(50);
  }
  // the else if runs for the 5th value of the pulse array and if it is on it goes to the bound
  else if (digitalRead(puls[4]) == HIGH) {
    while (digitalRead(puls[4]) == HIGH) {
      /*bound*/
    }
    y = 0; // for this else if, y =0, x =0, y1 would be y/10, and y2 would be y mod of 10
    x = 0;
    y1 = y / 10;
    y2 = y % 10;
    number2(y1, 0);
    delay(100);
    number2(y2, 1);
    delay(100);
    x1 = x / 10; // x1 would be x/10, and x2 would equal x mod of 10
    x2 = x % 10;
    number(x1, 0);
    delay(50);
    number(x2, 1);
    delay(50);
  }
  else {          // depending on button presses, it will output different int values
    number2(y1, 0);
    delay(50);
    number2(y2, 1);
    delay(50);
    number(x1, 0);
    delay(50);
    number(x2, 1);
    delay(50);
  }

}


// The first board on the breadboard on top
void number2(int n, int k) { // int n and int k will represent values in the if statements below for number2
  if (k == 0) {    // if int k is 0, the digital array pin's first value will be on, while the 2nd one would be off
    digitalWrite(dig[0], HIGH);
    digitalWrite(dig[1], LOW);
  }
  if (k == 1) { // if int k is 0, the digital array pin's first value will be off, while the 2nd one would be on
    digitalWrite(dig[0], LOW);
    digitalWrite(dig[1], HIGH);
  }
  if (n == 0) {   // if int n is 0, running a for loop, the input2 array would be off
    for (int i = 0; i < 4; i++)
      digitalWrite(input2[i], LOW);
  }
  if (n == 1) { //if int n is 1, the input 2 array's first value would be on, then it runs a for loop where all the values after would be off
    digitalWrite(input2[0], HIGH);
    for (int i = 1; i < 4; i++)
      digitalWrite(input2[i], LOW);
  }
  if (n == 2) { // if int n is 2, the input2 array's 1st value would be off, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input2[0], LOW);
    digitalWrite(input2[1], HIGH);
    digitalWrite(input2[2], LOW);
    digitalWrite(input2[3], LOW);
  }
  if (n == 3) {  // if int n is 3, the input2 array's 1st value would be on, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input2[0], HIGH);
    digitalWrite(input2[1], HIGH);
    digitalWrite(input2[2], LOW);
    digitalWrite(input2[3], LOW);
  }
  if (n == 4) {  // if int n is 4, the input2 array's 1st value would be off, the 2nd would be off, the 3rd would be on and 4th would be off
    digitalWrite(input2[0], LOW);
    digitalWrite(input2[1], LOW);
    digitalWrite(input2[2], HIGH);
    digitalWrite(input2[3], LOW);
  }
  if (n == 5) {  // if int n is 5, the input2 array's 1st value would be off, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input2[0], HIGH);
    digitalWrite(input2[1], LOW);
    digitalWrite(input2[2], HIGH);
    digitalWrite(input2[3], LOW);
  }
  if (n == 6) {  // if int n is 6, the input2 array's 1st value would be off, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input2[0], LOW);
    digitalWrite(input2[1], HIGH);
    digitalWrite(input2[2], HIGH);
    digitalWrite(input2[3], LOW);
  }
  if (n == 7) {  // if int n is 7, the input2 array's 1st value would be on, the 2nd would be on, the 3rd would be on, and 4th would be off
    digitalWrite(input2[0], HIGH);
    digitalWrite(input2[1], HIGH);
    digitalWrite(input2[2], HIGH);
    digitalWrite(input2[3], LOW);
  }
  if (n == 8) {  // if int n is 8, the input2 array's 1st value would be off, the 2nd would be off, the 3rd and 4th would be on
    digitalWrite(input2[0], LOW);
    digitalWrite(input2[1], LOW);
    digitalWrite(input2[2], LOW);
    digitalWrite(input2[3], HIGH);
  }
  if (n == 9) {  // if int n is 9, the input2 array's 1st value would be on, the 2nd would be off, the 3rd would be off, and 4th would be on
    digitalWrite(input2[0], HIGH);
    digitalWrite(input2[1], LOW);
    digitalWrite(input2[2], LOW);
    digitalWrite(input2[3], HIGH);
  }
}
// This represents the 2nd board on the bottom breadboard
void number(int n, int k) {  // int n and int k will represent values in the if statements below for void number
  if (k == 0) { // if int k is 0, the digital2 array pin's first value will be on, while the 2nd one would be off
    digitalWrite(dig2[0], HIGH);
    digitalWrite(dig2[1], LOW);
  }
  if (k == 1) {  // if int k is 0, the digital2 array pin's first value will be off, while the 2nd one would be on
    digitalWrite(dig2[0], LOW);
    digitalWrite(dig2[1], HIGH);
  }
  if (n == 0) {  // if int n is 0, running a for loop, the input array would be off
    for (int i = 0; i < 4; i++)
      digitalWrite(input[i], LOW);
  }
  if (n == 1) { //if int n is 1, the input array's first value would be on, then it runs a for loop where all the values after would be off
    digitalWrite(input[0], HIGH);
    for (int i = 1; i < 4; i++)
      digitalWrite(input[i], LOW);
  }
  if (n == 2) {  // if int n is 2, the input array's 1st value would be off, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input[0], LOW);
    digitalWrite(input[1], HIGH);
    digitalWrite(input[2], LOW);
    digitalWrite(input[3], LOW);
  }
  if (n == 3) {  // if int n is 3, the input array's 1st value would be on, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input[0], HIGH);
    digitalWrite(input[1], HIGH);
    digitalWrite(input[2], LOW);
    digitalWrite(input[3], LOW);
  }
  if (n == 4) {  // if int n is 4, the input array's 1st value would be off, the 2nd would be off, the 3rd would be on and 4th would be off
    digitalWrite(input[0], LOW);
    digitalWrite(input[1], LOW);
    digitalWrite(input[2], HIGH);
    digitalWrite(input[3], LOW);
  }
  if (n == 5) {  // if int n is 5, the input array's 1st value would be off, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input[0], HIGH);
    digitalWrite(input[1], LOW);
    digitalWrite(input[2], HIGH);
    digitalWrite(input[3], LOW);
  }
  if (n == 6) {  // if int n is 6, the input array's 1st value would be off, the 2nd would be on, and the 3rd and 4th would be off
    digitalWrite(input[0], LOW);
    digitalWrite(input[1], HIGH);
    digitalWrite(input[2], HIGH);
    digitalWrite(input[3], LOW);
  }
  if (n == 7) {  // if int n is 7, the input array's 1st value would be on, the 2nd would be on, the 3rd would be on, and 4th would be off
    digitalWrite(input[0], HIGH);
    digitalWrite(input[1], HIGH);
    digitalWrite(input[2], HIGH);
    digitalWrite(input[3], LOW);
  }
  if (n == 8) { // if int n is 8, the input array's 1st value would be off, the 2nd would be off, the 3rd and 4th would be on
    digitalWrite(input[0], LOW);
    digitalWrite(input[1], LOW);
    digitalWrite(input[2], LOW);
    digitalWrite(input[3], HIGH);
  }
  if (n == 9) {  // if int n is 9, the input array's 1st value would be on, the 2nd would be off, the 3rd would be off, and 4th would be on
    digitalWrite(input[0], HIGH);
    digitalWrite(input[1], LOW);
    digitalWrite(input[2], LOW);
    digitalWrite(input[3], HIGH);
  }
}