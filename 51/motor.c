#include <REGX52.H>
sbit  A1 = P1^0;
sbit  A2 = P1^1;
sbit  B1 = P1^2;
sbit  B2 = P1^3;
sbit  C1 = P1^4;
sbit  C2 = P1^5;
sbit  D1 = P1^6; 
sbit  D2 = P1^7;
//void LeftForward(void)//×óÂÖÇ°½ø
//{
//	A1=0;
//	A2=1;
//	C2=0;
//	C1=1;
//}
//void Lefttreat(void)//×óÂÖºóÍË
//{
//	A1=0;
//	A2=1;
//	C2=0;
//	C1=1;
//}
void GoForward(void)
{
	A1=0;
	A2=1;
	C2=0;
	C1=1;
	B1=1;
	B2=0;
	D1=0;
	D2=1;
}

void GoLeft(void)
{
	A1=0;
	A2=0;
	C2=0;
	C1=0;
	B1=0;
	B2=1;
	D1=1;
	D2=0;
	
}


void GoRight(void)
{
	A1=1;
	A2=0;
	C2=1;
	C1=0;
	B1=0;
	B2=0;
	D1=0;
	D2=0;
	
	
}
void GoRetreat(void)
{
	A1=1;
	A2=0;
	C2=1;
	C1=0;
	B1=0;
	B2=1;
	D1=1;
	D2=0;
	
	
}
void Stop(void)
{
	A1=0;
	A2=0;
	C2=0;
	C1=0;
	B1=0;
	B2=0;
	D1=0;
	D2=0;
	
	
}

