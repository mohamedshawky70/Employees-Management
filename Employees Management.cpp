#include<iostream>
#include<string>
#define ll  long long
#define ld  long double
#define sz   size 
#define el   endl 
using namespace std;
void fast()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

}
class Employee
{
protected:
	string Name;
	int Emp_id;
	double salary;
public:
	Employee() :Name("known name"), Emp_id(0), salary(0.0) {}
	Employee(string n, int id, double s) :Name(n), Emp_id(id), salary(s){} 
	virtual float Get_TortalSalary() = 0;                                  //Pure virual function                                                                     //Pure virual function
	virtual void print()                                                   //virual function
	{
		cout <<"Name:"<<Name<<el<< "Employee id:"<< Emp_id<<el<< "salary:" << salary<<el;
	}

};
class sales :public Employee                                                //Inheretance
{
	float Goss_Sales;
	float Commition_Rate;
public:
	sales():Goss_Sales(0.0),Commition_Rate(0.0){}
	sales(string n, int id, double s,float g, float c):Employee(n,id,s), Goss_Sales(g), Commition_Rate(c){}

	float Get_TortalSalary()
	{
		return salary + (Goss_Sales * Commition_Rate);
	}
	void print()
	{
		Employee::print();
		cout << "Goss_Sales:" << Goss_Sales<<el << "Commition_Rate:" << Commition_Rate<<el<<"TortalSalary:"<< Get_TortalSalary()<<el;
	}
};
class Engineer :public Employee
{
	string Specialty;
	int Experience;
	int Overtime_hours;
	float Overtime_hours_rate;
public:
	Engineer():Specialty("Known Specialty"), Experience(0), Overtime_hours(0), Overtime_hours_rate(0) {}

	Engineer(string n, int id, double s, string sp, int Ex, int Oh, int Or) :Employee(n, id, s), //Reuseability
		Specialty(sp), Experience(Ex) , Overtime_hours(Oh), Overtime_hours_rate(Or){}
	float Get_TortalSalary()
	{
		return salary + (Overtime_hours * Overtime_hours_rate);
	}
	void print()
	{
		Employee::print();                                                                        //Reuseability
		cout << "Specialty:" << Specialty<<el<< "Experience:" << Experience<<el<< 
		"Overtime_hours:"<<Overtime_hours<<el<<"Overtime_hours_rate:"<<Overtime_hours_rate<<el<<"TortalSalary:"<< Get_TortalSalary()<<el;
	}


};
int main()
{
	fast();
	Employee* Emp_Ptr;  //Polymorphism

	int Goss_Sales, Commition_Rate;
	cout << "Enter Goss_Sales:";
	cin >> Goss_Sales;
	cout << "Enter Commition_Rate:";
	cin >> Commition_Rate;
	
	sales sal("Mohmed",123,5000, Goss_Sales, Commition_Rate);
	Emp_Ptr = &sal;
	Emp_Ptr->print();

	cout << "-----------------------------"<<el;

	int Overtime_hours, Overtime_hours_rate;
	cout << "Enter Overtime_hours:";
	cin >> Commition_Rate;
	cout << "Enter Overtime_hours_rate:";
	cin >> Overtime_hours_rate;
	Engineer Eng("Shawky", 456, 10000, "Software Engineer", 1, Commition_Rate, Overtime_hours_rate);
	Emp_Ptr = &Eng;
	Emp_Ptr->print();
	

	return 0;
}


