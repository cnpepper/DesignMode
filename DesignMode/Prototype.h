#pragma once
#include <string>
using namespace std;
//�����ԭ����
class Prototype
{
public:
	Prototype(void);
	virtual ~Prototype(void);
	virtual Prototype* Clone()=0;
};
//�����ԭ����
class concreateprototype1:public Prototype
{
public:
	concreateprototype1(void);
	concreateprototype1(concreateprototype1*that)
	{

	}
	~concreateprototype1(void){}
	//����copy����
	Prototype* Clone()
	{
		return new concreateprototype1(*this);
	}
};

