#include <REGX52.H>


void Timer1_Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0xA4;				//���ö�ʱ��ʼֵ
	TH1 = 0xFF;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
}


void Timer0_Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0xA4;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0=1;//�����жϵļĴ���
	EA=1;//�����жϵļĴ���
  PT0=0;//�������ȼ��Ĵ���
}


void Timer_Init(void)
{
	Timer0_Init();
	Timer1_Init();
}




	
