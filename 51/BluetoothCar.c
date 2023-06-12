#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
#include "Motor.h"

typedef unsigned char u8;


//int Leftspeed = 0;//�����ٶ�
//int Rightspeed = 0;//�����ٶ�
//int Lcounter = 0;
//int Rcounter = 0;
u8 receivedate = 0;//���մ�������
void main()
{
	UartInit();
//   Timer_Init();
	 
    while(1)
  {
				switch(receivedate)
				{
					case 0x11:
						GoRetreat();
						Delay(10);
					  break;	
					case 0x12:
						GoLeft();
					  Delay(10);
   					break;
					case 0x13:
						GoRight();
						Delay(10);
					  break;
					case 0x14:
					  GoForward();
					  Delay(10);
					  break;
					case 0x15:
						Stop();
					  break;
				}
		
	
  }


}


//void Timer0_Routine()  interrupt 1//�ж�֮��ֱ�������ó���
//{

//	TL0 = 0xA4;				//���ö�ʱ��ʼֵ
//	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
//  Lcounter++;
//	Lcounter%=100;	//Counter�ӵ�100����
//	if(Lcounter<Leftspeed)//ռ�ձ�
//	{
//		
//	}
//	else
//	{
//		
//	}
//}


//void Timer1_Routine()  interrupt 3//�ж�֮��ֱ�������ó���
//{

//	TL0 = 0xA4;				//���ö�ʱ��ʼֵ
//	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
//  Rcounter++;
//	Rcounter%=100;	//Counter�ӵ�100����
//	if(Rcounter<Rightspeed)//ռ�ձ�
//	{
//		
//	}
//	else
//	{
//		
//	}
//}

void UART_Routine()    interrupt 4//�����жϺ��� 
{
	   if(RI==1)
		{
			receivedate=SBUF;//��ת
			USART_SendByte(SBUF);
			RI=0;//���ͽ�����һ֮��Ҫ����
		}
}


