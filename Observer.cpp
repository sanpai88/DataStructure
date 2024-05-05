#include <iostream>
#include <vector>
using namespace std;
//class Observer;

class Car{
	vector <class Observer *> m_observer_list;
	int  m_position;

	public:
	void notify();
	void setPosition(int pos){
		m_position = pos;
		notify();  
	}

	int getPosition(){
		return m_position;
	}

	void register_notification(Observer* obj)
	{
		m_observer_list.push_back(obj);
	}

};



class Observer{
	Car* _car;

	public:
	Observer(Car *obj){
		_car = obj;
		_car->register_notification(this);
	}

	virtual void update() = 0;
	Car* getCar(){
		return _car;
	}

};

void Car::notify()
{
	for(int i=0;i<m_observer_list.size();i++){
		m_observer_list[i]->update();
	}
}

class LeftObserver:public Observer{

	public:

		LeftObserver(Car *obj):Observer(obj){}


		void update()
		{
			int pos = getCar()->getPosition();
			if (pos < 0)
			{
				cout<<"Left turn"<<endl;
			}
		}
};

class RightObserver:public Observer{

	public:

		RightObserver(Car *obj):Observer(obj){}


		void update()
		{
			int pos = getCar()->getPosition();
			if (pos > 0)
			{
				cout<<"Right turn"<<endl;
			}
		}
};

class BreakObserver:public Observer{

	public:

		BreakObserver(Car *obj):Observer(obj){}

		void update()
		{
			int pos = getCar()->getPosition();
			if (pos == 0)
			{
				cout<<"Car is coming to halt"<<endl;
				cout<<"Code exiting"<<endl;
				exit(0);
			}
		}
};

int main()
{
	//cout << "Hello world" <<endl;

	Car *carobj = new Car;
	int button;
	LeftObserver lobj(carobj);
	RightObserver robj(carobj);
	BreakObserver bobj(carobj);

	cout<<"input -1 for Left ,1 for right 0 to break";

	while(1)
	{
		cin >> button;
		carobj->setPosition(button);

	}
	return 0;
}
