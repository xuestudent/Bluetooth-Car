#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
#include "Motor.h"

typedef unsigned char u8;


//int Leftspeed = 0;//左轮速度
//int Rightspeed = 0;//右轮速度
//int Lcounter = 0;
//int Rcounter = 0;
u8 receivedate = 0;//接收串口数据
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


//void Timer0_Routine()  interrupt 1//中断之后直接跳到该程序
//{

//	TL0 = 0xA4;				//设置定时初始值
//	TH0 = 0xFF;				//设置定时初始值
//  Lcounter++;
//	Lcounter%=100;	//Counter加到100清零
//	if(Lcounter<Leftspeed)//占空比
//	{
//		
//	}
//	else
//	{
//		
//	}
//}


//void Timer1_Routine()  interrupt 3//中断之后直接跳到该程序
//{

//	TL0 = 0xA4;				//设置定时初始值
//	TH0 = 0xFF;				//设置定时初始值
//  Rcounter++;
//	Rcounter%=100;	//Counter加到100清零
//	if(Rcounter<Rightspeed)//占空比
//	{
//		
//	}
//	else
//	{
//		
//	}
//}

void UART_Routine()    interrupt 4//串口中断函数 
{
	   if(RI==1)
		{
			receivedate=SBUF;//反转
			USART_SendByte(SBUF);
			RI=0;//发送接收置一之后要清零
		}
}


