#ifndef _ABSTRACTFACTORY_H
#define _ABSTRACTFACTORY_H
//抽象的按钮类
class CButton
{
public:
protected:
private:
};
//抽象的Border类
class CBorder
{
public:
protected:
private:
};
class CAbstractFactory
{
public:
	virtual CButton* CreateButton()=0;
	virtual CBorder* CreateBorder()=0;
};
//具体的MAC工厂
class MacFactory:public CAbstractFactory
{

};
//具体的WIN工厂
class WinFacttory:public CAbstractFactory
{
public:
protected:
private:
};
//具体的
#endif