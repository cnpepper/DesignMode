#include <iostream>
#include <string>
using namespace std;
//备忘者类备份发起者的状态
class Memento
{
public:
	//构造的时候备份数据
	Memento(string state):_state(state){};
	string _state;
};
//发起者类备份自己的状态
class Originator
{
public:
	//建立备份
	Memento* createBackups(){
		return new Memento(_state);
	}
	//恢复备份内容
	void restoreBackups(Memento* memento){
		_state = memento->_state;
	}
	//显示状态
	void show()	{
		cout<<_state<<endl;
	}
	string _state;
};
//管理者类管理备份
class Caretaker
{
public:
	//得到备份
	Memento* getMemento(){
		return _memento;
	}
	//设置备份
	void setMemento(Memento* memento){
		_memento = memento;
	}

	Memento *_memento;
};