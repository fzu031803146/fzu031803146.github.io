# include <iostream>
# include <stdlib.h>
using namespace std;
typedef struct minheap *Heap;
typedef struct minheap//极小化堆数组 
{
	int last,maxsize;
	int *heap;
}Minheap;
Heap MinHeapInit(int HeapSize)//建空堆 
{
	Heap H=(Heap)malloc(sizeof *H);
	H->maxsize=HeapSize;
	H->heap=(int *)malloc((H->maxsize+1)*sizeof(int));
	H->last=0;
	return H;
}
Heap MinHeapInit(int HeapSize);
void HeapItsert (int x,Heap H)//对堆插入元素 
{
	if (H->last==H->maxsize) return;
	int i=++H->last;
	while(i!=1 && (x<H->heap[i/2]))
	{
		H->heap[i]=H->heap[i/2];
		i/=2;
	}
	H->heap[i]=x;
}
int DeleteMin(Heap H)//抽取最小元 
{
	if (H->last==0) exit(1);
	int x=H->heap[1];
	int y=H->heap[H->last--];
	int i=1,ci=2;
	while(ci<=H->last)
	{
		if ((ci<=H->last) &&(H->heap[ci+1]<H->heap[ci])) ci++;
		if (H->heap[ci]>y)break;
		H->heap[i]=H->heap[ci];
		i=ci;
		ci*=2;
	}
	H->heap[i]=y;
	return x;
}
int main()
{
	int n;
	cin>>n;
	Heap Minheap;
	Minheap=MinHeapInit(n);
	for (int i=0;i<n;i++) 
	{
		int a;
		cin>>a;
		HeapItsert(a,Minheap);
	}
	int sum=0;
	int l=1;
	while(l<n)
	{
		l++;
		int k=DeleteMin(Minheap);
		k=k+DeleteMin(Minheap);
		HeapItsert(k,Minheap);
		sum=sum+k;
	}
	cout<<sum;
	return 0;
}
