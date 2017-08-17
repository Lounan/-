#define _CRT_SECURE_NO_WARNINGS

#include "Myphonebook.h"

int main(void)
{
	int flag;
	while(1)
	{
		printf("\n\n\t----------电话薄-----------\t\n");
		printf("\t-------1.查看联系人---------\t\n");
		printf("\t-------2.添加联系人---------\t\n");
		printf("\t-------3.查找联系人---------\t\n");
		printf("\t-------4.删除联系人---------\t\n");
		printf("\t-------5.载入/载出联系人----\t\n");
		printf("\t-------0.退出系统-----------\t\n");
		printf("请输入序号：");
		fflush(stdin);
		scanf("%d",&flag);
		switch(flag)
		{
		case 1:while(1)
			{
				show();
				printf("按'q'以退出");
				fflush(stdin);
				scanf("%c",&flag);
				if(flag == 'q')
				break;
				else error_order();//可添加载出和排序功能
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
	printf("共有%d个联系人  \n",amount);

}

INODE * create()
{
	 INODE * p = (INODE *)malloc(sizeof(INODE));

	 printf("请输入联系人姓名：");
	 fflush(stdin);
	 scanf("%s",p->name);
	 printf("请输入联系人电话：");
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
	printf("\t-------1.按名字查找----\t\n");
	printf("\t-------2.按电话查找----\t\n");
	fflush(stdin);
	scanf("%d",&flag);
	if(flag == 1)
	{
		printf("请输入要查找的姓名：");
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
			printf("未找到此人！是否新建此人Y/N？");
			fflush(stdin);
			scanf("%c",&sign);
			if(sign == 'Y') create();
			else if(sign == 'N') return;
			else error_order();
		}
	}
	else if(flag == 2)
	{
		printf("请输入要查找的电话号码：");
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
			printf("未找到这个电话号码！是否新建该电话号码Y/N？");
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
	printf("请输入正确的指令！");
}