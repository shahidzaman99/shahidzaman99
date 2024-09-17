QUESTION NO : 06
#include <iostream>
using namespace std;
int main()
{
int size;
int sum=0;
cout<<"enter the size array :"<<endl;
cin>> size;
int *arr=new int[size];
cout<<" enter the elements of array:"<<endl;
for(int i =0;i< size; i++)
{
cin>>arr[i];
if(arr[i] % 2 !=0)
{
sum=sum+arr[i];
}
}
cout<<"addition of all odd integer number "<< sum << endl;
return 0;
}
