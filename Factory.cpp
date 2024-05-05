#include <iostream>

using namespace std;


class Car
{
	public:
		virtual  void drive()=0;
		virtual  void reverse()=0;
		virtual  void park()=0;
};

class Volkswagen:public Car
{
	public:
		Volkswagen(){};

		void drive() {cout << "Volkswagen drive"<<endl;} 
		void reverse() {cout << "Volkswagen reverse"<<endl;} 
		void park() {cout << "Volkswagen park"<<endl;} 
};

class Volvo:public Car
{
	public:
		Volvo(){};
		void drive() {cout << "Volvo drive"<<endl;} 
		void reverse() {cout << "Volvo reverse"<<endl;} 
		void park() {cout << "Volvo park"<<endl;} 
};

class CreateCar
{
	public:
		virtual Car* FactoryMethod() = 0;
		Car * CreateCarObj()
		{
			return this->FactoryMethod();
			//return FactoryMethod();
		}
};

class CreateVolvo:public CreateCar
{
	public:
		Car* FactoryMethod()
		{
			return new Volvo();
		}
};

class CreateVolkswagen:public CreateCar
{
	public:
		Car* FactoryMethod()
		{
			return new Volvo();
		}
};


int main()
{
	Car *carptr;
	CreateCar *car = new CreateVolvo();
	carptr = car->CreateCarObj();

	carptr->drive();
	delete car;
	delete carptr;
	return 0;
}
