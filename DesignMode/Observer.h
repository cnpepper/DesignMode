#include <iostream>
#include <vector>
using namespace std;
//����Ĺ۲��ߣ�ʵ��Ӧ���Ǳ�֪ͨ��Ҫ�ı���
class CObserver
{
public:
	virtual void MyUpdate()=0;
};
class ConcreteObserver:public CObserver
{
public:
	ConcreteObserver():strStat("����Ʊ"){}
	void MyUpdate()
	{
		strStat = "��ʼ����";
	}
	string strStat;
};
//֪ͨ�ߣ�֪ͨע���˵ı�֪ͨ��ȥ�ı�״̬��
class CObservable
{
public:
	CObservable():m_bChanged(false)
	{
	}
	//ע��
	void MyAttach(CObserver* p)
	{
		m_CObservers.push_back(p);
	}
	//ע��
	void MyDetach(){}
	//֪ͨ
	void MyNotify()
	{
		vector<CObserver*>::iterator it;
		for (it= m_CObservers.begin();it!=m_CObservers.end();++it)
		{
			(*it)->MyUpdate();
		}
	}
	//״̬
	bool MyHasChanged()
	{
		return m_bChanged;
	}
	//����
	int GetObserversNum(){}
protected:
	//����״̬�仯!!!����̳�CObservable��������Ŀ��״̬
	void SetChanged(){}
	//��ʼ��Ŀ��Ϊδ�仯
	void ClearChanged(){}
private:
	bool m_bChanged;
	vector<CObserver*> m_CObservers;
	
};