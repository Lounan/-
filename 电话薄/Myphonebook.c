#define _CRT_SECURE_NO_WARNINGS

#include "Myphonebook.h"

int main(void)
{
	int flag;
	while(1)
	{
		printf("\n\n\t----------�绰��-----------\t\n");
		printf("\t-------1.�鿴��ϵ��---------\t\n");
		printf("\t-------2.�����ϵ��---------\t\n");
		printf("\t-------3.������ϵ��---------\t\n");
		printf("\t-------4.ɾ����ϵ��---------\t\n");
		printf("\t-------5.����/�س���ϵ��----\t\n");
		printf("\t-------0.�˳�ϵͳ-----------\t\n");
		printf("��������ţ�");
		fflush(stdin);
		scanf("%d",&flag);
		switch(flag)
		{
		case 1:while(1)
			{
				show();
				printf("��'q'���˳�");
				fflush(stdin);
				scanf("%c",&flag);
				if(flag == 'q')
				break;
				else error_order();//������س���������
			 } break;
		case 2: create();break;
		case 3:seek();break;
		case 4: del():break;

			
		}
	}
}

void show()
{

	INODE *p = h;
	char flag;
	while(p->next) 
	{
		printf("%s\t%s\n",p->name,p->phone_num);
		p = p->next;
	}
	printf("����%d����ϵ��  \n",amount);

}

INODE * create()
{
	 INODE * p = (INODE *)malloc(sizeof(INODE));

	 printf("��������ϵ��������");
	 fflush(stdin);
	 scanf("%s",p->name);
	 printf("��������ϵ�˵绰��");
	 fflush(stdin);
	 scanf("%s",p->phone_num);
      
	 p->next = h->next;
	 h->next = p;
	 amount++;
	 return p;
}

void del(INODE *obj)
{

}
INODE * seek()
{
	INODE * p = h;
	int flag ;
	INF temp;
	char sign;
	int i = 0;
	printf("\t-------1.�����ֲ���----\t\n");
	printf("\t-------2.���绰����----\t\n");
	fflush(stdin);
	scanf("%d",&flag);
	if(flag == 1)
	{
		printf("������Ҫ���ҵ�������");
		fflush(stdin);
		scanf("%s",temp.name);
		while(p->next)
		{
			if(strcmp(p->name,temp.name)== 0)
				printf("%s\t%s\n",  p->name,p->phone_num);
			i = 1;
		}
		if(i == 0)
		{
			printf("δ�ҵ����ˣ��Ƿ��½�����Y/N��");
			fflush(stdin);
			scanf("%c",&sign);
			if(sign == 'Y') create();
			else if(sign == 'N') return;
			else error_order();
		}
	}
	else if(flag == 2)
	{
		printf("������Ҫ���ҵĵ绰���룺");
		fflush(stdin);
		scanf("%s",temp.phone_num);
		while(p->next)
		{
			if(strcmp(p->phone_num,temp.phone_num)== 0)
				printf("%s\t%s\n",  p->name,p->phone_num);
			i = 1;
		}
		if(i == 0)
		{
			printf("δ�ҵ�����绰���룡�Ƿ��½��õ绰����Y/N��");
			fflush(stdin);
			scanf("%c",&sign);
			if(sign == 'Y') create();
			else if(sign == 'N') return;
			else error_order();
		}	
	}
	return p;
}

void error_order()
{
	printf("��������ȷ��ָ�");
}