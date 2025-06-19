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
	printf("导入成功!\n");
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
	printf("请输入学生相关信息:\n");
	printf("学号:");
	scanf("%d",&node[count].num);
	printf("姓名:");
	scanf("%s",node[count].name);
	printf("年龄:");
	while(1)
	{
		scanf("%d",&node[count].age);
		if(node[count].age<100)
		{
		 	break;	
		}
		else
		{
			printf("数据不合理,请重新输入\n");
		}
	}
	printf("性别:\n");
	printf("1---------男\n");
	printf("2---------女\n");
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
			printf("输入有误,请重新输入\n");
		}
	}
	printf("出生年月:");
	scanf("%s",node[count].brithday);
	printf("地址:");
	scanf("%s",node[count].address);
	printf("电话:");
	scanf("%s",node[count].phonenum);
	printf("电子邮箱:");
	scanf("%s",node[count].emali);
	count++;
}
void deleteinf(struct stu node[])
{
	int num,index,i;
	printf("请输入所要删除的人的学号:");
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
		printf("不存在该学号");
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
	printf("1---------姓名查询\n");
	printf("2---------学号查询\n");
	int t,i,index,num;
	char name[50];
	scanf("%d",&t);
	if(t==1)
	{
		printf("请输入姓名:");
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
			printf("查无此人\n");
		}
		else
		{
			printf("学号\t姓名\t年龄\t性别\t出生年月\t家庭住址\t电话号码\t电子邮箱\t\n");
			printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t\n",node[index].num,node[index].name,node[index].age,node[index].sex,node[index].brithday,node[index].address,node[index].phonenum,node[index].emali);
		}	
	}
	if(t==2)
	{
		printf("请输入查询学号:");
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
			printf("查无此人\n");	
		}
		else
		{
			printf("学号\t姓名\t年龄\t性别\t出生年月\t家庭住址\t电话号码\t电子邮箱\t\n");
			printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t\n",node[index].num,node[index].name,node[index].age,node[index].sex,node[index].brithday,node[index].address,node[index].phonenum,node[index].emali);
		}
	}
	
}
void modify(struct stu node[])
{
	printf("请输入要修改人的学号:\n");
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
		printf("查无此人\n");
		return;	
	}
	printf("1.修改姓名,2.修改年龄,3.修改性别,4.修改生日,5.修改住址,6.修改电话,7.修改邮箱,0.退出\n");
	int t;
	scanf("%d",&t);
	while(1)
	{
		switch (t) {
			case 1:
				char name[20];
				printf("输入姓名：\n");
				scanf("%s",name);
				strcpy(node[index].name,name);
				break;
			case 2:
				int age;
				printf("输入年龄：\n");
				scanf("%d",&age);
				node[index].age=age;
				break;
			case 3:
				int a;
				printf("输入性别：\n");
				printf("1-----------男\n");
				printf("2-----------女\n");
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
					printf("输入生日\n");
					char brith[40];
					scanf("%s",brith);
					strcpy(node[index].brithday,brith);
					break;
				case 5:
					printf("输入住址\n");
					char address[50];
					scanf("%s",address);
					strcpy(node[index].address,address);
					break;
				case 6:
					printf("输入电话\n");
					char phone[50];
					scanf("%s",phone);
					strcpy(node[i].phonenum,phone);
					break;
				case 7:
					printf("输入邮箱\n");
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
	printf("学号\t姓名\t年龄\t性别\t出生年月\t家庭住址\t电话号码\t电子邮箱\t\n");
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
		printf("欢迎使用学生信息管理系统！\n");
		printf("******1.信息录入********\n");
		printf("******2.信息显示********\n");
		printf("******3.信息查询********\n");
		printf("******4.信息删除********\n");
		printf("******5.信息修改********\n");
		printf("******6.导入已有文件****\n");
		printf("******7.作者及相关信息**\n");
		printf("******0.退出************\n");
		scanf("%d",&n);
		switch (n) {
			case 1:
				if(count==999)
				{
					printf("错误溢出\n");	
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
				printf("作者：后志远\n");
				printf("更多服务：QQ:3169243027\n");
				system("pause");
				system("cls");
				break;
			case 0:
				printf("谢谢使用学生信息管理系统！\n");
				return 0;	
	}
	}
}
