


#define SYNC_DATA                0x00
#define HEADER                        0xAA
#define cal PORTC.F0
#define up PORTC.F1
#define down PORTC.F4
#define pumpswitch PORTB.F1

unsigned int counter;

sbit LCD_RS at RB7_bit;
sbit LCD_EN at RB6_bit;
sbit LCD_D4 at RB5_bit;
sbit LCD_D5 at RB4_bit;
sbit LCD_D6 at RB3_bit;
sbit LCD_D7 at RB2_bit;

sbit LCD_RS_Direction at TRISB7_bit;
sbit LCD_EN_Direction at TRISB6_bit;
sbit LCD_D4_Direction at TRISB5_bit;
sbit LCD_D5_Direction at TRISB4_bit;
sbit LCD_D6_Direction at TRISB3_bit;
sbit LCD_D7_Direction at TRISB2_bit;

unsigned char range;
unsigned char number;
unsigned char pumponlevel, pumpofflevel, transmiton;
unsigned char set2 = 40;
unsigned char no[] = "faith ";
void uart1_send(unsigned char dataa)
{
        while(TXIF_bit==0);                                //only send the new data after
        TXREG = dataa;                                        //the previous data finish sent
}


void send_packet(unsigned char dataa)
{
        unsigned char i;

        unsigned char buffer[3];


        buffer[0] = HEADER;


        buffer[1] = dataa;


        buffer[2] = (unsigned char)(HEADER + dataa);

        // Clocking for a while before sending the data so that the Tx and Rx are in sync.
        for (i = 0; i < 7; i++) uart1_send(SYNC_DATA);

        // Transmit the packet using UART.
        for (i = 0; i < 3; i++) uart1_send(buffer[i]);
}

//void uart_send(unsigned char data);
//void send_packet(unsigned char data);
    unsigned char tt;
void wireles() {
        BRGH_bit = 0;
        SPBRG = 51;
        TX9_bit = 0;
        TXEN_bit = 1;
        SYNC_bit = 0;

        SPEN_bit = 1;
            send_packet('#');
for (tt=0; tt< 6; tt++) {
     send_packet(no[tt]);
}
 send_packet('*');
             send_packet('*');

}



unsigned int T1_O  = 0; // timer1 overflow updated in interrupt routine.
unsigned short gCapInt = 0; // captured something in interrupt routine.
unsigned short gfCapOn = 1; // control capture only capture 1st value.

unsigned int t_capL = 0; // timer 1 low.
unsigned int t_capH = 0; // timer 1 high.
unsigned int t_capO = 0; // timer 1 overflow.

unsigned int gCapVal = 0; // captured this.


//////////////////////////////////////////////////////////////////////
void enable_interrupts(void) {

   // Timer 1
   PIR1 &= ~(1<<TMR1IF); // Zero T1 overflow register value.

   // Capture
   PIR1 &= ~(1<<CCP1IF); // Zero Capture flag

   // Interrupt enable.
   PIE1 =  (1<<CCP1IE);

   // Global interrupt enable.
   INTCON = (1<<GIE) | (1<<PEIE); // enable global & peripheral
}

//////////////////////////////////////////////////////////////////////
void disable_interrupts(void) {
   INTCON &= ~(1<<GIE); // disable global & peripheral
}
unsigned char qr;
void gen_ultra(void) {
  PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

      PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

      PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

      PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

      PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

   PORTC.F3 = 1;
   delay_us(12);
   PORTC.F3 = 0;
   delay_us(11);

}
 unsigned char percent;
 unsigned char transmit;
 unsigned char pump;
  unsigned char set = 20;
  unsigned char displaydata[16];
//////////////////////////////////////////////////////////////////////
void main() {
unsigned char m,ii,ch0,ch1,yy,ch2,iii,j,lcd1[] = "000000" ;
unsigned int i,val,s1,s2,s3,tH,tL,tO;
unsigned char op[12];
 unsigned long calc=0;
unsigned long calc2 = 0;
unsigned long Vdec,Vfrac;
TRISC.F2 = 1;
TRISC.F3 = 0;
TRISC.F4 = 1;
TRISB.F1 = 0;
PORTB.F1 = 0;
set = 20;
transmit = 20;
pump = 20;
range = EEPROM_Read(0x00);
pumponlevel = EEPROM_Read(0x01);
pumpofflevel = EEPROM_Read(0x02);
transmiton = EEPROM_Read(0x03);
         BRGH_bit = 0;
        SPBRG = 51;
        TX9_bit = 0;
        TXEN_bit = 1;
        SYNC_bit = 0;

        SPEN_bit = 1;

  yy = 0;
 CCP1CON = 0x05;
   T1CON = (1<<TMR1ON);
           Lcd_Init();
        Lcd_Cmd(_LCD_CLEAR);
       Lcd_Cmd(_LCD_CURSOR_OFF);
       displaydata[0] =  ' ';
       displaydata[1] =  ' ';
       displaydata[2] =  ' ';
       displaydata[3] =  'L';
       displaydata[4] =  'E';
       displaydata[5] =  'V';
       displaydata[6] =  'E';
       displaydata[7] =  'L';
       displaydata[8] =  ' ';
       displaydata[9] =  'M';
       displaydata[10] = 'E';
       displaydata[11] = 'T';
       displaydata[12] = 'E';
       displaydata[13] = 'R';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(1, 1, displaydata) ;
      //  Lcd_Out(2, 7, "cm") ;

   gCapInt=0; // Reset capture indicator.

      counter = 0;
   while(1) {

if (set == 20) {
     counter++;
      gfCapOn = 1; // allow one capture value
   T1CON = ~(1<<TMR1ON);
      TMR1H = 0;
      TMR1L = 0;
      T1_O = 0;
      tO = T1_O; // Get the current timer value.
      tH = TMR1H;
      tL = TMR1L;

      t_capL = 0;
      t_capH = 0;
      t_capO = 0;  // initialise capture
       T1CON = (1<<TMR1ON);
      gen_ultra();

      enable_interrupts();
      //seg_display_int(val);
      delay_ms(40);
      disable_interrupts(); // had 20 ish ms of time so stop

    //  if (! gCapInt) { // no echo from soft output ? try loud

    //     enable_interrupts();
//delay_ms(40);
  //       disable_interrupts(); // had 20 ish ms of time so stop
    //  }

      // Did we get any echo from soft or loud ?
      if (gCapInt) { // captured anything ?
         yy = 0;
         gCapInt=0;  // reset for next time

         // 4MHz clock so timer 1 returns us
         // gCapVal * 1,000,000 = seconds.
         // speed of sound in air at 20degC = 340m/s
         // (gCapVal*1000000*340)/(2*100) = distance in cm

         s1=(t_capH - tH);
         s2=(t_capL - tL);
         s3 = (t_capO - tO);

         calc = ((s1)<<8)+s2;
         calc *= 34;
         calc /= 2000; // output in cm
       //  calc2 = calc * 100000 / range; // output in percentage
       calc2 = calc * 100000 / (range - 10); // output in percentage
         calc2 = 100000 - calc2;


         LongToStr(calc,op);
j=0;
for(iii=0;iii<=11;iii++)
{
if(op[iii] != ' ') // If a blank
{
lcd1[j]=op[iii];
j++;
}
}

//        Lcd_Cmd(_LCD_CLEAR);

       displaydata[0] =  ' ';
       displaydata[1] =  ' ';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  'c';
       displaydata[8] =  'm';
       displaydata[9] =  ' ';
       displaydata[10] = ' ';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(2, 1, displaydata) ;

//Lcd_Out(2,1, "       cm");
Lcd_Out(2,1,lcd1); // Output to LCD
if (s3 > 0) {
 Lcd_Chr(2, 3, (s3 + 48));
}

     Vdec = calc2 / 1000; // Decimal part
Vfrac = calc2 % 1000; // Fractional part
        LongToStr(Vdec,op); // Convert Vdec to string in "op"
//FloatToStr(Vin, op);
//
// Remove leading blanks
//
j=0;
for(i=0;i<=11;i++)
{
if(op[i] != ' ') // If a blank
{
lcd1[j]=op[i];
j++;
}
}
//
// Display result on LCD
//
  /*
       displaydata[0] =  ' ';
       displaydata[1] =  ' ';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  ' ';
       displaydata[8] =  ' ';
       displaydata[9] =  ' ';
       displaydata[10] = ' ';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(1, 1, displaydata) ;
    */
// Lcd_Out(1,1,"                ");
Lcd_Out(1,1,lcd1); // Output to LCD
Lcd_Out_Cp("."); // Display "."

ch0 = Vfrac / 100; // Calculate fractional part
ch1 = (Vfrac % 100) / 10; // Calculate fractional part
//ch3 = (Vfrac % 100) / 10; // Calculate fractional part
ch2 = Vfrac % 10; // Calculate fractional part

//ch0 = Vfrac / 10 ;
//ch1 = Vfrac % 10; // Calculate fractional part

Lcd_Chr_Cp(48+ch0); // Display fractional part
Lcd_Chr_Cp(48+ch1); // Display fractional part
Lcd_Chr_Cp(48+ch2); // Display fractional part

//Lcd_Chr_Cp(176);
Lcd_Chr_Cp('%');

 if ((Vdec <= pumponlevel) && (set2 == 40)) {
 pumpswitch = 1;
 delay_ms(2000);
 set2 = 20;
}
else if ((Vdec >= pumpofflevel) && (set2 == 20)) {
 pumpswitch = 0;
 delay_ms(2000);
 set2 = 40;
}

      if (counter >= 125) {
 counter = 0;
 if (transmiton == 20) {
 no[0] = lcd1[0];
 no[1] = lcd1[1];
 no[2] = lcd1[2];
 no[3] = ch0 + 48;  //  lcd1[3];
 no[4] = ch1 + 48;  //lcd1[4];
 no[5] = ch2 + 48;  //lcd1[5];
 wireles();
}
}



      }
else yy++;

   /*
if (yy >= 50) {
       displaydata[0] =  ' ';
       displaydata[1] =  'O';
       displaydata[2] =  'U';
       displaydata[3] =  'T';
       displaydata[4] =  ' ';
       displaydata[5] =  'O';
       displaydata[6] =  'F';
       displaydata[7] =  ' ';
       displaydata[8] =  'R';
       displaydata[9] =  'A';
       displaydata[10] = 'N';
       displaydata[11] = 'G';
       displaydata[12] = 'E';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(1, 1, displaydata) ;


// Lcd_Out(1,1,"out of range");
// lcd1[0] = '*';
// lcd1[1] = '*';
// lcd1[2] = '*';
// lcd1[3] = '*';
// lcd1[4] = '*';
// lcd1[5] = '*';
}
 */
if (cal == 0) {
//delay_ms(100);
 set = 30;
       displaydata[0] =  ' ';
       displaydata[1] =  ' ';
       displaydata[2] =  ' ';
       displaydata[3] =  'R';
       displaydata[4] =  'A';
       displaydata[5] =  'N';
       displaydata[6] =  'G';
       displaydata[7] =  'E';
       displaydata[8] =  ' ';
       displaydata[9] =  '(';
       displaydata[10] = 'c';
       displaydata[11] = 'm';
       displaydata[12] = ')';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(1, 1, displaydata) ;
       displaydata[0] =  '<';
       displaydata[1] =  '<';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  ' ';
       displaydata[8] =  ' ';
       displaydata[9] =  '>';
       displaydata[10] = '>';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(2, 1, displaydata) ;

//        Lcd_Out(1, 1, "RANGE (cm)") ;
  delay_ms(1000);
}

 }

 else if (set == 30) {

// Lcd_Out(2, 1, "<  ") ;
ch0 = range / 100; // Calculate fractional part
ch1 = (range % 100) / 10; // Calculate fractional part
//ch3 = (Vfrac % 100) / 10; // Calculate fractional part
ch2 = range % 10; // Calculate fractional part

Lcd_Chr(2, 4, 48+ch0);
Lcd_Chr(2, 5, 48+ch1);
Lcd_Chr(2, 6, 48+ch2);

//Lcd_Chr_Cp(48+ch0); // Display fractional part
//Lcd_Chr_Cp(48+ch1); // Display fractional part
//Lcd_Chr_Cp(48+ch2); // Display fractional part

// Lcd_Out(2, 7, "  >") ;
 if (up == 0) {
 delay_ms(100);
 if (range < 250)   range++;
 }

 else if (down == 0) {
  delay_ms(100);
 if (range > 12)     range--;
 }

 else if (cal == 0) {
 // delay_ms(100);
  set = 40;
  EEPROM_Write(0x00, range);

        displaydata[0] =  'P';
       displaydata[1] =  'U';
       displaydata[2] =  'M';
       displaydata[3] =  'P';
       displaydata[4] =  ' ';
       displaydata[5] =  'O';
       displaydata[6] =  'N';
       displaydata[7] =  ' ';
       displaydata[8] =  'L';
       displaydata[9] =  'E';
       displaydata[10] = 'V';
       displaydata[11] = 'E';
       displaydata[12] = 'L';
       displaydata[13] = '(';
       displaydata[14] = '%';
       displaydata[15] = ')';
        Lcd_Out(1, 1, displaydata) ;

       displaydata[0] =  '<';
       displaydata[1] =  '<';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  ' ';
       displaydata[8] =  ' ';
       displaydata[9] =  '>';
       displaydata[10] = '>';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(2, 1, displaydata) ;
      percent = pumponlevel;
    delay_ms(1000);
//  Lcd_Out(1, 1, "PUMP ON LEVEL(%)") ;

 }

 }

 else if (set == 40) {

// Lcd_Out(2, 1, "<  ") ;
//percent = 15;
ch0 = percent / 100; // Calculate fractional part
ch1 = (percent % 100) / 10; // Calculate fractional part
//ch3 = (Vfrac % 100) / 10; // Calculate fractional part
ch2 = percent % 10; // Calculate fractional part

Lcd_Chr(2, 4, 48+ch0);
Lcd_Chr(2, 5, 48+ch1);
Lcd_Chr(2, 6, 48+ch2);

//Lcd_Chr_Cp(48+ch0); // Display fractional part
//Lcd_Chr_Cp(48+ch1); // Display fractional part
//Lcd_Chr_Cp(48+ch2); // Display fractional part

// Lcd_Out(2, 7, "  >") ;
 if (up == 0) {
 delay_ms(100);
 if (percent < 100)   percent++;
 }

 else if (down == 0) {
  delay_ms(100);
 if (percent > 1)     percent--;
 }

 else if (cal == 0) {
 // delay_ms(100);
  set = 50;
  pumponlevel = percent;
    EEPROM_Write(0x01, pumponlevel);

        displaydata[0] =  'P';
       displaydata[1] =  'U';
       displaydata[2] =  'M';
       displaydata[3] =  'P';
       displaydata[4] =  ' ';
       displaydata[5] =  'O';
       displaydata[6] =  'F';
       displaydata[7] =  'F';
       displaydata[8] =  'L';
       displaydata[9] =  'E';
       displaydata[10] = 'V';
       displaydata[11] = 'E';
       displaydata[12] = 'L';
       displaydata[13] = '(';
       displaydata[14] = '%';
       displaydata[15] = ')';
        Lcd_Out(1, 1, displaydata) ;
       displaydata[0] =  '<';
       displaydata[1] =  '<';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  ' ';
       displaydata[8] =  ' ';
       displaydata[9] =  '>';
       displaydata[10] = '>';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(2, 1, displaydata) ;
       percent = pumpofflevel;
    delay_ms(1000);
//  Lcd_Out(1, 1, "PUMP ON LEVEL(%)") ;

 }

 }



 else if (set == 50) {

// Lcd_Out(2, 1, "<  ") ;
//percent = 90;
ch0 = percent / 100; // Calculate fractional part
ch1 = (percent % 100) / 10; // Calculate fractional part
//ch3 = (Vfrac % 100) / 10; // Calculate fractional part
ch2 = percent % 10; // Calculate fractional part

Lcd_Chr(2, 4, 48+ch0);
Lcd_Chr(2, 5, 48+ch1);
Lcd_Chr(2, 6, 48+ch2);

//Lcd_Chr_Cp(48+ch0); // Display fractional part
//Lcd_Chr_Cp(48+ch1); // Display fractional part
//Lcd_Chr_Cp(48+ch2); // Display fractional part

// Lcd_Out(2, 7, "  >") ;
 if (up == 0) {
 delay_ms(100);
 if (percent < 100)   percent++;
 }

 else if (down == 0) {
  delay_ms(100);
 if (percent > 1)     percent--;
 }

 else if (cal == 0) {
 // delay_ms(100);
  set = 60;
  pumpofflevel = percent;
  EEPROM_Write(0x02, pumpofflevel);

        displaydata[0] =  'T';
       displaydata[1] =  'R';
       displaydata[2] =  'A';
       displaydata[3] =  'N';
       displaydata[4] =  'S';
       displaydata[5] =  'M';
       displaydata[6] =  'I';
       displaydata[7] =  'T';
       displaydata[8] =  ' ';
       displaydata[9] =  'O';
       displaydata[10] = 'N';
       displaydata[11] = '/';
       displaydata[12] = 'O';
       displaydata[13] = 'F';
       displaydata[14] = 'F';
       displaydata[15] = ' ';
        Lcd_Out(1, 1, displaydata) ;
       displaydata[0] =  '<';
       displaydata[1] =  '<';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  ' ';
       displaydata[8] =  ' ';
       displaydata[9] =  '>';
       displaydata[10] = '>';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(2, 1, displaydata) ;
transmit = transmiton;
    delay_ms(1000);
//  Lcd_Out(1, 1, "PUMP ON LEVEL(%)") ;

 }

 }



 else if (set == 60) {

// Lcd_Out(2, 1, "<  ") ;

//ch0 = percent / 100; // Calculate fractional part
//ch1 = (percent % 100) / 10; // Calculate fractional part
//ch3 = (Vfrac % 100) / 10; // Calculate fractional part
//ch2 = percent % 10; // Calculate fractional part

//Lcd_Chr(2, 4, 48+ch0);
//Lcd_Chr(2, 5, 48+ch1);
//Lcd_Chr(2, 6, 48+ch2);

//Lcd_Chr_Cp(48+ch0); // Display fractional part
//Lcd_Chr_Cp(48+ch1); // Display fractional part
//Lcd_Chr_Cp(48+ch2); // Display fractional part
if (transmit == 20) {
  Lcd_Chr(2, 4, 'O');
Lcd_Chr(2, 5, 'N');
Lcd_Chr(2, 6, ' ');
}

else if (transmit == 40) {
  Lcd_Chr(2, 4, 'O');
Lcd_Chr(2, 5, 'F');
Lcd_Chr(2, 6, 'F');

}

// Lcd_Out(2, 7, "  >") ;
 if (up == 0) {
 delay_ms(100);
// if (percent < 100)   percent++;
 transmit = 20;
 }

 else if (down == 0) {
  delay_ms(100);
// if (percent > 1)     percent--;
transmit = 40;

 }

 else if (cal == 0) {
 // delay_ms(100);
  set = 20;
  transmiton = transmit;
  EEPROM_Write(0x03, transmiton);


       displaydata[0] =  ' ';
       displaydata[1] =  ' ';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  ' ';
       displaydata[8] =  ' ';
       displaydata[9] =  ' ';
       displaydata[10] = ' ';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(1, 1, displaydata) ;
       displaydata[0] =  ' ';
       displaydata[1] =  ' ';
       displaydata[2] =  ' ';
       displaydata[3] =  ' ';
       displaydata[4] =  ' ';
       displaydata[5] =  ' ';
       displaydata[6] =  ' ';
       displaydata[7] =  'c';
       displaydata[8] =  'm';
       displaydata[9] =  ' ';
       displaydata[10] = ' ';
       displaydata[11] = ' ';
       displaydata[12] = ' ';
       displaydata[13] = ' ';
       displaydata[14] = ' ';
       displaydata[15] = ' ';
        Lcd_Out(2, 1, displaydata) ;

    delay_ms(1000);
//  Lcd_Out(1, 1, "PUMP ON LEVEL(%)") ;

 }

 }






   } // while(1)
}

////////////////////////////////////////////////////////////////////////
void interrupt(void) {

   // Free run Timer 1 get the overflow to extend counter here.
   if (PIR1 & (1<<TMR1IF) ) { // T1 overflowed ?
      PIR1 &= ~(1<<TMR1IF);   // clear timer1 overflow bit.
      T1_O++;
   }

   // Capture
   if (PIR1 & (1<<CCP1IF)) {
      PIR1 &= ~(1<<CCP1IF); // Zero Capture flag.

      if (gfCapOn) { // allow only 1 capture

         gfCapOn = 0;

         t_capL = CCPR1L;
         t_capH = CCPR1H;
         t_capO = T1_O;

         gCapInt = 1; // signal that a capture occured.
      }
   }

   // Interrupts are only enabled at a specific point from program.
   // They are not re-enabled here

   // Note GIE set by RETFIE instruction
}
