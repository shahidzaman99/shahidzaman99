#include <iostream>
using namespace std;
int main()
{
double rainfall[12];
double total_rainfall=0;
int highest_rainfall_month=0;
int lowest_rainfall_month;
double avg_rainfall;
cout<<"enter the total rain fall in each 12 months :"<<endl;
for(int i=0;i<12;i++)
{
cin>>rainfall[i];
total_rainfall= total_rainfall + rainfall[i];
if(rainfall[i] > highest_rainfall_month)
{
highest_rainfall_month=rainfall[i];
}
if(rainfall[i] < lowest_rainfall_month)
{
lowest_rainfall_month=rainfall[i];
}
}
avg_rainfall=total_rainfall/12;
cout<<"total rainfall in this year :"<<total_rainfall<<endl;
cout<<"higest rainfall months in this year :"<< highest_rainfall_month <<endl;
cout<<"lowest rainfall months in this year :"<< lowest_rainfall_month <<endl;
cout<<"avrage rainfall of in this year :"<<avg_rainfall<<endl;
return 0;
}
