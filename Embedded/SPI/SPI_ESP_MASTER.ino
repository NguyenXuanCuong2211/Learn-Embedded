/*
  Author: Nguyen Xuan Cuong
  SPI library
*/
// Master SPI Programming
#include "stdio.h"
#define SS_PIN 5   // Pin kết nối SS (Slave Select)
#define MOSI_PIN 21 // Pin kết nối MOSI
#define MISO_PIN 19 // Pin kết nối MISO
#define SCK_PIN 18  // Pin kết nối SCK
#define T_HALF 1   // Time half cycle

void setup() {
  Serial.begin(9600);
  spiSoftInit();
}

/*
  Function Name: spiSoftInit()
  Describe: declare mode of SPI PIN
  INPUT: void 
  OUTPUT: void
*/
void spiSoftInit()
		{
        pinMode(SS_PIN, OUTPUT);     // Chân SS là OUTPUT
        pinMode(MOSI_PIN, OUTPUT);   // Chân MOSI là OUTPUT
        pinMode(MISO_PIN, INPUT);    // Chân MISO là INPUT
        pinMode(SCK_PIN, OUTPUT);
				digitalWrite(SCK_PIN, 0);
				digitalWrite(MOSI_PIN, 0);
				digitalWrite(SS_PIN, 1);
		} //declare spi
/*
  Function Name: spiTransReceive(uint8_t data)
  Describe: transmit and receive a byte to SLAVE
  INPUT: a byte data transmit to SLAVE 
  OUTPUT: a byte data receive from MASTER
*/
uint8_t spiTransReceive(uint8_t data)
		{
        uint8_t MoveByte = 0x80; //1000.0000
        uint8_t ReceiveByte=0;
				digitalWrite(SS_PIN, 0);
				for(int i=0;i<8;i++)
				{
					if(data & MoveByte)
					{
							digitalWrite(MOSI_PIN, 1);
					}
					else digitalWrite(MOSI_PIN, 0);
          delay(T_HALF);
          if(digitalRead(MISO_PIN))
          {
              ReceiveByte = ReceiveByte|MoveByte;
          }
          digitalWrite(SCK_PIN, 1);
          delay(T_HALF);
          digitalWrite(SCK_PIN, 0);
					MoveByte= MoveByte>>1;
				}
				digitalWrite(SS_PIN, 1);
      return ReceiveByte;
		}
/*
  Function Name: spiTransReceiveString(const uint8_t *stringData,uint8_t *stringReceive, size_t size)
  Describe: transmit and receive a string to slave
  INPUT: a string transmit, a string receive, size of data
  OUTPUT: void
*/
void spiTransReceiveString(const uint8_t *stringData,uint8_t *stringReceive, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        stringReceive[i] = spiTransReceive(stringData[i]);
    }
}
void loop() {
  static uint8_t TransData=1;
  uint8_t Master_transmit[20];
  uint8_t Master_Receive[20];
  snprintf((char*)Master_transmit,sizeof(Master_transmit),"MASTER GUI LAN %d  ",TransData);
  spiTransReceiveString(Master_transmit,Master_Receive,20);
  printf("%s\n", Master_Receive);
  TransData++;
  delay(3000);
}

