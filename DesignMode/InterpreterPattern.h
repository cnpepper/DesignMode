#include <iostream>  
#include <map>  
#include <string>  

using namespace std;  

class Context
{
private:
	map<string, int> valueMap;

public:
	void addValue(string key,int value)
	{       
		valueMap.insert(std::pair<string,int>(key,value));
	}

	int getValue(string key)
	{
		return valueMap[key];
	}
};
// ����һ������Ľ��Ͳ���������ӿ�Ϊ���о�����ʽ��ɫ��Ҫʵ�ֵġ�
class AbstractExpression
{
public :
	virtual int interpreter(Context context) = 0;
};

class AddNonterminalExpression : public AbstractExpression
{
private :
	AbstractExpression *left;
	AbstractExpression *right;

public:
	AddNonterminalExpression(AbstractExpression *left, AbstractExpression *right)
	{
		this->left = left;
		this->right = right;
	}

	int interpreter(Context context)
	{
		return this->left->interpreter(context) + this->right->interpreter(context);
	}

};

class SubtractNonterminalExpression : public AbstractExpression
{
private :
	AbstractExpression *left;
	AbstractExpression *right;

public:
	SubtractNonterminalExpression(AbstractExpression *left, AbstractExpression *right)
	{
		this->left = left;
		this->right = right;
	}

	int interpreter(Context context)
	{
		return this->left->interpreter(context) - this->right->interpreter(context);
	}

};
//ʵ�����ķ��е�Ԫ��������Ľ��Ͳ�����ͨ��һ��������ģʽ��ֻ��һ���ս�����ʽ�����ж��ʵ����Ӧ��ͬ���ս����
//�ս�������������õ��Ļ���Ԫ�أ�һ�㲻���ٱ��ֽ⣬��: x -> xa�� ����a���ս������Ϊû�б�Ĺ�����԰�a��ɱ�ķ��ţ�����x���Ա�ɱ�ķ��ţ�����x�Ƿ��ս����
class TerminalExpression : public AbstractExpression
{
private :
	int i;

public :
	TerminalExpression(int i)
	{
		this->i = i;
	}

	int interpreter(Context context)
	{
		return this->i;
	}
};
//NonterminalExpression:�ķ��е�ÿ�������Ӧ��һ�����ս���ʽ�� ���ս���ʽ�����߼��ĸ��ӳ̶ȶ����ӣ�ԭ����ÿ���ķ����򶼶�Ӧһ�����ս�����ʽ��

