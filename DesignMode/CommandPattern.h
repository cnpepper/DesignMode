#ifndef _COMMANDPATTERN_H
#define _COMMANDPATTERN_H
#include <iostream>
using namespace std;
/*
命令模式
*/
//接收执行者
class Receiver
{
public:
	void Action(){
		cout<<"执行请求"<<endl;
	}
};
//命令抽象
class Command
{
public:
	Command(){}
	Command(Receiver *receiver){
		_receiver = receiver;
	}
	virtual void ExcuteCommand()=0;//命令执行的接口
protected:
	Receiver *_receiver;//持有一个执行者

};
//命令具体
class ConcreteCommand:public Command
{
public:
	ConcreteCommand(Receiver *receiver):Command(receiver){}
	//具体实现的命令执行的接口，内部实现了执行者需要执行的命令。
	void ExcuteCommand() override {
		Command::_receiver->Action();
	} 
};
//命令管理者
class Invoker
{
public:
	//设置命令
	void setOrder(Command* thatCommand){
		this->_command = thatCommand;
	}
	//执行命令
	void Notify(){
		_command->ExcuteCommand();
	}
private:
	Command* _command;
};
#endif//_COMMANDPATTERN_H