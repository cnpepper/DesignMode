#include <iostream>
using namespace std;
class Context;//声明
//抽象出来的状态类
class State
{
public:
	virtual void Handle(Context *context) = 0;
};
//状态管理类
class Context
{
public:
	//初始化状态
	Context(State *state)
	{
		m_pState = state;
	}
	//执行状态类实现的方法
	void Request()
	{
		m_pState->Handle(this);
	}
	State* m_pState;
};
//具体的状态子类
class ConcreteStateA:public State
{
public:
	void Handle(Context *context);
};
//具体的状态子类
class ConcreteStateB:public State
{
public:
	void Handle(Context *context);
};
//具体的状态子类
class ConcreteStateC:public State
{
public:
	void Handle(Context *context)
	{
	context->m_pState = new ConcreteStateA;
	}
};
//子类中函数的实现放在后边，前边提前的对B和C两个子类的声明也可以去掉了。
void ConcreteStateA:: Handle(Context *context)
{
	context->m_pState = new ConcreteStateB;
}
void ConcreteStateB:: Handle(Context *context)
{
	context->m_pState = new ConcreteStateC;
}
