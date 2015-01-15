#include <iostream>
using namespace std;
class Context;//����
//���������״̬��
class State
{
public:
	virtual void Handle(Context *context) = 0;
};
//״̬������
class Context
{
public:
	//��ʼ��״̬
	Context(State *state)
	{
		m_pState = state;
	}
	//ִ��״̬��ʵ�ֵķ���
	void Request()
	{
		m_pState->Handle(this);
	}
	State* m_pState;
};
//�����״̬����
class ConcreteStateA:public State
{
public:
	void Handle(Context *context);
};
//�����״̬����
class ConcreteStateB:public State
{
public:
	void Handle(Context *context);
};
//�����״̬����
class ConcreteStateC:public State
{
public:
	void Handle(Context *context)
	{
	context->m_pState = new ConcreteStateA;
	}
};
//�����к�����ʵ�ַ��ں�ߣ�ǰ����ǰ�Ķ�B��C�������������Ҳ����ȥ���ˡ�
void ConcreteStateA:: Handle(Context *context)
{
	context->m_pState = new ConcreteStateB;
}
void ConcreteStateB:: Handle(Context *context)
{
	context->m_pState = new ConcreteStateC;
}
