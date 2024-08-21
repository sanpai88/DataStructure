#include <iostream>
using namespace std;

class Alarm
{
    bool alarm;
    public:
    Alarm():alarm(false){};

    void TurnoffAlarm()
    {
        alarm = false;
	cout << "Turned off alarm"<<endl;
    }
    
    void TurnonnAlarm()
    {
        alarm = true;
	cout << "Turned on alarm"<<endl;
    }

};

class Smartlight
{
    bool light_status;
    public:
    Smartlight():light_status(false){};

    void TurnoffLights()
    {
        light_status = false;
	cout << "Turned off lights"<<endl;
    }
    
    void TurnonLights()
    {
        light_status = true;
	cout << "Turned on lights"<<endl;
    }
};

class SmartHome
{
    Smartlight *st;
    Alarm *at;
    public:
	   SmartHome(){
	       st = new(std::nothrow) Smartlight;
	       at = new(std::nothrow) Alarm;
	   }

	   void goOut()
	   {
               st->TurnoffLights();
	       at->TurnonnAlarm();
	   }
	   
	   void comeHome()
	   {
               st->TurnonLights();
	       at->TurnonnAlarm();
	   }

};	

int main()
{
    SmartHome st;

    st.goOut();
    return 0;
}
