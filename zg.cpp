/************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: zg.cpp
Author: yxm
Date:2018.6.29
Description: 十大板块对应十个功能 // 模块描述
Version: 6.0 // 版本信息
Function List: // 主要函数及其功能
1. add（）添加职工资料
2. write（）保存职工资料
3. read（）导入数据
4 list（）浏览职工资料
5. del（）删除职工资料
6. find（）函数查找职工资料
7. modify（）修改职工资料
8. grsds（）计算税率
9.menu（）菜单界面
10.main（）主函数

-------
History: // 历史修改记录
David 201/06/29 1.0 build this moudle
***********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct worker
{
		char num[10];         //工号
		char name[10];   //姓名
		float gwgz;        //岗位工资
		float xjgz;       //薪级工资
		float zwjt;          //职务津贴
		float jxgz;         //绩效工资
		float yfgz;        //应发工资 
		float sds;           //个人所得税
		float sfgz;         //实发工资
}zggz[100];  

int n = 0;//职工的总人数
int i = 0;
int flag = 0;
     
void grsds(float yfgz,int i);
/***********************************************************
Function: // add

Description: // 添加职工数据

Called By: // main()

Input: // 键盘键入职工数据

Output: // 将数据存入zggz[]

***********************************************************/


void add(struct worker zggz[100])   //添加
{
	n++;
	printf("请输入职工号：\n");
	scanf("%s",zggz[n].num);
	printf("请输入职工姓名：\n");
	scanf("%s",zggz[n].name);
	printf("请输入职工岗位工资：\n");
	scanf("%f",&zggz[n].gwgz);
	printf("请输入职工薪级工资：\n");
	scanf("%f",&zggz[n].xjgz);
	printf("请输入职工职务津贴：\n");
	scanf("%f",&zggz[n].zwjt);
	printf("请输入职工绩效工资：\n");
	scanf("%f",&zggz[n].jxgz);
	zggz[n].yfgz = zggz[n].gwgz + zggz[n].xjgz + zggz[n].zwjt + zggz[n].jxgz;
	grsds(zggz[n].yfgz,n);
    zggz[n].sfgz = zggz[n].yfgz - zggz[n].sds;
	
	printf("职工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n"); 
	printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[n].num,zggz[n].name,zggz[n].gwgz,
		zggz[n].xjgz,zggz[n].zwjt,zggz[n].jxgz,zggz[n].yfgz,zggz[n].sds,zggz[n].sfgz);
	printf("添加成功\n");
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}
/***********************************************************
Function: // write

Description: // 保存职工工资数据函数

Called By: // main()

Output: // 将zggz[]数据存入本地文件

***********************************************************/
void write(struct worker zggz[100])  //保存文件
{
	FILE*fp;   
	if(n > 0)
	{
		if ((fp=fopen("gx.dat","wb"))==NULL) 
		{
				printf ("文件打开失败\n");
				fclose(fp);
				exit(0);
		}
		for (i=1;i<n+1;i++) 
		{
			fprintf(fp,"%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[i].num,zggz[i].name,
				zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
		}
				
		fclose(fp);
		printf("保存数据成功\n");
	}
	else
	{
		printf("当前没有数据可以保存\n");
	}
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}
/***********************************************************
Function: // read

Description: // 读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数

Called By: // main()

Input: // 本地文件的读取

Output: // 将本地文件数据存入zggz[]

Return: // 函数返回值的说明
***********************************************************/
void read(struct worker zggz[100]) //导入数据
{
	FILE*fp;
	n = 0;
	if((fp=fopen("gx.dat","a+"))==NULL)
	{ 
			printf ("文件打开失败\n");
			fclose(fp);
			exit(0);
	}
	else
	{
		
		while(!feof(fp))
		{
			n++;
			fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zggz[n].num,zggz[n].name,&zggz[n].gwgz,
				&zggz[n].xjgz,&zggz[n].zwjt,&zggz[n].jxgz,&zggz[n].yfgz,&zggz[n].sds,&zggz[n].sfgz);
		} 
	
		fclose(fp);
		printf("导入数据成功\n");
		printf("按回车键退出\n");
		getchar();
		getchar();
		return ;
	}
}
/***********************************************************
Function: // list

Description: //浏览职工工资数据函数

Called By: // main()

Output: // 输出全部职工数据

***********************************************************/
void list(struct worker zggz[100])  //浏览
{
	printf("职工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n"); 
	for(i=1;i<n+1;i++)
	{
		printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[i].num,zggz[i].name,
			zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
	}
     
	printf("\n按回车键退出\n");
	getchar();
	getchar();
	return ;
}
/***********************************************************
Function: // del

Description: //删除职工工资数据函数

Called By: // main()

Input: // 键盘键入工号

Output: // 修改zggz[]数据
***********************************************************/
void del(struct worker zggz[100])   //删除
{
	char gonghao[10] = {0};
	char ch[2] = {0};
	int j = 0;
	printf("请输入要删除的职工号:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			flag = 1;
			break;

		}
	}
	if(flag == 1)
	{
		printf("是否删除：(y/n)\n");
		while(1)
		{
			scanf("%s",ch);
			if(strcmp(ch,"y") == 0)
			{
				for(j=i;j<n;j++)
				{
					strcpy(zggz[j].num,zggz[j+1].num);
					strcpy(zggz[j].name,zggz[j+1].name);
					zggz[j].gwgz=zggz[j+1].gwgz;
					zggz[j].xjgz=zggz[j+1].xjgz;
					zggz[j].zwjt=zggz[j+1].zwjt;
					zggz[j].jxgz=zggz[j+1].jxgz;
					zggz[j].yfgz=zggz[j+1].yfgz;
					zggz[j].sds=zggz[j+1].sds;
					zggz[j].sfgz=zggz[j+1].sfgz;
				}

				n--;
				break;
			}

			else if(strcmp(ch,"n") == 0)
			{
				break;
			}

			else
			{
				printf("输入错误，请重新输入\n");
			}
		}
	}
	else
	{
		printf("\n对不起,查无此人\n");
	}
		
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}

/***********************************************************
Function: // find

Description: // 查询职工工资数据函数

Called By: // main()

Input: // 键盘键入工号

Output: // 输出特定职工数据

***********************************************************/
void find(struct worker zggz[100])//查找
{
	char gonghao[10] = {0};
	printf("请输入要查找的职工号:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			printf("职工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n"); 
			printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f%% %2.1f\n",zggz[i].num,zggz[i].name,
				zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
			flag = 1;
			break;

		}
	}
	if(flag == 0)
	{		
		printf("\n对不起,查无此人\n");
	}
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;		
}
/***********************************************************
Function: //modify

Description: 	// 修改职工工资数据函数

Called By: // main()

Input: // 键盘键入工号


***********************************************************/

void modify(struct worker zggz[100]) //修改
{
    char gonghao[10] = {0};
	printf("请输入要修改的职工号:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			flag = 1;
			break;

		}
	}
	if(flag == 1)
	{
		printf("请输入职工号：\n");
		scanf("%s",zggz[i].num);
		printf("请输入职工姓名：\n");
		scanf("%s",zggz[i].name);
		printf("请输入职工岗位工资：\n");
		scanf("%f",&zggz[i].gwgz);
		printf("请输入职工薪级工资：\n");
		scanf("%f",&zggz[i].xjgz);
		printf("请输入职工职务津贴：\n");
		scanf("%f",&zggz[i].zwjt);
		printf("请输入职工绩效工资：\n");
		scanf("%f",&zggz[i].jxgz);
		zggz[i].yfgz = zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz;	
        zggz[i].sfgz = zggz[i].yfgz - zggz[i].sds;
	
	
		
		
		
	}
	else
	{
		printf("\n对不起,查无此人\n");
	}
		
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;

}
/***********************************************************
Function: // grsds

Description: // 个人所得税计算
Called By: // modify(), add()
***********************************************************/
void grsds(float yfgz,int i)
{    
     

	if (yfgz > 3500)
	{
		if(yfgz <= 4000)
		{
			zggz[i].sds = 0.05*(yfgz-3500);
		}
		else if(yfgz > 4000 && yfgz <= 6000)
		{
			zggz[i].sds = 0.05*(yfgz-3500)+0.1*(yfgz-4000);
		}
		else if(yfgz >6000 && yfgz <= 9000)
		{
		    zggz[i].sds = 0.05*500+0.1*2000+0.15*(yfgz-6000);
		}

		else if(yfgz > 9000 && yfgz <= 21000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*(yfgz-9000);
		}
		else if(yfgz > 21000 && yfgz <= 41000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*(yfgz-21000);
		}
		else if(yfgz > 41000 && yfgz <= 61000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*20000+0.30*(yfgz-41000);
		}else if(yfgz > 61000 && yfgz <= 81000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*20000+0.30*20000+0.35*(yfgz-61000);
		}
		else if(yfgz > 81000 && yfgz <= 101000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*15000+0.30*20000+0.35*20000+0.40*(yfgz-81000);
		}else if(yfgz > 101000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*15000+0.30*20000+0.35*20000+0.40*20000+0.45*(yfgz-101000);
		}
	}
	
     
	else
	{
		zggz[i].sds=0;
	}

}
/***********************************************************
 ***********************************************************/
void menu() //菜单界面
{
		printf("  ###欢迎使用广西民族大学软件与信息安全学院职工工资管理系统###  \n\n\n");
        printf("  请选择<1-7>:  \n");
        printf("  ============================================================ \n");
        printf("  |               1  查询职工工资记录                        | \n");
		printf("  |               2  修改职工工资记录                        | \n");
		printf("  |               3  添加职工工资记录                        | \n");
		printf("  |               4  删除职工工资记录                        | \n");
		printf("  |               5  保存数据到文件                          | \n");
		printf("  |               6  浏览职工记录                            | \n");
		printf("  |               7  退出系统                                | \n");
        printf("  ============================================================ \n");
		printf("    你的选择是:");
}

/***********************************************************
***********************************************************/
int main()
{   
	int choice = 0;
	read(zggz);
	while(1)
	{
		menu();
		scanf("%d",&choice);
		switch(choice)
		{	
			case 1: 
                system("cls");
				find(zggz);
				break;
              
			case 2: 
                system("cls");
				modify(zggz);
				break;
			case 3:
                 system("cls");
				add(zggz);
				break; 
			case 4:
				del(zggz);
				break;
			case 5:
                system("cls"); 
				write(zggz);
				break;
			case 6:
                 system("cls");
				list(zggz);
				break;
			case 7:
                system("cls");
				exit(0);
				break;
			default :
				break;
		}
	}
	return 0;
}

