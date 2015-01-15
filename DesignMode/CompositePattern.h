#include <iostream>
#include <string>
#include <vector>
using namespace std;
//抽象基类
class Component
{
public:
	Component(string strName):_strName(strName){}
	virtual void Add(Component* component)=0;
	virtual void Remove(Component* component)=0;
	virtual void Display(int depth)=0;
	string _strName;
};
//叶子节点
class Leaf:public Component
{
public:
	Leaf(string strName):Component(strName){};
	void Add(Component* component) override {
		cout<<"Cannot add to a leaf"<<endl;
	}
	void Remove(Component* component) override {
		cout<<"Cannot remove from a leaf"<<endl;
	}
	void Display(int depth) override {
		int nt = depth;
		while(nt--)
			cout<<"-";
		cout<<Component::_strName<<endl;
	}
};
//叶子节点
class Leaf2:public Component
{
public:
	Leaf2(string strName):Component(strName){};
	void Add(Component* component) override {
		cout<<"Cannot add to a leaf"<<endl;
	}
	void Remove(Component* component) override {
		cout<<"Cannot remove from a leaf"<<endl;
	}
	void Display(int depth) override {
		int nt = depth;
		while(nt--)
			cout<<"-";
		cout<<Component::_strName<<"2"<<endl;
	}
};
//枝节点，管理叶节点
class Composite:public Component
{
public:
	Composite(string strName):Component(strName){}
	void Add(Component* component){
		_vecComponent.push_back(component);
	}

	void Remove(Component* component){
		_vecComponent.pop_back();
	}

	void Display(int depth){
		int nt = depth;
		while(nt--)
			cout<<"-";
		cout<<Component::_strName<<endl;
		vector<Component*>::iterator itRS;
		for (itRS = _vecComponent.begin();itRS!=_vecComponent.end();++itRS)
		{
			(*itRS)->Display(depth+2);
		}
	}

	vector<Component*> _vecComponent;
};