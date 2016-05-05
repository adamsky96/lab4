#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int search_k(int quantity)
{
	if (quantity==0 || quantity==1)
		return quantity;
	bool correct = false;
	for (int k=1; ;k++)
	{
		int issue=quantity*k;
		while(issue)
		{
			if(issue%10 !=0 && issue%10 !=1) break;
			issue/=10;
			if(issue==1) return k;
		}
	}
}

void number_text(int quantity)
{
	if(quantity==0)
		cout<<"zero"<<endl;
	if(quantity==1000000)
		cout<<"milion"<<endl;
	string one[]={"", "jeden ", "dwa ", "trzy ", "cztery ", "pięć ", "sześć ", "siedem ", "osiem ", "dziewięć "};
	string teen[]={"", "jedenaście ", "dwanaście ", "trzynaście ", "czternaście ", "pietnaście ", "szesnaście ", "siedemnaście ", "osiemnaście ", "dziewiętnaście "};
	string ten[]={"", "dziesięć ", "dwadzieścia ", "trzydzieści ", "czterdzieści ", "pięćdziesiąt ", "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ", "dziewięćdziesiąt "};
	string hundred[]={"", "sto ", "dwieście ", "trzysta ", "czterysta ", "pięćset ", "sześćset ", "siedemset ", "osiemset ", "dziewięćset "};
	string thousend[] = {"", "tysięcy ", "tysiące ", "tysiące ", "tysiące ", "tysięcy ", "tysięcy ", "tysięcy ", "tysięcy ", "tysięcy "};
	
	string number_text;
	
	int number[6];
	for(int i = 5, j = 1; i >= 0; i--, j *= 10)
	{
		number[i]=(quantity/j)%10;
	}
	if(number[0]!=0 && number[1]==0 && number[2]==0)
		number_text += hundred[number[0]]+thousend[number[0]];
	else
		number_text += hundred[number[0]];
	if(number[1]==0)
	{
		if(number[2]==1 && number[0]==0 && number[1]==0)
			number_text += "tysiac ";
		else if(number[2]==2 || number[2]==3 || number[2]==4)
			number_text += one[number[2]]+thousend[number[2]]; 
		else
			number_text += one[number[2]]+thousend[number[2]];
	}
	else if(number[1]==1)
		number_text += teen[number[2]]+thousend[number[2]];
	else
		number_text += ten[number[1]]+one[number[2]]+thousend[number[2]];
	if(number[1]!= 0 && number[2]==0)
		number_text += ten[number[1]]+thousend[number[1]];
	number_text += hundred[number[3]];
	if(number[4]==1 && number[5]!=0)
		number_text += teen[number[5]];
	else
		number_text += ten[number[4]]+one[number[5]];
	cout<<number_text<<endl;
}

int main(int argc, char *argv[])
{
	int n=atoi(argv[1]);
	if (n>1000000)
	{
		cout<<"Liczba większa od miliona"<<endl;
		return 0;
	}
	double issue = n*search_k(n);
	cout<<"Lizba k wynosi: ";
	number_text(search_k(n));
	if (issue>1000000)
	{
		cout<<"Iloczyn liczb n*k przekracza milion"<<endl;
		return 0;
	}
	else
		number_text(issue);
}