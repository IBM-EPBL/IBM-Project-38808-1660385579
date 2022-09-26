/* - - - - - initialization function - - - - - */
void init()
{
  PINSEL1=0x01080000; /* Select P0.28 as ADC and P0.25 as DAC */
  PINSEL2=0x00000000; /* Select the port function as GPIO */
  IO1DIR=0x00FF0000; /* select P1.16 to P1.23 as output */
  
  IO0DIR=0xF00; //Set port line as output port
 
}

/* - - - - - uart initialization function - - - - - */
void uart_inital()
{
  PINSEL0_bit.P0_0=0X01; /*Select the function of the 0th pin of port0 as TXD*/
  PINSEL0_bit.P0_1=0X01; /*Select the function of the 1st pin of port0 as RXD*/
  PINSEL0_bit.P0_8=0X01; /*Select the function of the 8th pin of port0 as TXD*/
  PINSEL0_bit.P0_9=0X01; /*Select the function of the 9th pin of port0 as RXD*/
  
  VPBDIV=0X01; /* Controls the rate of the VPB clock in relation to the processor clock.
                  If VPBDIV is 01, then VPB bus clock is the same as the processor clock */

  U1LCR=0X83; /* The U1LCR determines the format of the data character that is to be transmitted or received.
                The 2 LSB's of the U1LCR is the Word Length Select Bits and is 11 when the word length is of 8 bits
                THe MSB is the Divisor Latch Access Bit (DLAB), this has to be enabled to access the Divisor Latch Registers(DLL & DLM) */
  U1DLL=0X4E;  /* The UART1 Divisor Latch LSB Register, along with the U1DLM register, determines the baud rate of the UART1      */
  U1DLM=0X00; /*  The UART1 Divisor Latch MSB Register, along with the U1DLL register, determines the baud rate of the UART1.        */
  U1LCR=0X03; 
  
  U0LCR=0X83;   /* The U0CR determines the format of the data character that is to be transmitted or received.
                The 2 LSB's of the U1LCR is the Word Length Select Bits and is 11 when the word length is of 8 bits
                THe MSB is the Divisor Latch Access Bit (DLAB), this has to be enabled to access the Divisor Latch Registers(DLL & DLM) */
  U0DLL=0X4E; /*The UART0 Divisor Latch LSB Register, along with the U0DLM register, determines the baud rate of the UART0.*/
  U0DLM=0X00; /*The UART0 Divisor Latch MSB Register, along with the U0DLL register, determines the baud rate of the UART0.*/
  U0LCR=0X03;
}

/* funtion to access printf - - - - - */

int putchar(int ch)
{
  while((U0LSR&0X20)!=0X20);
  return(U0THR=ch);
}
