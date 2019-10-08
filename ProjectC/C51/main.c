/*******************************************************************************
* ʵ����			   :LCD��ʾʵ��
* ʹ�õ�IO	     : 
* ʵ��Ч��       :1602��ʾ�¶ȡ���ֵ
*  ע��		     ��reg51.h��reg52.h��ʹ��
*******************************************************************************/

#include<reg51.h>
#include"lcd.h"
#include"temp.h"
#include"XPT2046.h"
//#include"studio.h"


typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit beep=P1^5;
//sbit moto=P1^0;

uchar CNCHAR[6] = "���϶�";
void LcdDisplay();
void delay(u16 i);
void beepY();
void Dimension();

/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������i=1ʱ����Լ��ʱ10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);	
}


/*******************************************************************************
* �� �� ��         : beepY
* ��������		   : ����������
*******************************************************************************/
void beepY()
{
	u8 i;
	for(i=0;i<100;i++)
	{
	beep=~beep;
	delay(90);
	}
	beep=0;
	delay(1000);	
}


/*******************************************************************************
* ������         : LcdDisplay()
* ��������		   : LCD��ʾ��ȡ�����¶�
* ����           : v
* ���         	 : ��
*******************************************************************************/
void LcdDisplay() 	 //lcd��ʾ
{
    int temp;
	u16 temp1;
  	unsigned char datas[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //��������
	float tp;  
	u16 ADC,ADC1;
	static u8 i;
	temp=Ds18b20ReadTemp(); 	
	  	LcdWriteCom(0x80+0x40);		//д��ַ 80��ʾ��ʼ��ַ
	    LcdWriteData('+'); 		//��ʾ��
		SBUF='+';//�����յ������ݷ��뵽���ͼĴ���
		while(!TI);			         //�ȴ������������
		TI=0;						 //���������ɱ�־λ
		tp=temp;//��Ϊ���ݴ�����С�������Խ��¶ȸ���һ�������ͱ���
		//����¶���������ô����ô������ԭ����ǲ���������
		temp=tp*0.0625*100+0.5;	
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
		ADC1 = Read_AD_Data(0x94);		//   AIN0 ��λ��
//		ADC = ADC1*0.75;

//		temp1 = Read_AD_Data(0xE4);		//   AIN3 �ⲿ����

	if(i==3)
	{
		i=0;
		temp1 = Read_AD_Data(0xE4);		//   AIN3 �ⲿ����
//		temp1 = temp1-1250;
//		temp1 = temp1/6.21;
		ADC = ADC1*0.75;
		if(temp1>=1200)
	{
	   LcdWriteCom(0x8C+0x40);		 //д��ַ 80��ʾ��ʼ��ַ
	   LcdWriteData('+'); //��ʾС����һλ
	   temp1 = temp1-1200;
	   temp1 = temp1/6.21-3;
	}
	else
	{
	   	LcdWriteCom(0x8C+0x40);		 //д��ַ 80��ʾ��ʼ��ַ
	    LcdWriteData('-'); //��ʾС����һλ
		temp1 = temp1-1033;
		temp1 = temp1/3.7;
		temp1 = temp1+45-3;
		if(temp1>100) temp1 = 45; 
	}
	}
	i++;


	
	datas[0] = temp / 10000;			  //��λ
	datas[1] = temp % 10000 / 1000;		  //ʮλ
	datas[2] = temp % 1000 / 100;		  //��λ
	datas[3] = temp % 100 / 10;
	datas[4] = temp % 10;
	datas[5] = ADC / 1000;		  //��λ
	datas[6] = ADC % 1000 / 100;		  //ʮλ
	datas[7] = ADC % 100 / 10;			  //��λ
	datas[8] = ADC % 10;				 //С�����һλ
	datas[9] = temp1/1000;//ǧλ
	datas[10] = temp1%1000/100;//��λ
	datas[11] = temp1%1000%100/10;//ʮλ
	datas[12] = temp1%1000%100%10;//��λ

/*��һ����ʾ�¶�ֵ*/
	LcdWriteCom(0x81+0x40);		  //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[0]); //��λ 
	
	LcdWriteCom(0x82+0x40);		 //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[1]); //ʮλ

	LcdWriteCom(0x83+0x40);		//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[2]); //��λ 

	LcdWriteCom(0x84+0x40);		//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('.'); 		//��ʾ ��.��

	LcdWriteCom(0x85+0x40);		 //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[3]); //��ʾС����һλ  

/*�ڶ�����ʾ����ֵ*/
	LcdWriteCom(0x81);		  //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[5]); //��λ 
		
	LcdWriteCom(0x82);		 //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[6]); //ʮλ

	LcdWriteCom(0x83);		//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[7]); //��λ 

	LcdWriteCom(0x84);		//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('.'); 		//��ʾ ��.��

	LcdWriteCom(0x85);		 //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[8]); //��ʾС����һλ  


/*�Ҳ���ʾ������*/
//	LcdWriteCom(0x8C+0x40);		  //д��ַ 80��ʾ��ʼ��ַ
//	LcdWriteData('0'+datas[9]); //��ʾǧλ
	
	LcdWriteCom(0x8D+0x40);		 //д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[10]); //��ʾ��λ

	LcdWriteCom(0x8E+0x40);		//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[11]); //��ʾʮλ 

	LcdWriteCom(0x8F+0x40);		//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('0'+datas[12]); //��ʾ��λ


	 
}



/*******************************************************************************
* �� �� ��         :Dimension()
* ��������		   :��λ��ʾ
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void Dimension()
{
	LcdWriteCom(0x87+0x40);	//д��ַ 80��ʾ��ʼ��ַ
	LcdWriteData('C');
	LcdWriteCom(0x8D);	
	LcdWriteData('X');	
	LcdWriteCom(0x8E);
	LcdWriteData('-');	
	LcdWriteCom(0x8F);	
	LcdWriteData('Z');	 
	LcdWriteCom(0x87);	
	LcdWriteData('P');
	LcdWriteCom(0x88);	
	LcdWriteData('P');
	LcdWriteCom(0x89);	
	LcdWriteData('M');
}

/*******************************************************************************
* ������         : main
* ��������		   : ������
* ����           : ��
* ���         	 : ��
*******************************************************************************/
void main()
{

	u16 adc,adc1;
	int i=0;
	LcdInit();			 //��ʼ��LCD1602
	Dimension();
//	moto=0;			//�رյ��
/*	for(i=0;i<100;i++)	  //ѭ��100�Σ�Ҳ���Ǵ�Լ5S
	{
		moto=1;			 //�������
		delay(5000);	//��Լ��ʱ50ms
	}
	moto=0;			//�رյ�� */
	while(1)
	{
	 	adc1=Read_AD_Data(0x94);
	    adc=adc1*0.75;
		LcdDisplay();
//		moto=0;
		if(adc>=2000)	
		{
		beepY(); 
//      moto=1;
		i++;
		}
	}		  
}				
