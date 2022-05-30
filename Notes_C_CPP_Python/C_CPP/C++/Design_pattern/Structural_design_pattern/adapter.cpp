#include<iostream>
#include<memory>
using namespace std;

class indianSocket
{

public:
	virtual void indiancharger(int type)=0;
	
};

class usaSocket
{
	
public:
	void usacharger()
	{
		cout<<"usa charger is plugged"<<endl;
	}
	
};

class gSocket
{
	
public:
	void gcharger()
	{
		cout<<"g charger is plugged"<<endl;
	}
	
};

class socketAdapter:public indianSocket, public usaSocket, public gSocket
{

public:
		void indiancharger(int type)
		{
			switch(type)
			{
				case 1:
					usacharger();
					break;
				
				case 2:
					gcharger();
					break;
				
				default:
					break;
			}
			
		}
	
};

int main()
{
	unique_ptr<indianSocket> socket = make_unique<socketAdapter>();
	socket->indiancharger(1);
	socket->indiancharger(2);
	return 0;
}