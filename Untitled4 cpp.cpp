#include<iomanip>
using namespace std;
int main ()
{
int array[2][3] = { {3,4,6}, {2,7,3}
};
cout<<"TWO D array :"<<endl;
int total =0;
for(int i=0; i<2; i++)
{
for(int j=0; j<3; j++)
{
cout<<setw(3)<<array[i][j];
total = total + array[i][j];
}
cout<<endl;
}
cout<<endl<<"Total of all elements= "<<total<<endl;
cout<<"Average of all elements= "<<total/6<<endl;
for(int i=0; i<2; i++)
{
int rowtotal= 0, hr=0;
for(int j=0; j<3; j++)
{
rowtotal = rowtotal + array[i][j];
if(array[i][j]>hr)
{
hr= array[i][j];
}
}
cout<<endl<<"Total sum of "<<i+1<<" row is = "<<rowtotal<<endl;
cout<<"Highest value in "<<i+1<<" row is: "<<hr;
}
cout<<endl;
for(int j=0; j<3; j++)
{
int coltotal= 0, hc=0;
for(int i=0; i<2; i++)
{
coltotal = coltotal + array[i][j];
if(array[i][j]>hc)
{
hc= array[i][j];
}
}
cout<<endl<<"Total sum of "<<j+1<<" column is = "<<coltotal<<endl;
cout<<"Highest value in "<<j+1<<" column is: "<<hc<<endl;
}
return 0;
}
