//#include "builder.h"
// int main(void)
// {
// 	ConcreteBuilder *A = new ConcreteBuilder;
// 	Director *B = new Director;
// 	B->Construct(A);
// 	Product C = A->GetResult();
// 	C.GetHumen();
// 	getchar();
// 	return 0;
// }
/*
#include "Observer.h"
int main(void)
{
	ConcreteObserver* p= new ConcreteObserver;
	CObservable *m = new CObservable;
	m->MyAttach((CObserver*)p);
	cout<<p->strStat.c_str()<<endl;
	m->MyNotify();
	cout<<p->strStat.c_str()<<endl;
	getchar();
	return 0;
}*/

/*#include "StateMode.h"
int main(void)
{
	//初始化A状态
	Context* context = new Context(new ConcreteStateA);
	context->Request();
	context->Request();
	context->Request();
	getchar();
	return 0;
}*/
/*
#include "Memento.h"
int main(void)
{
	//设置和显示状态
	Originator o;
	o._state = "ON";
	o.show();
	//创建备份
	Memento* m = o.createBackups();
	//管理备份
	Caretaker c;
	c.setMemento(m);
	//设置和显示状态
	o._state = "OFF";
	o.show();
	//恢复备份
	m = c.getMemento();
	o.restoreBackups(m);
	//显示状态
	o.show();
	getchar();
	return 0;
}*/
//#include "CompositePattern.h"
// struct Test
// {
// 	int a;
// 	char b;
// 	short c;
// };
// int main(void)
// {
// 	printf("%d\n",sizeof(Test));
// 	Test test;
// 	printf("%d\n",sizeof(test));
// 	getchar();
// 	Composite *root = new Composite("root");
// 	root->Add(new Leaf("LeafA"));
// 	root->Add(new Leaf2("LeafB"));
// 
// 	Composite *compX = new Composite("CompositeX");
// 	compX->Add(new Leaf("LeafXA"));
// 	compX->Add(new Leaf2("LeafXB"));
// 
// 	root->Add(compX);
// 
// 	Composite *compY = new Composite("CompositeXY");
// 	compY->Add(new Leaf("LeafXYA"));
// 	compY->Add(new Leaf2("LeafXYB"));
// 
// 	compX->Add(compY);
// 
// 	root->Add(new Leaf("LeafC"));
// 
// 	Leaf* leaf = new Leaf("LeafD");
// 	root->Add(leaf);
// 	root->Remove(leaf);
// 
// 	root->Display(1);
// 	getchar();
// 	return 0;
// }
// #include "CommandPattern.h"
// int main(void){
// 	Receiver *r = new Receiver();
// 	Command *c = new ConcreteCommand(r);
// 	Invoker *i = new Invoker();
// 	i->setOrder(c);
// 	i->Notify();
// 	getchar();
// 	return 0;
// }
// #include <vector>
// using namespace std;
// #include "ChainMode.h"
// int main(void)
// {
// 	Handler* h1 = new ConcreteHandlerA();
// 	Handler* h2 = new ConcreteHandlerB();
// 	Handler* h3 = new ConcreteHandlerC();
// 	h1->setSuccessor(h2);
// 	h2->setSuccessor(h3);
// 	vector<int> nRequest;
// 	
// 	nRequest.push_back(12);
// 	nRequest.push_back(22);
// 	nRequest.push_back(8);
// 	nRequest.push_back(17);
// 	nRequest.push_back(29);
// 	for (int i = 0;i<5;++i)
// 	{	
// 		h1->HandleRequest(nRequest[i]);
// 
// 	}
// 
// 	getchar();
// 
// 	return 0;
// }
/*
#include "MediatorMode.h"
int main(void)
{
	Mediator *mediator = new HouseMediator;
	Person *person1 = new Renter;
	Person *person2 = new Landlord;

	mediator->setA(person1);
	mediator->setB(person2);

	person1->setMediator(mediator);
	person2->setMediator(mediator);

	person1->sendMessage("我要租房子");
	person2->sendMessage("我有房要租");

	getchar();
	return 0;
}*/
// #include "FlyweightPattern.h"
// int main(void)
// {
// 	int n = 22;
// 	FlyweightFactory *f= new FlyweightFactory();
// 	
// 	Flyweight *fx = f->GetFlyweight("X");
// 	fx->Operation(n);
// 
// 	fx = f->GetFlyweight("Y");
// 	fx->Operation(n);
// 
// 	fx = f->GetFlyweight("Z");
// 	fx->Operation(n);
// 
// 	UnsharedConcreteFlyweight *uf = new UnsharedConcreteFlyweight();
// 	uf->Operation(--n);
// 	getchar();
// 	return 0;
// }
/*
#include "InterpreterPattern.h"
int main(){
	
	//a-b+c
	Context context;
	context.addValue("a", 7);
	context.addValue("b", 8);
	context.addValue("c", 2);

	SubtractNonterminalExpression *subtractValue = new SubtractNonterminalExpression(new TerminalExpression(
		context.getValue("a")), new TerminalExpression(context.getValue("b")));

	AddNonterminalExpression *addValue = new AddNonterminalExpression(subtractValue, new TerminalExpression(
		context.getValue("c")));

	cout<< addValue->interpreter(context);
	getchar();
	return 0;  
}  */
#include <iostream>
using namespace std;
// class A
// {
// public:
// 
// 	A getInstance()
// 	{
// 		
// 		return a;
// 	}
// protected:
// private:
// 	static A a;
// };

class A
{
public:

	static A* getInstance()
	{

		return a;
	}
	void print()
	{
		cout<<"asdljaskdkljlasd"<<endl;
	}
protected:
private:
	static A* a;
};
A* A::a= new A;
void shellsort(int a[], int n)
{
	int i, j, gap;

		for (gap = n / 2; gap > 0; gap /= 2) //步长
		for (i = 0; i < gap; i++)        //直接插入排序
		{
			for (j = i + gap; j < n; j += gap) 
			if (a[j] < a[j - gap])
			{
				int temp = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
		}
}

void insertsort(int a[],int n)
{
		/*int i, j, k;
		for (i = 1; i < n; i++)
		{
			//为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
			for (j = i - 1; j >= 0; j--)
				if (a[j] < a[i])
					break;

			//如找到了一个合适的位置
			if (j != i - 1)
			{
				//将比a[i]大的数据向后移
				int temp = a[i];
				for (k = i - 1; k > j; k--)
					a[k + 1] = a[k];
				//将a[i]放到正确位置上
				a[k + 1] = temp;
			}
		}
		*/
		int i,j,k;
		for(int i = 1; i< n; ++i)
		{
			int temp = a[i];
			//有序数组是 0~i-1
			for( j = i-1; j >= 0; --j )
			{
				if(a[j]<temp)
				{
					break;
				}		
			}
			if(j!=i-1)
			{
											//把 j~i-1 向后位移一个
				for(k=i-1;k> j;--k)
				{
					a[k+1]=a[k];
				}
				a[k+1] = temp;
			}
		}
/*
	if (a == NULL || n== 0)
	{
		return;
	}
	int i,j,m;
	for (i=1;i<n;++i)
	{
		int k = a[i];
		for (j=i-1;j>=0;--j)
		{
			if (a[j]<k)
			{
				for (m = i - 1; m > j; m--)
					a[m + 1] = a[m];

			}
			a[j] = k;
			

		}
	}*/
}
#include <stdio.h>
#include <time.h>
#include <Windows.h>
struct pre
{
	int p;
};
pre a;
/*
int main()
{
	if(!a.p)
	{
		a.p = 1;
		return 1;
	}
	/*int arr[10] = {11,2,5,3,4,6,9,0,10,23};
	int* ptr = new int[1000];
	for (int i = 0;i<1000; ++i)
	{
		Sleep(100);
		srand(time(NULL));
		int temp = rand()%1000;
		*(ptr+i) = temp;
	}
	//shellsort(arr,10);
	insertsort(ptr,1000);
	for (int i = 0; i<1000;++i)
	{
		printf("%d ",ptr[i]);
	}*/
	/*getchar();
	return 0;  
}*/
	int main(void)
{
	int cc1,cc2,cc3,cc4,cc5,cc6;
	for(int A=0;A<=1;A=A+1)
		for(int B=0;B<=1;B=B+1)
			for(int C=0;C<=1;C=C+1)
				for(int D=0;D<=1;D=D+1)
					for(int E=0;E<=1;E=E+1)
						for(int F=0;F<=1;F=F+1)
						{
							cc1=A||B;
							cc2=!(A&&D);
							cc3=(A&&E)||(A&&F)||(E&&F);
							cc4=(B&&C)||(!B&&!C);
							cc5=(C&&!D)||(D&&!C);
							cc6=D||(!D&&!E);
							if(cc1+cc2+cc3+cc4+cc5+cc6==6)
							{
								int i = 1;
								cout<< (i==2);
								cout<< true?"a":"b"<<1;
								cout<<"A:"<</*A==0?"不是":"是"*/"21"<<"罪犯"<<endl;
								cout<<"B:"<<B==0?"不是":"是";
								cout<<"C:"<<(C==0?"不是":"是")<<"罪犯"<<endl;
								cout<<"D:"<<D==0?"不是":"是" <<"罪犯"<<endl;
								cout<<"E:"<<E==0?"不是":"是" <<"罪犯"<<endl;
								cout<<"F:"<<F==0?"不是":"是" <<"罪犯"<<endl;
							}
						}
						return 0;
}