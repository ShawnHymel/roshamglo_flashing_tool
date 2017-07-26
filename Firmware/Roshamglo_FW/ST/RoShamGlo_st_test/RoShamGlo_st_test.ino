//RoshamGlow self-test 1/20/17
// 5-way Switch Defines (IN FW)
#define DOWN_PIN            PA0
#define RIGHT_PIN           PA1
#define UP_PIN              PA2
#define LEFT_PIN            PA4
#define CENTER_PIN          PA6

// LED Defines (IN FW)
#define GRN_LED       PA7
#define RED_LED       8
#define IR_LED        PA5
#define IR_REC        PA3

int st_val;
int up;
int down;
int right;
int left;
int center;
int i;

void setup() 
{
  //PORTA = (1<<LEFT_PIN)|(1<<RIGHT_PIN)|(1<<UP_PIN)|(1<<DOWN_PIN)|(1<<CENTER_PIN);
  
  pinMode(DOWN_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);
  pinMode(UP_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(CENTER_PIN, INPUT_PULLUP);
  //st();
  //pinMode(RED_LED, OUTPUT);
  //digitalWrite(RED_LED, HIGH);

  //pinMode(GRN_LED, OUTPUT);
  //digitalWrite(GRN_LED, HIGH);
  /*
  // Enable pullup resistors for 5-way switch (IN FW)
  pinMode(GRN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  pinMode(IR_LED, OUTPUT);
  digitalWrite(IR_LED, LOW);
  pinMode(IR_REC, INPUT);
  
  if((digitalRead(UP_PIN)==0)&&(digitalRead(LEFT_PIN)==0)&&(digitalRead(RIGHT_PIN)==0)&&(digitalRead(CENTER_PIN)==0))
  {
    st_val = 0;
    five_way_tst();
    if(st_val==5)
    {
      transmit_IR();
      recieve_IR();
    }
  }
  */
  pinMode(IR_LED, OUTPUT);
  digitalWrite(IR_LED, HIGH);
}

void loop() 
{
 
}
///////////////////////////////////////////////////////////////////////////////////////
void st()
{
  // Enable pullup resistors for 5-way switch (IN FW)
  pinMode(GRN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  pinMode(IR_LED, OUTPUT);
  digitalWrite(IR_LED, LOW);
  pinMode(IR_REC, INPUT);
  
  if((digitalRead(UP_PIN)==0)&&(digitalRead(LEFT_PIN)==0)&&(digitalRead(RIGHT_PIN)==0)&&(digitalRead(CENTER_PIN)==0))
  {
    delay(500);
    st_val = 0;
    five_way_tst();
    if(st_val==5)
    {
      transmit_IR();
      delay(250);
      recieve_IR();
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////
void five_way_tst()
{
  for(i=0;i<70;i++)
  {
   if(st_val < 5)
   {
    digitalWrite(GRN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    if((digitalRead(UP_PIN)==0) && (up==0))
    {
      up=1;
      st_val++;
    }
    delay(50);
    if((digitalRead(DOWN_PIN)==0) && (down==0))
    {
      down=1;
      st_val++;
    }
    delay(50);
    digitalWrite(GRN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    if((digitalRead(RIGHT_PIN)==0) && (right==0))
    {
      right=1;
      st_val++;
    }
    delay(50);
    if((digitalRead(LEFT_PIN)==0) && (left==0))
    {
      left=1;
      st_val++;
    }
    delay(50);
    if((digitalRead(CENTER_PIN)==0) && (center==0))
    {
      center=1;
      st_val++;
    }
    if(st_val==5)
    {
      i = 71;
      digitalWrite(GRN_LED, LOW);
      digitalWrite(RED_LED, LOW);
    }
   }
  }
  if(i==70)
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GRN_LED, LOW);
  }
}
////////////////////////////////////////////////////////////////////////////////////
void transmit_IR()
{
 for(i=0;i<2000;i++)
 {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(IR_LED, HIGH);
  delayMicroseconds(11);
  digitalWrite(IR_LED, LOW);
  delayMicroseconds(10);
 }
 digitalWrite(RED_LED, LOW);
}
///////////////////////////////////////////////////////////////////////////////////
void recieve_IR()
{
 for(i=0;i<250;i++)
 {
  delay(10);
  if(digitalRead(IR_REC)==0)
  {
   while(1)
   {
    digitalWrite(GRN_LED, HIGH);
   }
  }
 }
 if(i>249)
 {
  while(1)
  {
   digitalWrite(RED_LED, HIGH);
  }
 }
}

