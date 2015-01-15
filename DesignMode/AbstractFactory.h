#ifndef _ABSTRACTFACTORY_H
#define _ABSTRACTFACTORY_H
//����İ�ť��
class CButton
{
public:
protected:
private:
};
//�����Border��
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
//�����MAC����
class MacFactory:public CAbstractFactory
{

};
//�����WIN����
class WinFacttory:public CAbstractFactory
{
public:
protected:
private:
};
//�����
#endif