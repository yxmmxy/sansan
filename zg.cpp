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
	cout<<"�����빤�ţ�"<<endl;
	scanf("%",name);


}

void write()
{
	ofstream fout("gz.dat",ios::out);
    if(!fout)
	{
		cout<<"���ܴ�"
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


	cout<<"��ӭʹ��ְ������ϵͳ"<<endl;
	cout<<"��ѡ����Ҫʹ�õĹ��ܣ������������֣��س�ȷ�ϣ�"<<endl;
	cout<<"1.��ѯ"<<"\n"<<"2.�޸�"<<"\n"<<"3.���"<<"\n"<<"4.ɾ��"<<"\n"<<"5.���"<<"\n"<<"6.����"<<"\n"<<"7.�˳�"<<endl;
	cin>>choose_num;
	if(choose_num<8&&choose_num>0)
	{
	switch(choose_num)
	{
	    case 1:cout<<"�ѽ����ѯģ��";break;
	case 2:cout<<"�ѽ����޸�ģ��";break;
	case 3: 
		{
			cout<<"�ѽ������ģ��";
			char name,gh;
			float gwgz,xjgz,zwgz,jxgz,yfgz,sds,sfgz;
			cout<<"�������¹��ţ�"<<endl;
			cin>>gh;
			cout<<"���������֣�"<<endl;
			cin>>name;
			cout<<"��λ���ʣ�"<<endl;
			cin>>gwgz;
			cout<<"н�����ʣ�"<<endl;
			cin>>xjgz;
			cout<<"ְ�������"<<endl;
			cin>>zwgz;
			cout<<"��Ч���ʣ�"<<endl;
			cin>>jxgz;
			
			
            fout.close();




			break;
		}










	case 4:cout<<"�ѽ���ɾ��ģ��";break;
	case 5:cout<<"�ѽ������ģ��";break;
	case 6:

		cout<<"�ѱ���";break;
	case 7:cout<<"ϵͳ�˳�����ӭ�ٴ�ʹ�ã�";break;
	}
	}
	else{
		cout<<"������ѡ����"<<endl;
	return 0;}

   

	return 0;	


}

