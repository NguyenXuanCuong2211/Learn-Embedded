/*
  Author: Nguyen Xuan Cuong
  SPI library
*/
// SLAVE SPI Programming
#include "stdio.h"
#define SS_PIN 5   // Pin kết nối SS (Slave Select)
#define MOSI_PIN 21 // Pin kết nối MOSI
#define MISO_PIN 19 // Pin kết nối MISO
#define SCK_PIN 18  // Pin kết nối SCK

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
            pinMode(SS_PIN, INPUT);     // Chân SS là INPUT
            pinMode(MOSI_PIN, INPUT);   // Chân MOSI là INPUT
            pinMode(MISO_PIN, OUTPUT);  // Chân MISO là OUTPUT
            pinMode(SCK_PIN, INPUT);    // Chân SCK là INPUT
            digitalWrite(MISO_PIN, 0);
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
        if(digitalRead(SS_PIN)==0)
        {
          for(int i=0;i<8;i++)
          {
          if(data&MoveByte)
          {
            digitalWrite(MISO_PIN, 1);
          }
          else digitalWrite(MISO_PIN, 0);
          while(digitalRead(SCK_PIN)==0)
          if(digitalRead(MOSI_PIN))
          {
              ReceiveByte = ReceiveByte|MoveByte;
          }
          while(digitalRead(SCK_PIN)==1)
          MoveByte = MoveByte >>1;
          }
        }
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
  uint8_t SLAVE_Transmit[20];
  uint8_t SLAVE_Receive[20];
  snprintf((char*)SLAVE_Transmit,sizeof(SLAVE_Transmit),"MASTER GUI LAN %d  ",TransData);
  spiTransReceiveString(SLAVE_Transmit,SLAVE_Receive,20);
  printf("%s\n", SLAVE_Receive);
  TransData++;
  delay(3000);
}
