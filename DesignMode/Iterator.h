#ifndef _ITERATOR_H
#define _ITERATOR_H
class Iterator
{
public:
	virtual Iterator* First()=0;
	virtual Iterator* Next()=0;
	virtual bool IsDone()=0;
	virtual Iterator* CurrentItem()=0;
protected:
private:
};
class Aggregate
{
public:
	virtual Iterator* CreateIterator()=0;
protected:
private:
};
class ConcreateAggregate:public Aggregate
{
public:
protected:
private:
};

class ConcreateIterator:public Iterator
{
public:
protected:
private:

};
#endif//_ITERATOR_H