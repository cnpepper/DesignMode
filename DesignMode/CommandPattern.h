#ifndef _COMMANDPATTERN_H
#define _COMMANDPATTERN_H
#include <iostream>
using namespace std;
/*
����ģʽ
*/
//����ִ����
class Receiver
{
public:
	void Action(){
		cout<<"ִ������"<<endl;
	}
};
//�������
class Command
{
public:
	Command(){}
	Command(Receiver *receiver){
		_receiver = receiver;
	}
	virtual void ExcuteCommand()=0;//����ִ�еĽӿ�
protected:
	Receiver *_receiver;//����һ��ִ����

};
//�������
class ConcreteCommand:public Command
{
public:
	ConcreteCommand(Receiver *receiver):Command(receiver){}
	//����ʵ�ֵ�����ִ�еĽӿڣ��ڲ�ʵ����ִ������Ҫִ�е����
	void ExcuteCommand() override {
		Command::_receiver->Action();
	} 
};
//���������
class Invoker
{
public:
	//��������
	void setOrder(Command* thatCommand){
		this->_command = thatCommand;
	}
	//ִ������
	void Notify(){
		_command->ExcuteCommand();
	}
private:
	Command* _command;
};
#endif//_COMMANDPATTERN_H