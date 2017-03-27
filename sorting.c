//
// Created by Andriy Poplavskyi on 3/20/17.
//
#include "push_swap.h"

static int         partition(int a[], int less, int high, int i)
{
	int     pivot;
	int     j;
	int     t;

	pivot = a[less];
	j = high + 1;
	while(1)
	{
		while(++i <= high && a[i] <= pivot)
			;
		while(--j && a[j] > pivot )
			;
		if(i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[less];
	a[less] = a[j];
	a[j] = t;
	return (j);
}

void        ft_qsort(int a[], int less, int high)
{
	int j;

	if(less < high)
	{
		j = partition(a, less, high, less);
		ft_qsort( a, less, j-1);
		ft_qsort( a, j+1, high);
	}
}
