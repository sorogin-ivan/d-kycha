#ifndef __D_HEAP__H__
#define __D_HEAP__H__

#include <cstdlib>
#include <iostream>

using namespace std;

template <class HType>
class DHeap
{
private:
	int d; //�������
	HType *keys;// ������
	int kolvo;//����������
public:
	DHeap (const int, const int);
	DHeap (const DHeap&);
	~DHeap ();
	int getidx (int a);
	int min (int a, int b);
	void trans (const int a, const int b);
	void vstavka (const int idx, const HType a);
	void vsplyt (int a);
	void pogryzh (int a);
	int minchild (int a);
	void delet ();
	void deletzadan (int a);
	void push (HType a);
	void okych ();
	void vyvod ();
	int operator == (const DHeap<HType>& a)const;
};

template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	d = arnost; 
	kolvo = size;
	keys = new HType[kolvo];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{
	keys = new HType [a.kolvo];
	d = a.d;
	kolvo = a.kolvo;
	for (int i=0;i<kolvo;i++)
		keys[i] = a.keys[i];
}

template <class HType>
DHeap<HType>::~DHeap ()
{
	delete []keys;
}

template <class HType>//ZAPOLNIT'
int DHeap<HType>::min (int a, int b)
{
}

template <class HType>
int DHeap<HType>::getidx (int a)
{
	int p;
	return p = (a-1)/d;
}

template <class HType>
void DHeap<HType>::trans (const int a, const int b) 
{
	HType tmp = keys[a];
	keys[a] = keys[b];
	keys[b] = tmp;
}

template <class HType>
void DHeap<HType>::vstavka (const int idx, const HType a)
{
	keys[idx] = a;
}

template <class HType>
void DHeap<HType>::vsplyt (int a) 
{
	int p = getidx (a);
	while ((p > 0) && (keys[p] > keys[a]))
	{
		trans(a,p);
		a = p;
		getidx (p);
	}
}

template <class HType>
int DHeap<HType>::minchild (int a) 
{
	int f,l,minc;
	f = a*d + 1;
	if (f > n-1)
		return (-1);
	l = min (a*d+d,n-1);
	minc = f;
	for (int k=f; k<=l;k++)
		if (keys[k] < keys[minc])
			minc = k;
	return minc;
}

template <class HType>
void DHeap<HType>::pogryzh (int a)
{
	int c = minchild(a);
	while ((c!=-1) && (keys[c] < keys[a]))
	{
		trans (c,a);
		a = c;
		c = minchild (a);
	}
}

template <class HType>
void DHeap<HType>::delet ()
{
	int minkey = keys[0];
	keys[0] = keys[kolvo - 1];
	kolvo --;
}

template <class HType>
void DHeap<HType>::deletzadan (int a)//ZAPOLNIT'
{
}

template <class HType>
void DHeap<HType>::push (HType a)
{
	keys = (HType*) realloc (keys, kolvo + 1);
	kolvo ++;
	keys[kolvo] = a;
	vsplyt(kolvo);
}

template <class HType>
void DHeap<HType>::okych ()//ZAPOLNIT'
{
}

template <class HType>
int DHeap<HType>::operator==(const DHeap<HType>& a)const
{
	if ((kolvo != a.kolvo) && (d != a.d))
		return 0;
	for (int i=0;i<kolvo;i++)
	{
		if (keys[i] != a.keys[i])
			return 0;
	}
	return 1;
}

template <class HType>
void DHeap<HType>::vyvod()
{
	for (int i=0;i<kolvo;i++)
	{
		cout << keys[i] << " ";
	}
}
#endif