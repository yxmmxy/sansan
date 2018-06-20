#include <iomanip>
#include <iostream>
using namespace;
struct zggz
{
  char name[10];
  char gh[10];
  float gwgz[10];
  float xjgz[10];
  float zwgz[10];
  float jxgz[10];
  float yfgz[10];
  float sds[10];
  float sfgz[10];
}

void read()
{

	char name[20];
	cout<<"请输入工号："<<endl;
	scanf("%",name);


}

void write()
{
	ofstream fout("gz.dat",ios::out);
    if(!fout)
	{
		cout<<"不能打开"
			exit(1);
	}
	fout<<

}

void find()
{
}

void list()
{
}

void modify()
{
}

void del()
{
}

void add()
{
}

void grsds()
{
}
int main()
{
  int choose_num;
	fstream fout("gz.dat", ios::binary|ios::out);
  
    fstream fin("gz.dat", ios::binary|ios::in);


	cout<<"欢迎使用职工管理系统"<<endl;
	cout<<"请选择你要使用的功能（键盘输入数字，回车确认）"<<endl;
	cout<<"1.查询"<<"\n"<<"2.修改"<<"\n"<<"3.添加"<<"\n"<<"4.删除"<<"\n"<<"5.浏览"<<"\n"<<"6.保存"<<"\n"<<"7.退出"<<endl;
	cin>>choose_num;
	if(choose_num<8&&choose_num>0)
	{
	switch(choose_num)
	{
	    case 1:cout<<"已进入查询模块";break;
	case 2:cout<<"已进入修改模块";break;
	case 3: 
		{
			cout<<"已进入添加模块";
			char name,gh;
			float gwgz,xjgz,zwgz,jxgz,yfgz,sds,sfgz;
			cout<<"请输入新工号："<<endl;
			cin>>gh;
			cout<<"请输入名字："<<endl;
			cin>>name;
			cout<<"岗位工资："<<endl;
			cin>>gwgz;
			cout<<"薪级工资："<<endl;
			cin>>xjgz;
			cout<<"职务津贴："<<endl;
			cin>>zwgz;
			cout<<"绩效工资："<<endl;
			cin>>jxgz;
			
			
            fout.close();




			break;
		}










	case 4:cout<<"已进入删除模块";break;
	case 5:cout<<"已进入浏览模块";break;
	case 6:

		cout<<"已保存";break;
	case 7:cout<<"系统退出，欢迎再次使用！";break;
	}
	}
	else{
		cout<<"请重新选择功能"<<endl;
	return 0;}

   

	return 0;	


}

