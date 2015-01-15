#include <iostream>
#include <vector>
using namespace std;
//抽象的观察者，实际应该是被通知需要改变者
class CObserver
{
public:
	virtual void MyUpdate()=0;
};
class ConcreteObserver:public CObserver
{
public:
	ConcreteObserver():strStat("看股票"){}
	void MyUpdate()
	{
		strStat = "开始工作";
	}
	string strStat;
};
//通知者，通知注册了的被通知者去改变状态。
class CObservable
{
public:
	CObservable():m_bChanged(false)
	{
	}
	//注册
	void MyAttach(CObserver* p)
	{
		m_CObservers.push_back(p);
	}
	//注销
	void MyDetach(){}
	//通知
	void MyNotify()
	{
		vector<CObserver*>::iterator it;
		for (it= m_CObservers.begin();it!=m_CObservers.end();++it)
		{
			(*it)->MyUpdate();
		}
	}
	//状态
	bool MyHasChanged()
	{
		return m_bChanged;
	}
	//数量
	int GetObserversNum(){}
protected:
	//设置状态变化!!!必须继承CObservable才能设置目标状态
	void SetChanged(){}
	//初始化目标为未变化
	void ClearChanged(){}
private:
	bool m_bChanged;
	vector<CObserver*> m_CObservers;
	
};