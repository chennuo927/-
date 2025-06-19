#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
	int num,age;
	char name[10],sex[10],brithday[20],phonenum[20],emali[20],address[20];
};
int count=0;
void creatfile()
{
	FILE *p;
	if((p=fopen("stuinf.txt","w"))==NULL)
	{
		printf("FILE OPEN ERROR!");
	}
	fclose(p);
}
void load(struct stu node[])
{
	FILE *p;
	if((p=fopen("stuinf.txt","r"))==NULL)
	{
		printf("FILE OPEN ERROR!");
		return;
	}
	while(!feof(p))
	{
		fscanf(p,"%d%s%d%s%s%s%s%s",&node[count].num,node[count].name,&node[count].age,node[count].sex,node[count].brithday,node[count].address,node[count].phonenum,node[count].emali);
		count++;		
	}
	printf("����ɹ�!\n");
	fclose(p);
}
void save(struct stu node[])
{
	FILE *p;
	if((p=fopen("stuinf.txt","w"))==NULL)
	{
		printf("FILE OPEN ERROR!");
	}
	for(int i=0;i<count;i++)
	{
		fprintf(p,"%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t\n",node[i].num,node[i].name,node[i].age,node[i].sex,node[i].brithday,node[i].address,node[i].phonenum,node[i].emali);
	}
	fclose(p);
}
void add(struct stu node[])
{
	int t;
	printf("������ѧ�������Ϣ:\n");
	printf("ѧ��:");
	scanf("%d",&node[count].num);
	printf("����:");
	scanf("%s",node[count].name);
	printf("����:");
	while(1)
	{
		scanf("%d",&node[count].age);
		if(node[count].age<100)
		{
		 	break;	
		}
		else
		{
			printf("���ݲ�����,����������\n");
		}
	}
	printf("�Ա�:\n");
	printf("1---------��\n");
	printf("2---------Ů\n");
	while(1)
	{
		scanf("%d",&t);
		if(t==1)
		{
			strcpy(node[count].sex,"male");
			break;
		}
		if(t==2)
		{
			strcpy(node[count].sex,"female");
			break;
		}
		else
		{
			printf("��������,����������\n");
		}
	}
	printf("��������:");
	scanf("%s",node[count].brithday);
	printf("��ַ:");
	scanf("%s",node[count].address);
	printf("�绰:");
	scanf("%s",node[count].phonenum);
	printf("��������:");
	scanf("%s",node[count].emali);
	count++;
}
void deleteinf(struct stu node[])
{
	int num,index,i;
	printf("��������Ҫɾ�����˵�ѧ��:");
	scanf("%d",&num);
	for(i=0;i<count;i++)
	{
		if(num==node[i].num)
		{
			index=i;
			break;
		}
	}
	if(i>=count)
	{
		printf("�����ڸ�ѧ��");
		return;	
	}
	for(int j=index;j<=count-1;j++)
	{
		node[j]=node[j+1];
	}
	count=count-1;
}
void search(struct stu node[])
{
	printf("1---------������ѯ\n");
	printf("2---------ѧ�Ų�ѯ\n");
	int t,i,index,num;
	char name[50];
	scanf("%d",&t);
	if(t==1)
	{
		printf("����������:");
		scanf("%s",name);
		for(i=0;i<count;i++)
		{
			if((strcmp(node[i].name,name))==0)
			{
				index=i;
				break;
			}
		}
		if(i>=count)
		{
			printf("���޴���\n");
		}
		else
		{
			printf("ѧ��\t����\t����\t�Ա�\t��������\t��ͥסַ\t�绰����\t��������\t\n");
			printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t\n",node[index].num,node[index].name,node[index].age,node[index].sex,node[index].brithday,node[index].address,node[index].phonenum,node[index].emali);
		}	
	}
	if(t==2)
	{
		printf("�������ѯѧ��:");
		scanf("%d",&num);
		for(i=0;i<count;i++)
		{
			if(num==node[i].num)
			{
				index=i;
				break;
			}
		}
		if(i>=count)
		{
			printf("���޴���\n");	
		}
		else
		{
			printf("ѧ��\t����\t����\t�Ա�\t��������\t��ͥסַ\t�绰����\t��������\t\n");
			printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t\n",node[index].num,node[index].name,node[index].age,node[index].sex,node[index].brithday,node[index].address,node[index].phonenum,node[index].emali);
		}
	}
	
}
void modify(struct stu node[])
{
	printf("������Ҫ�޸��˵�ѧ��:\n");
	int num,i,index;
	scanf("%d",&num);
	for(i=0;i<count;i++)
	{
		if(num==node[i].num)
		{
			index=i;
			break;
		}
	}
	if(i>=count)
	{
		printf("���޴���\n");
		return;	
	}
	printf("1.�޸�����,2.�޸�����,3.�޸��Ա�,4.�޸�����,5.�޸�סַ,6.�޸ĵ绰,7.�޸�����,0.�˳�\n");
	int t;
	scanf("%d",&t);
	while(1)
	{
		switch (t) {
			case 1:
				char name[20];
				printf("����������\n");
				scanf("%s",name);
				strcpy(node[index].name,name);
				break;
			case 2:
				int age;
				printf("�������䣺\n");
				scanf("%d",&age);
				node[index].age=age;
				break;
			case 3:
				int a;
				printf("�����Ա�\n");
				printf("1-----------��\n");
				printf("2-----------Ů\n");
				while(1)
				{
					scanf("%d",&a);
					if(a==1)
					{
						strcpy(node[index].sex,"male");
						break;
					}
					if(a==2)
					{
						strcpy(node[index].sex,"female");
						break;
					}
				}
				break;
				case 4:
					printf("��������\n");
					char brith[40];
					scanf("%s",brith);
					strcpy(node[index].brithday,brith);
					break;
				case 5:
					printf("����סַ\n");
					char address[50];
					scanf("%s",address);
					strcpy(node[index].address,address);
					break;
				case 6:
					printf("����绰\n");
					char phone[50];
					scanf("%s",phone);
					strcpy(node[i].phonenum,phone);
					break;
				case 7:
					printf("��������\n");
					char emali[30];
					scanf("%s",emali);
					strcpy(node[index].emali,emali);	
				case 0:
					return;		
		}
	}
}
void listall(struct stu node[])
{
	printf("ѧ��\t����\t����\t�Ա�\t��������\t��ͥסַ\t�绰����\t��������\t\n");
	for(int i=0;i<count;i++)
	{
		printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t\n",node[i].num,node[i].name,node[i].age,node[i].sex,node[i].brithday,node[i].address,node[i].phonenum,node[i].emali);		
	}
}
int main ()
{
	
	struct stu node[1000];
	int n;
	while(1){
		printf("��ӭʹ��ѧ����Ϣ����ϵͳ��\n");
		printf("******1.��Ϣ¼��********\n");
		printf("******2.��Ϣ��ʾ********\n");
		printf("******3.��Ϣ��ѯ********\n");
		printf("******4.��Ϣɾ��********\n");
		printf("******5.��Ϣ�޸�********\n");
		printf("******6.���������ļ�****\n");
		printf("******7.���߼������Ϣ**\n");
		printf("******0.�˳�************\n");
		scanf("%d",&n);
		switch (n) {
			case 1:
				if(count==999)
				{
					printf("�������\n");	
				}
				add(node);
				save(node);
				system("pause");
				system("cls");
				break;
			case 2:
				listall(node);
				system("pause");
				system("cls");
				break;
			case 3:
				search(node);
				system("pause");
				system("cls");
				break;
			case 4:
				deleteinf(node);
				save(node);
				system("pause");
				system("cls");
				break;
			case 5:
				modify(node);
				save(node);
				system("pause");
				system("cls");
				break;
			case 6:
				load(node);
				system("pause");
				system("cls");
				break;	
			case 7:
				printf("���ߣ���־Զ\n");
				printf("�������QQ:3169243027\n");
				system("pause");
				system("cls");
				break;
			case 0:
				printf("ллʹ��ѧ����Ϣ����ϵͳ��\n");
				return 0;	
	}
	}
}
