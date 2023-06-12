#include <REGX52.H>



void UartInit(void)		//9600bps@11.0592MHz
{
    TMOD=0x20;      //设置计数器1的工作方式2
    TH1=0xfd;	    //设置计数器1的初值，决定波特率
    TL1=0xfd;		//设置计数器1的初值，决定波特率
    PCON=0x00;      // 波特率倍增0x00不加倍	 0x80加倍
    SCON=0x50;		//设置工作方式1 开启接受允许
    EA=1;		    //开启总中断
    ES=1;			//开启串口接受中断
    TR1=1;			//计数器1开始运行
}

void USART_SendByte(unsigned char Byte)//USART发送字符
{
	SBUF=Byte;//把数据写到SBUF寄存器
	while(TI==0);//直到发送控制器标志位置1（TI为1表示有数据）
	TI=0;//TI标志位，置1之后软件置0
}
