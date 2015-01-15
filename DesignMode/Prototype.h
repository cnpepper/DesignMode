#pragma once
#include <string>
using namespace std;
//抽象的原型类
class Prototype
{
public:
	Prototype(void);
	virtual ~Prototype(void);
	virtual Prototype* Clone()=0;
};
//具体的原型类
class concreateprototype1:public Prototype
{
public:
	concreateprototype1(void);
	concreateprototype1(concreateprototype1*that)
	{

	}
	~concreateprototype1(void){}
	//调用copy构造
	Prototype* Clone()
	{
		return new concreateprototype1(*this);
	}
};

