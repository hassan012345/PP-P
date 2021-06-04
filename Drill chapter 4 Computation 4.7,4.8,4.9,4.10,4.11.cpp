#include <iostream>
#include <vector>
using namespace std;
double conversion(double,string);
	const double cm_to_m =0.01;
    const double in_to_m =2.54*cm_to_m;
    const double ft_to_m =12.0*in_to_m;
int main()
{
	double a;
	string unit;
	double sum=0;
	double meterVal=0;
	vector <double>lens;
	int no_of_values=0;
	double smallest,largest;
while(cin>>a>>unit)
{
	if(unit !="m" && unit!="cm" && unit!= "ft" && unit!="in")
		{
			cout<<"Invalid unit entered.";
			cin>>a>>unit;
			cout<<endl;
		}
	
	meterVal=conversion(a,unit);
	if(0==no_of_values)
		{
			smallest=meterVal;
			largest=meterVal;
		}
	if(meterVal<smallest)
		{
		smallest=a;
		}
	else if(meterVal>largest)
		{
			largest=a;
	}	
	sum=sum+meterVal;
	++no_of_values;
	lens.push_back(meterVal);
}
cout<<"\nThe smallest value entered sofar is"<<smallest<<endl;
cout<<"The largest value entered dofar is"<<largest<<endl;
cout<<"Total no.of values entered"<<no_of_values<<endl;
cout<<"Sum of all values"<<sum<<" m";
cout<<"All the values converted into meters are: \n";
//SORTING ALL VALUES IN THE VECTOR IN INCREASING ORDER
for(int i=0;i<lens.size();i++)
	{
		double min=lens[i];
		int minindex=i;
		for(int j=i+1;j<lens.size();j++)
			{
				if(min>lens[j])
					{
						min=lens[j];
						minindex=j;
					}
			}
		//ASSIGING THE LEFT MOST VALUE TO THE MINIMUM 
		//VALUE AT INDEX J IF MINIMUM VALLUE WAS REPLACED.
		if(minindex !=i)
			{
				lens[minindex]=lens[i];
				lens[i]=min;
			}
	}
for(int i=0;i<lens.size();i++)
	{
		cout<<lens[i]<<" ";
	}
}
double conversion(double length,string unit)
{
	if(unit=="m")
		return length;
	else if(unit=="cm")
		return length*cm_to_m;
	else if(unit=="in")
		return length*in_to_m;
	else if(unit=="ft")
		return length*ft_to_m;
	else 
		return length;
}

