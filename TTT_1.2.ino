#include <IRremote.h>  //library for IR Remote and IR Receiver (IR = Infra-RED)


#define Interval_MaxCounter    65536  //intervalspeed interrupt
#define Interval_200ms      12500


int shiftPin = 11;    //Initialisation of Shift-Register
int storePin = 12;
int dataPin = 13;
int wechselPin = 8;
int speicherPin = 9;
int datenPin = 10;
int wPin = 5;
int sPin = 6;
int dPin = 7;

int a;  // Initialisation of variables for RED-LED a=1
int b; // b=2
int c; // c=3
int d; // d=4
int e; // e=5
int f; // f=6
int g; // g=7
int h; // h=8
int s; // s=9
  
int t;  // Initialisation of variables for GREEN-LED t=1
int u; // u=2
int l; // l=3
int m; // m=4
int n; // n=5
int o; // o=6
int p; // p=7
int q; // q=8
int r; // r=9
int xyz;
int greengui;
int redgui;
int playeronegui;
int playertwogui;
int pause = 1000; //Intervall-Delay
int buzzer = 3;  //Initialisation of Buzzers
int PlayerOne[8] = {0, 1, 0, 0, 0, 0, 0, 1}; //7Segment display Player one LED Array
int PlayerTwo[8] = {0, 0, 1, 1, 1, 0, 1, 1}; //7Segment display Player Two LED Array
int Reset[8] = {0,0,0,0,0,0,0,0}; //7Segment display Reset LED Array, turn all LED off

IRrecv sensor(2);  // Receive IR Signals at Pin 2

void setup()
{
Serial.begin(9600);
pinMode(shiftPin, OUTPUT);  //Outputsetting of Shift-Register Pins and Buzzer
pinMode(storePin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(wechselPin, OUTPUT);
pinMode(speicherPin, OUTPUT);
pinMode(datenPin, OUTPUT);
pinMode(wPin, OUTPUT);
pinMode(sPin, OUTPUT);
pinMode(dPin, OUTPUT);
pinMode(buzzer, OUTPUT);
sensor.enableIRIn();  // activate sensor-receive 
a = 0;  //variables sets at point of start all LED off
b = 0;
c = 0;
d = 0;
e = 0;
f = 0;
g = 0;
h = 0;
s = 0;
t = 0;
u = 0;
l = 0;
m = 0;
n = 0;
o = 0;
p = 0;
q = 0;
r = 0;
xyz = 0;
greengui = 0;
redgui = 0;
playeronegui = 0;
playertwogui = 0;
  noInterrupts();
  TCCR1A = 0; //Timecounter Register TCCRxA
  TCCR1B = 0; //Timecounter Register TCCRxB
  TIMSK1 |= (1 << TOIE1); //Interrupt release
  TCCR1B |= (1 << CS12); //Structure Time-Interval
  TCNT1 = Interval_MaxCounter - Interval_200ms; //Definite Time-Interval
  interrupts();
}
ISR(TIMER1_OVF_vect) // When the timer activates an Interrupt the function starts
{  
  int i;
  decode_results result;  //decode received results in an libraray for IR-Codes
  //reset timer interval
  TCNT1 = Interval_MaxCounter - Interval_200ms; //The Timeintervall restarts

  sensor.decode(&result);//IR-library delivers an decoded signal

  
  switch (result.value) //Switch compares the signal with cases, in every case is a variable, the variable of the adressed case will set on 1, so the LED turns on, but only if there is no LED on of the other color on the same field.
  {
    case 16724175: //IR signal of button 1(red) on IR Remote
      a = 1;  //LED a sets on 1
        if(t==1) //only if LED t is 0
         {
          a=0; // a stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16718055: // IR signal of button 2 (red) on IR Remote
      b = 1; //LED b sets on 1 
        if(u==1) //only if LED u is 0
         {
          b=0; // b stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16743045: //IR signal for button 3(red) on IR Remote
      c = 1; //LED c sets on 1 
        if(l==1) //only if LED l is 0
         {
          c=0; // c stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16716015: //IR signal for button 4(red) on IR Remote
      d = 1;  //LED d sets on 1
        if(m==1) //only if LED m is 0
         {
          d=0; // d stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16726215: //IR signal for button 5(red) on IR Remote
      e = 1; //LED e sets on 1
        if(n==1) //only if LED n is 0
        {
          e=0; // e stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16734885: //IR signal for button 6(red) on IR Remote
      f = 1; //LED f sets on 1
        if(o==1) //only if LED o is 0
        {
          f=0; // f stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16728765: //IR signal for button 7(red) on IR Remote
      g = 1; //LED g sets on 1 
        if(p==1) //only if LED p is 0
         {
          g=0; // g stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16730805: //IR signal button 8(red) on IR Remote
      h = 1; //LED h sets on 1
        if(q==1) //only if LED q is 0
         {
          h=0; // h stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16732845: //IR signal button 9(red) on IR Remote
      s = 1; //LED s sets on 1
        if(r==1) //only if LED r is 0
         {
          s=0; // s stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16753245: //IR signal button 1(green) on IR Remote
      t = 1; //LED t sets on 1
        if(a==1) //only if LED a is 0
         {
          t=0; // t stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16736925: //IR signal button 2(green) on IR Remote
      u = 1; //LED u sets on 1 
        if(b==1) //only if LED b is 0
         {
          u=0; // u stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16769565: //IR signal button 3(green) on IR Remote
      l = 1; //LED l sets on 1
        if(c==1) //only if LED c is 0
         {
          l=0; // l stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16720605: //IR signal button 4(green) on IR Remote
      m = 1; //LED m sets on 1
        if(d==1) //only if LED d is 0
         {
          m=0; // m stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16712445: //IR signal for button 5(green) on IR Remote
      n = 1; //LED n sets on 1 
        if(e==1) //only if LED e is 0
         {
          n=0; // n stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16761405: //IR signal for button 6(green) on IR Remote
      o = 1; //LED o sets on 1 
        if(f==1) //only if LED f is 0
         {
          o=0; // o stays 0
          Buzzer(); // Buzzer beeps
         }
      break;
    case 16769055: //IR signal for button 7(green) on IR Remote
      p = 1; //LED p sets on 1
      if(g==1) //only if LED g is 0
         {
          p=0; // p stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16754775: //IR signal on button 8(green) on IR Remote
      q = 1; //LED q sets on 1
        if(h==1) //only if LED h is 0
         {
          q=0; // q stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16748655: //IR signal on button 9(Grün) on IR Remote
      r = 1; //LED r sets on 1
        if(s==1) //außer LED s is 0
         {
          r=0; // r stays 0
          Buzzer(); // Buzzer beeps
         }
      break; // case closed
    case 16738455:  //Case button 0 = Reset all LEDs/ restart, all LEDs are off
      a = 0; // All LEDs were set on 0
      b = 0;
      c = 0;
      d = 0;
      e = 0;
      f = 0;
      g = 0;
      h = 0;
      s = 0;
      t = 0;
      u = 0;
      l = 0;
      m = 0;
      n = 0;
      o = 0;
      p = 0;
      q = 0;
      r = 0;
      default: // release if there is no case triggert
      break; // case closed
  } 
sensor.resume(); // Sensor is available for a new signal
}
void loop()
{
 while(Serial.available()>0) //check if arduino is available for QT
  {
    Serial.println("available"); //Message to QT
    if(Serial.read() == 'R') //Compare data for restart the game
    {
      a = 0; // All LED set on 0
      b = 0;
      c = 0;
      d = 0;
      e = 0;
      f = 0;
      g = 0;
      h = 0;
      s = 0;
      t = 0;
      u = 0;
      l = 0;
      m = 0;
      n = 0;
      o = 0;
      p = 0;
      q = 0;
      r = 0;
      greengui = 0; //Variables for Datatransfer are set on 0
      redgui = 0;
      playeronegui = 0;
      playertwogui = 0;
    }
    Serial.println("Game starts"); //Message to QT
  }

  
 swseg();   //Function for 7Segmentdisplay
 int lampen[9]={s,h,g,f,e,d,c,b,a}; // LED Array red
 digitalWrite(storePin, LOW); //SR stays available
 for (int x = 0; x < 9; x++) //For-Loop works with the array "lampen"
  {
    digitalWrite(shiftPin, LOW); //saved data deletes
    digitalWrite(dataPin, lampen[x]); // new data for for-loop
    digitalWrite(shiftPin, HIGH); // Data is received in Shift-Register
  }
 digitalWrite(storePin, HIGH);// Output of new data

 swseg(); //Function for 7Segmentdisplay
 int lichter [9]={r,q,p,o,n,m,l,u,t}; // LED Array green
 digitalWrite(speicherPin, LOW); //SR stays available
 for(int k = 0; k < 9;k++)  //For-Loop works with the array "lichter"
  {
    digitalWrite(wechselPin, LOW);  //saved data deletes
    digitalWrite(datenPin, lichter[k]);  // new data for for-loop
    digitalWrite(wechselPin, HIGH);// Data is received in Shift-Register
  }
 digitalWrite(speicherPin, HIGH);// Output of new data
 Sieg();  // Winning-Function
}

void swseg()
{
 int array[18]={a,b,c,d,e,f,g,h,s,t,u,l,m,n,o,p,q,r}; // Array of all LEDs
 int sum=0; // Sum sets on 0 
 for (int j=0;j<18;j++) // for-loop works with Array of all LEDs
  {
   sum += array[j]; // the array sum all variables of array
  }
  sum = sum  % 2; //modulo slavage value Operation
 
  switch(sum) // switch sum compare, which players turn is right now
  {
  case 0:
      playeronegui=playeronegui+1; //Player 1 Variable adds 1 
      if(playeronegui==1) // when variable is =1 output to QT
      {
      Serial.println("spieler 1 ist dran"); //output message to QT
      playertwogui=0;//reset variable
      }
      playertwogui=0;//reset variable
    
    digitalWrite(sPin, LOW);// SR is available for new data
      for(int y = 0; y<8; y++) // for-Schleife works for Array PlayerOne
         {
           digitalWrite(wPin, LOW);  //saved Data Reset
           digitalWrite(dPin, PlayerOne[y]); // new Data input for Loop
           digitalWrite(wPin, HIGH);// Data received
          }
    digitalWrite(sPin, HIGH);// Output new data
    break; // case closed
   case 1:
        playertwogui=playertwogui+1;//Player 2 variable adds +1 
        if(playertwogui==1)//if player2 variable is 1, message to QT
        {
        Serial.println("spieler 2 ist dran"); //output to QT "its player2 turn"
        playeronegui = 0;//reset variable
        }
        playeronegui=0;//reset variable
       
     digitalWrite(sPin, LOW);// SR is available for new data
      for(int y = 0; y<8; y++)  //Loop works with Array PlayerTwo
        {
           digitalWrite(wPin, LOW);  //saved Data  Reset
           digitalWrite(dPin, PlayerTwo[y]); // new Data for Loop
           digitalWrite(wPin, HIGH);// Data received in SR
        }
     digitalWrite(sPin, HIGH);// Output new data
     default: // release when there is now case activated
     break; // case closed
  }


}
void Sieg()
{
int array[18]={a,b,c,d,e,f,g,h,s,t,u,l,m,n,o,p,q,r}; //LED Status Array all LEDs
  if(a==1 && b==1 && c==1) //1. opportunity for winning(top line red)
    {
      Red(); //winningfunction activate
    }
   if(a==1 && e==1 && s==1)//1. opportunity for winning(diagonal 1 red)
   {
      Red();  //winningfunction activate
   }
   if(a==1 && d==1 && g==1)//2. opportunity for winning(first column red)
   {
    Red(); //winningfunction activate
   }
   if(b==1 && e==1 && h==1)//3. opportunity for winning(second column red)
   {
    Red(); //winningfunction activate
   }
   if(c==1 && f==1 && s==1)//4. opportunity for winning(third column red)
   {
    Red(); //winningfunction activate
   }
   if(d==1 && e==1 && f==1)//5. opportunity for winning(second line red)
   {
    Red(); //winningfunction activate
   }
   if(g==1 && h==1 && s==1)//6. opportunity for winning(third line red)
   {
    Red(); //winningfunction activate
   }
   if(c==1 && e==1 && g==1)//7. opportunity for winning(diagonal 2 red)
   {
    Red(); //winningfunction activate
   }
   if(t==1 && u==1 && l==1)//8. opportunity for winning(First lin green)
   {
    Green(); //winningfunction activate
   }
   if(t==1 && n==1 && r==1)//9. opportunity for winning(Diagonal 1 green)
   {
    Green(); //winningfunction activate
   }
   if(t==1 && m==1 && p==1)//10. opportunity for winning(First green)
   {
    Green(); //winningfunction activate
   }
   if(u==1 && n==1 && q==1)//11. opportunity for winning(Second column green)
   {
    Green(); //winningfunction activate
   }
   if(l==1 && o==1 && r==1)//12. opportunity for winning(Third column green)
   {
    Green(); //winningfunction activate
   }
   if(m==1 && n==1 && o==1)//13. opportunity for winning(Second line green)
   {
    Green(); //winningfunction activate
   }
   if(p==1 && q==1 && r==1)//14. opportunity for winning(Third line green)
   {
    Green(); //winningfunction activate
   }
   if(l==1 && n==1 && p==1)//15. opportunity for winning(Diagonal 2 green)
   {
    Green(); //winningfunction activate
   }
   if(t==1 && n==1 && r==1)//16. opportunity for winning(Diagonal 1 green)
   {
    Green(); //winningfunction activate
   }
}
void Red() // Winning Function Player Red, All LEDs turn on and Buzzer beeps
{

  redgui = redgui+1;//adds +1 to variable
  if(redgui==1)//compare
  {
    Serial.println("Spieler Rot hat gewonnen"); //Message to QT "Player Red wons"
  }

  digitalWrite(sPin, LOW);// SR is available for new data
  for(int y = 0; y<8; y++)  //Loop works with array reset
    {
      digitalWrite(wPin, LOW);  //saved Data Reset
      digitalWrite(dPin, Reset[y]); // new data for loop
      digitalWrite(wPin, HIGH);// Data receivend in SR
     }
  digitalWrite(sPin, HIGH);// Output new data
  s=1; // all red LEDs turn on
  h=1;
  g=1;
  f=1;
  e=1;
  d=1;
  c=1;
  b=1;
  a=1;
  int lampen[9]={s,h,g,f,e,d,c,b,a}; //Array alle red LEDs
  digitalWrite(storePin, LOW);// SR is avaiable for Input
  for (int x = 0; x < 9; x++)  //Loop works with Array "lampen"
  {
    digitalWrite(shiftPin, LOW);  //saved Data Reset
    digitalWrite(dataPin, lampen[x]); // new data for loop
    digitalWrite(shiftPin, HIGH);//  Data receivend in SR
  }
  digitalWrite(storePin, HIGH);// output new data
  Buzzer(); //Buzzer beeps
  delay(2*pause); // dobble break
  
}
void Green() // Winning Function Player Green, All LEDs turn on and Buzzer beeps
{ 

  greengui = greengui+1;//adds +1 to variable 
  if(greengui==1)//if variable = 1 output to QT
  {
    Serial.println("Spieler Grün hat gewonnen"); //Message to QT "Player Green wons"
  }
  

  digitalWrite(sPin, LOW);//  SR is available for new data
  for(int y = 0; y<8; y++)  //Loop works with array reset
    {
      digitalWrite(wPin, LOW);  //saved Data Reset
      digitalWrite(dPin, Reset[y]); // new data for loop
      digitalWrite(wPin, HIGH);// Data receivend in SR
     }
  digitalWrite(sPin, HIGH);// output new data
  t=1;// all green LEDs turn on
  u=1;
  l=1;
  m=1;
  n=1;
  o=1;
  p=1;
  q=1;
  r=1;
  int lichter [9]={r,q,p,o,n,m,l,u,t}; //Array for all green LEDs
  digitalWrite(speicherPin, LOW);// SR is available for new input
  for(int k = 0; k < 9;k++)  //loop works with Array "lichter"
  {
    digitalWrite(wechselPin, LOW);  //saved Data Reset
    digitalWrite(datenPin, lichter[k]); // new data for loop
    digitalWrite(wechselPin, HIGH);// Data receivend in SR
  }
  digitalWrite(speicherPin, HIGH);// output new data
  Buzzer();//Buzzer beeps
  delay(2*pause); // double break

}
void Buzzer()
{
 digitalWrite(buzzer, HIGH); //Buzzer turn on
 delay(pause); // buzzer beeps an interval
 digitalWrite(buzzer, LOW); //Buzzer turns off
}
