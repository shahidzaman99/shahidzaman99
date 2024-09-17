#include<iostream>
using namespace std;
int main()
{
int array[3][3];
int average;
int sum=0;
int multi=1;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<"enter the elemet of row["<<i<<"] column["<<j<<"]:"<<endl;
cin>>array[i][j];
}
}
for (int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
sum=sum+array[i][j];
multi=multi*array[i][j];
}
}
average=sum/12;
cout<<"sum :"<<sum<<endl;
cout<<"multi :"<<multi<<endl;
cout<<"average :"<<average<<endl;
}
