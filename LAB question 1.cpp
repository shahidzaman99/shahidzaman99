#include <iostream>
using namespace std;
int main()
{
int max;
cout<<"enter the AGE of array :"<<endl;
int arr[10];
for(int i=0;i<10;i++)
{
cin>>arr[i];
}
max=arr[0];
for(int i=1;i<10;i++)
{
if (arr[i]>max)
{
max=arr[i];
}
}
cout<<"the largest AGE of this array is :"<<max<<endl;
return 0;
}
