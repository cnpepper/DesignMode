#include <iostream>
#include <string>
using namespace std;
//�������౸�ݷ����ߵ�״̬
class Memento
{
public:
	//�����ʱ�򱸷�����
	Memento(string state):_state(state){};
	string _state;
};
//�������౸���Լ���״̬
class Originator
{
public:
	//��������
	Memento* createBackups(){
		return new Memento(_state);
	}
	//�ָ���������
	void restoreBackups(Memento* memento){
		_state = memento->_state;
	}
	//��ʾ״̬
	void show()	{
		cout<<_state<<endl;
	}
	string _state;
};
//�������������
class Caretaker
{
public:
	//�õ�����
	Memento* getMemento(){
		return _memento;
	}
	//���ñ���
	void setMemento(Memento* memento){
		_memento = memento;
	}

	Memento *_memento;
};