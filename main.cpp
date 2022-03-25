#include <iostream>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class Electricity
{
	protected:
	double input_ec;
	public:
	void elec_billc();
	double getAttribute()
	{ return input_ec; }
};

void Electricity::elec_billc()
 {
	
	 double min_amt=30;
	 double result=0;
	 double unit1=0;
	 double unit2=0;
	 double unit3=0;
	 double unit=0;

	           cout<<"   Electricity Bill : "<<endl;
		       cout<<"   Enter the number of units used(0 if not applicable)\n";
			   cin>>unit;
	 if(unit>30)
	 {
		 unit1=unit-30;
		 result=min_amt+(30*3);
	 }
	 else
	 {
		result=min_amt+(unit*3);
	 }
	 if(unit1>70)
	 {
		unit2=unit1-70; 
		result=result+(70*4.4);
	 }
	 else
	 {
		 result=result+(unit1*4.4);
	 }
	 if(unit2>100)
	 {
		 unit3=unit2-100;
		 result=result+(100*5.9);
	 }
	 else
	 {
		 result=result+(unit2*5.9);
	 }
	 if(unit3>125)
	 {
		 result=result+(unit3*6.9);
	 }
	 
	 input_ec = result;
	 }

class Water
{
	protected:
	double input_wt;
	public:
	void water_billc();
	double getAttribute()
	{ return input_wt; }
};
void Water::water_billc()
 {
	 double min_amt=48;
	 double result=0;
	 double lit=0;
	 double lit1=0;
	 double lit2=0;
	 double litres=0;

	           cout<<"   Water Bill : "<<endl;
		       cout<<"   Enter the number of litres consumed(0 if not applicable)\n";
			   cin>>litres;

	 if(litres>8000)
	 {
		 lit=litres-8000;
		 result=min_amt+(8000*6);
	 }
	 else
	 {
		result=min_amt+(litres*6);
	 }
	 if(lit>25000)
	 {
		lit1=lit-25000; 
		result=result+(25000*9);
	 }
	 else
	 {
		 result=result+(lit*9);
	 }
	 if(lit1>50000)
	 {
		 lit2=lit1-50000;
		 result=result+(50000*15);
	 }
	 else
	 {
		 result=result+(lit1*30);
	 }
	input_wt=result;
 }

class Telephone
{
	protected:
	double input_te;
	public:
	void telephone_billc();
	double getAttribute()
	{ return input_te; }
};

void Telephone::telephone_billc()
{
	cout<<"   Phone Bill : "<<endl;
	cout<<"   Enter the cumulative amount(data + call)(0 if not applicable)\n";
	cin>>input_te;
}


class Shopping
{
	protected:
	double input_sh;
	public:
	void shopping_billc();
	double getAttribute()
	{ return input_sh; }
};

void Shopping::shopping_billc()
{
	cout<<"   Shopping Bill : "<<endl;
	cout<<"   Enter the cumulative amount(0 if not applicable)\n";
	cin>>input_sh;
}

class Misc
{
	protected:
	double input_misc;
	public:
	void misc_billc();
	int getAttribute()
	{ return input_misc; }
};

void Misc::misc_billc()
{
	cout<<"Miscallenaous Bill : "<<endl;
	cin>>input_misc;
}

class Fuel
{
	protected:
	double input_fu;
	public:
	void fuel_billc();
	double getAttribute()
	{ return input_fu; }
};

void Fuel::fuel_billc()
{
	cout<<"   Fuel Bill : "<<endl;
	cout<<"   Enter the cumulative amount(0 if not applicable)\n";
	cin>>input_fu;
}

class Home {
	public:
		double total;
	  void generateBill(int,int,int,int,int,int);
};

void Home::generateBill(int water,int electricity,int shopping,int fuel,int phone,int misc)
{
	int index=0;
	cout<<setw(5)<<"Sno";
	cout<<setw(40)<<"Category";
	cout<<setw(40)<<"Amount"<<endl;
	cout<<setw(4)<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<setw(5)<<++index<<setw(40)<<"Water"<<setw(40)<<water<<endl;
	cout<<setw(5)<<++index<<setw(40)<<"Electricity"<<setw(40)<<electricity<<endl;
	cout<<setw(5)<<++index<<setw(40)<<"Shopping"<<setw(40)<<shopping<<endl;
	cout<<setw(5)<<++index<<setw(40)<<"Phone"<<setw(40)<<phone<<endl;
	cout<<setw(5)<<++index<<setw(40)<<"Fuel"<<setw(40)<<fuel<<endl;
	cout<<setw(5)<<++index<<setw(40)<<"Miscellaneous"<<setw(40)<<misc<<endl<<endl;
	cout<<setw(40)<<"Total : "<<total<<endl<<setw(0);
}

class CustomBill
{
	private:
    string categ;
	double input;
	queue<string> categ_queue;
	queue<double> input_queue;

	public:
	void custom_billc();	
};

void CustomBill::custom_billc()
{
	ofstream outfile;
	outfile.open("print.dat",ios::out);


	int total=0;
	while(1)
	{
	cout<<"Enter Category(-1 to stop) : ";
	cin>>categ;

	if(categ.compare("-1") == 0)
	break;

	cout<<"Enter Expenditure(-1 to stop) : ";
	if(input == -1)
	break;

	cin>>input;
	categ_queue.push(categ);
	input_queue.push(input);
	}

	int index=0;
	cout<<setw(4)<<"---------------------------------------------------------------------------------------"<<endl;
	outfile<<setw(4)<<"---------------------------------------------------------------------------------------"<<endl;

	cout<<setw(5)<<"Sno";
	outfile<<setw(5)<<"Sno";

	cout<<setw(40)<<"Category";
	outfile<<setw(40)<<"Category";
	
	cout<<setw(40)<<"Amount"<<endl;
	outfile<<setw(40)<<"Amount"<<endl;

	cout<<setw(4)<<"---------------------------------------------------------------------------------------"<<endl;
    outfile<<setw(4)<<"---------------------------------------------------------------------------------------"<<endl;

	while(!categ_queue.empty())
	{
	cout<<setw(5)<<++index<<setw(40)<<categ_queue.front()<<setw(40)<<input_queue.front()<<endl;
	outfile<<setw(5)<<++index<<setw(40)<<categ_queue.front()<<setw(40)<<input_queue.front()<<endl;
	total += input_queue.front();
	categ_queue.pop();
	input_queue.pop();
	}
    cout<<endl;
	outfile<<endl;
	cout<<setw(40)<<"Total : "<<total<<endl;
	outfile<<setw(40)<<"Total : "<<total<<endl;
    
	outfile.close();
}

int main()
{
	int ch;
	Water WaterBill;
	Electricity ElecBill;
	Shopping ShopBill;
	Misc MiscBill;
	Telephone PhoneBill;
	Fuel FuelBill;
	Home TotalBill;
	CustomBill CBill;
     x:
	cout<<"\n Enter your choice\n 1 . Generate Basic bill \n 2 . Generate Custom Bill \n 3 . Print last bill\n 4 . Settings\n 5 . Exit\n";
	cin>>ch;
	
	switch(ch)
	{
		case 1:WaterBill.water_billc();
			   TotalBill.total += WaterBill.getAttribute();
			   
		       ElecBill.elec_billc();
			   TotalBill.total += ElecBill.getAttribute();

			   ShopBill.shopping_billc();
			   TotalBill.total += ShopBill.getAttribute();

			   PhoneBill.telephone_billc();
			   TotalBill.total += PhoneBill.getAttribute();

			   FuelBill.fuel_billc();
			   TotalBill.total += FuelBill.getAttribute();

			   MiscBill.misc_billc();
			   TotalBill.total += MiscBill.getAttribute();

			   cout<<"Generating Bill....."<<endl;
			   TotalBill.generateBill(WaterBill.getAttribute(),
			                          ElecBill.getAttribute(),
									  ShopBill.getAttribute(),
									  FuelBill.getAttribute(),
									  PhoneBill.getAttribute(),
									  MiscBill.getAttribute());
			   goto x;
		
		case 2 : CBill.custom_billc();
		        goto x;
		
		case 4 :

		case 5 : exit(0); 
		default:cout<<"Wrong index.\n";
	}
	
	
	return 0;
}
 
 
