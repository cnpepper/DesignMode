#ifndef _MEDIATORMODE_H
#define _MEDIATORMODE_H
#include <iostream>
#include <string>
using namespace std;

class Mediator;
//�û�������
class Person
{
public:
	virtual void setMediator(Mediator* mediator)=0;
	virtual void sendMessage(string message)=0;
	virtual void getMessage(string message)=0;
protected:
	Mediator *_mediator;
private:
};
//�н������
class Mediator
{
public:
	virtual void send(string message,Person *person)=0;
	virtual void setA(Person *a)=0;
	virtual void setB(Person *b)=0;
protected:
private:
};
//�ⷿ��
class Renter:public Person
{
public:
	void setMediator(Mediator *mediator){
		_mediator = mediator;
	}
	void sendMessage(string message){
		_mediator->send(message,this);
	}
	void getMessage(string message){
		cout<<"�ⷿ���յ���Ϣ"<<message<<endl;
	}
protected:
private:
};
//������
class Landlord:public Person
{
public:
	void setMediator(Mediator *mediator){
		_mediator = mediator;
	}
	void sendMessage(string message){
		_mediator->send(message,this);
	}
	void getMessage(string message){
		cout<<"�����յ���Ϣ"<<message<<endl;
	}


protected:
private:
};
//�����н�
class HouseMediator:public Mediator
{
public:
	HouseMediator():_A(NULL),_B(NULL){}
	void setA(Person *a){
		_A=a;
	}
	void setB(Person *b){
		_B=b;
	}
	void send(string message,Person *person){
		if (person == _A)
		{
			_B->getMessage(message);
		}
		else
		{
			_A->getMessage(message);
		}
	}

protected:
private:
	Person *_A;
	Person *_B;
};
#endif//_MEDIATORMODE_H