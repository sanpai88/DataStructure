#include <iostream>

using namespace std;


class Singleton
{
    static Singleton* m_instance;
    Singleton();
    uint16_t val;
    public:
        static Singleton *getInstance()
	{
             if(m_instance == nullptr )
	     {
                 m_instance = new Singleton();
	     }
	     return m_instance;
	}
        
	~Singleton()
        {
	    cout<< "Deleting singleton obj"<<endl;
            delete m_instance;
        }

	void SetVal(uint16_t in){ 
		cout<<"In setVal"<<endl;
		val = in; 
	}
	uint16_t GetVal() { return val ;}


};

Singleton::Singleton()
{ 
    cout<<"Inside Construtor"<<endl;
}

Singleton* Singleton::m_instance = nullptr;

int main()
{
    Singleton *obj = Singleton::getInstance();
    uint16_t val = 0; 
    obj->SetVal(10);
    val = obj->GetVal();
    //printf("val : %u",val);
    cout<<val<<endl;

    return 0;    
}
