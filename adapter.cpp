#include <iostream>

using namespace std;


class Rectangle{

	public:
		virtual void draw() = 0;

};

class LegacyRectangle{

	uint32_t len;
        uint32_t bre;

	public:
		LegacyRectangle(uint32_t x , uint32_t y):len(x),bre(y){};
		void legacydraw() {
                    cout<< "legacy draw func"<<endl;
		    cout<< "len:"<<len<<"bre:"<<bre<<endl;
                }
};

class AdapterRectangle:public LegacyRectangle , public Rectangle{

	public:
		AdapterRectangle(uint32_t x , uint32_t y):LegacyRectangle(x ,y){};
		void draw()
		{
		    legacydraw();
		}
};


int main()
{
    AdapterRectangle *rect = new AdapterRectangle(10,20);
    rect->draw();
    return 0;
}

