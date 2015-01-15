#ifndef _ADAPTER_H
#define _ADAPTER_H
#include <iostream>
using namespace std;
class Target
{
public:
	virtual void Request()
	{
		cout<<"ÆÕÍ¨ÇëÇó"<<endl;
	}
protected:
private:
};
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout<<""<<endl;
	}
protected:
private:
};
class Adapter:Target
{
public:
	void Request()
	{
		adaptee.SpecificRequest();
	}
protected:
private:
	Adaptee adaptee;
};
#endif//_ADAPTER_H