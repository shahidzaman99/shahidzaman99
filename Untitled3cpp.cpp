#include<iostream>
using namespace std;
int main()
{
int num;
int searchItem;
bool find=false;
cout<<"enter the number of elements of array :";
cin>>num;
int *arr=new int[num];
cout<<"enter the element of array :";
for(int i=0;i<num;i++)
{
cin>>arr[i];
}
cout<<"enter the Item to search :"<<endl;
cin>>searchItem;
for(int i=0;i<num;i++)
{
if(arr[i]==searchItem)
{
cout<<"the searchItem is found :"<<endl;
find = true;
break;
}
}
if(!find)
{
cout<<"find elements is not found"<<endl;
}
return 0;
}
