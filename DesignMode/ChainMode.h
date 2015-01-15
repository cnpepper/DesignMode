#ifndef _CHAINMODE_H
#define _CHAINMODE_H
#include <iostream>
using namespace std;
//�������������
class Handler
{
public:
	void setSuccessor(Handler* successor){
		_successor = successor;
	}
	virtual void HandleRequest(int request)=0;
protected:
	Handler* _successor;
private:
};

class ConcreteHandlerA:public Handler
{
public:
	void HandleRequest(int request)
	{
		if (request>=0&&request<10)
		{
			cout<<"A������"<<request<<endl;
		}
		else if (_successor != NULL)
		{
			_successor->HandleRequest(request);
		}
	}

};
class ConcreteHandlerB:public Handler
{
public:
	void HandleRequest(int request)
	{
		if (request>=10&&request<20)
		{
			cout<<"B������"<<request<<endl;
		}
		else if (_successor != NULL)
		{
			_successor->HandleRequest(request);
		}
	}

};
class ConcreteHandlerC:public Handler
{
public:
	void HandleRequest(int request)
	{
		if (request>=20&&request<30)
		{
			cout<<"C������"<<request<<endl;
		}
		else if (_successor != NULL)
		{
			_successor->HandleRequest(request);
		}
	}

};
#endif//_CHAINMODE_H