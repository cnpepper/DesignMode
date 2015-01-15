#include <iostream>
#include <vector>
using namespace std;
//产品类，得到最终成型的产品
class Product
{
public:
	vector<string> m_parts;
	void add(string strParts)
	{
		m_parts.push_back(strParts);
	}
	void GetHumen()
	{
		for (vector<string>::iterator it = m_parts.begin();
			it!=m_parts.end();++it)
		{
			string str = *it;
			cout<<str.c_str()<<endl;
		}
	}
};
class CBulider
{
public:
	CBulider(){}
	~CBulider(){}
	Product* p;
	virtual void wthead()=0;
	virtual void wtbody()=0;
	virtual void wtleg()=0;
	virtual Product GetResult()=0;
};
class ConcreteBuilder:public CBulider
{
public:
	Product p;
	void wthead()
	{
		p.add("head");
	}
	void wtbody()
	{
		p.add("body");
	}
	void wtleg()
	{
		p.add("leg");
	}
	Product GetResult()
	{
		return p;
	}
};
class Director
{
public:
	void Construct(CBulider* p)
	{
		p->wthead();
		p->wtbody();
		p->wtleg();
	}
};
