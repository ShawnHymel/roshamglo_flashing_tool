//RoshamGlow self-test 1/20/17

//#include <IntarIR.h> //(IN FW)

// 5-way Switch Defines (IN FW)
#define DOWN_PIN            PA0
#define RIGHT_PIN           PA1
#define UP_PIN              PA2
#define LEFT_PIN            PA4
#define CENTER_PIN          PA6

// LED Defines (IN FW)
#define GRN_LED       PA7
#define RED_LED       PB2
#define IR_LED        PA5
#define IR_REC        PA3

int st_val;
bool up,down,right,left,center;
  
void setup() 
{
  PORTA = (1<<LEFT_PIN)|(1<<RIGHT_PIN)|(1<<UP_PIN)|(1<<DOWN_PIN)|(1<<CENTER_PIN);
  
  st();
}

void loop() 
{
 
}
///////////////////////////////////////////////////////////////////////////////////////
void st()
{
  // Enable pullup resistors for 5-way switch (IN FW)
  DDRA = (1<<GRN_LED)|(1<<IR_LED);
  DDRB = (1<<RED_LED);

  PORTA &= ~((1<<GRN_LED)|(1<<IR_LED));
  PORTB &= ~(1<<RED_LED);

  if((!(PINA & (1<<UP_PIN))) && (!(PINA & (1<<LEFT_PIN))) && (!(PINA & (1<<RIGHT_PIN))) && (!(PINA & (1<<CENTER_PIN))))
  {
    _delay_ms(500);
    st_val = 0;
    five_way_tst();
    if(st_val==5)
    {
      transmit_IR();
      _delay_ms(250);
      recieve_IR();
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////
void five_way_tst()
{
  byte i;
  for(i=0;i<70;i++)
  {
   if(st_val < 5)
   {
    PORTA |= (1<<GRN_LED);
    PORTB &= ~(1<<RED_LED);
    if((!(PINA & (1<<UP_PIN))) && (up==0))
    {
      up=1;
      st_val++;
    }
    _delay_ms(50);
    if((!(PINA & (1<<DOWN_PIN))) && (down==0))
    {
      down=1;
      st_val++;
    }
    _delay_ms(50);
    PORTA &= ~(1<<GRN_LED);
    PORTB |= (1<<RED_LED);
    
    if((!(PINA & (1<<RIGHT_PIN))) && (right==0))
    {
      right=1;
      st_val++;
    }
    _delay_ms(50);
    if((!(PINA & (1<<LEFT_PIN))) && (left==0))
    {
      left=1;
      st_val++;
    }
    _delay_ms(50);
    if((!(PINA & (1<<CENTER_PIN))) && (center==0))
    {
      center=1;
      st_val++;
    }
    if(st_val==5)
    {
      i = 71;
      PORTA &= ~(1<<GRN_LED);
      PORTB &= ~(1<<RED_LED);
    }
   }
  }
  if(i==70)
  {
    PORTB |= (1<<RED_LED);
    PORTA &= ~(1<<GRN_LED);
  }
}
////////////////////////////////////////////////////////////////////////////////////
void transmit_IR()
{
  for(int i=0;i<2000;i++)
  {
    PORTB |= (1<<RED_LED);
    PORTA |= (1<<IR_LED);
    _delay_us(11);
    PORTA &= ~(1<<IR_LED);
    _delay_us(10);
  }
  
  PORTB &= ~(1<<RED_LED);
}
///////////////////////////////////////////////////////////////////////////////////
void recieve_IR()
{
  byte i;
  
  for(i=0;i<250;i++)
  {
    _delay_ms(10);
    if(!(PINA & (1<<IR_REC)))
    {
      while(1)
      {
        PORTA |= (1<<GRN_LED);
      }
    }
  }
  if(i>249)
  {
    while(1)
    {
      PORTB |= (1<<RED_LED);
    }
  }
}

