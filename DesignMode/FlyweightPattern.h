#ifndef _FLYWEIGHTPATTERN_H
#define _FLYWEIGHTPATTERN_H
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Flyweight
{
public:
	virtual void Operation(int extrinsicstate) = 0;
};
class ConcreteFlyweight:public Flyweight
{
public:
	void Operation(int extrinsicstate)
	{
		cout<<"具体"<<extrinsicstate<<endl;
	}
};
class UnsharedConcreteFlyweight:public Flyweight
{
public:
	void Operation(int extrinsicstate)
	{
		cout<<"不共享"<<extrinsicstate<<endl;
	}
};
class FlyweightFactory
{
public:
	FlyweightFactory()
	{
		_flyweights["X"] = new ConcreteFlyweight();
		_flyweights["Y"] = new ConcreteFlyweight();
		_flyweights["Z"] = new ConcreteFlyweight();
	}
	Flyweight* GetFlyweight(string key)
	{
		return _flyweights[key];
	}
private:
	map<string,Flyweight*> _flyweights;
};
#endif