#include <d-heap.h>

void main ()
{
	int c=0; 
	DHeap<int> *a = new DHeap <int> (3,12);
	 a->vstavka (0,5);
	a->vstavka (1,8);
	for (int i=2;i<12;i++)
		a->vstavka(i,0);
	DHeap<int> *b = new DHeap<int>(3,12);
	b->vstavka (0,8);
	b->vstavka (1,5);
	for (int i=2;i<12;i++)
		b->vstavka(i,0);
	b->trans(0,1);
	

}