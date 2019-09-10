#include "usmart.h"
#include "usmart_str.h"

#include "led.h"
#include "delay.h"
#include "mypwm.h"

extern void mode_change(uint8_t modee);
extern void mode7_change(float mode7_centerr);
extern void mode2_change(uint8_t mode_2_counttt);

//�������б���ʼ��(�û��Լ�����)
//�û�ֱ������������Ҫִ�еĺ�����������Ҵ�
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//���ʹ���˶�д����
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif		   
	(void*)delay_ms,"void delay_ms(u16 xms)",
 	(void*)delay_us,"void delay_us(u32 xus)",	
	(void*)LED_RED_DEBUG, "void LED_RED_DEBUG(bool a)",
	(void*)LED_BLUE_DEBUG, "void LED_BLUE_DEBUG(bool a)",
	(void*)LED_GREEN_DEBUG, "void LED_GREEN_DEBUG(bool a)",
	(void*)mode_change, "void mode_change(uint8_t modee)",
	(void*)mode7_change, "void mode7_change(float mode7_centerr)",
	(void*)mode2_change, "void mode2_change(uint8_t mode_2_counttt)",
};	




//�������ƹ�������ʼ��
//�õ������ܿغ���������
//�õ�����������
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//��������
	0,	  	//��������
	0,	 	//����ID
	1,		//������ʾ����,0,10����;1,16����
	0,		//��������.bitx:,0,����;1,�ַ���	    
	0,	  	//ÿ�������ĳ����ݴ��,��ҪMAX_PARM��0��ʼ��
	0,		//�����Ĳ���,��ҪPARM_LEN��0��ʼ��
};

