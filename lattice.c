#include <stdlib.h>
#include <stdio.h>

#include "aux.h"

int main()
{

	data * I = init_data();
	root * R = init_root();
	I->R = R;
	point * p = init_point(I, R);

	int s,i,dummy,counter,neg,min;

	point * step;
	point * top = p;


	printf("bads:");
	for(i=0; i<nu; i++)
		printf(" %d", p->I->bad[i]);
	printf("  bad values:");
	for(i=0; i<nu; i++)
		printf(" %d", p->I->ZKbad[i]);
	printf("\n");
	

	counter = 0;
	neg = 0;
	while(p != NULL)
	{
		if(++counter % 1 == 0)
		{
			printf("we're at");
			for(i=0; i<nu; i++)
				printf(" %d", p->coord[p->I->bad[i]]);
		//	printf("\nmin is %d, chi is %d\n", p->min, p->chi);
			printf(" and p = %d\n", p);
		}
		if(p->chi<1)
			neg++;
		for(s=0; s<nu; s++)
		{
			if(p->coord[I->bad[s]] < I->ZKbad[s])
			{
				step = p->up[s];
				if(step == NULL)
				{
					step = create_point(s, p);

					top->next = step;
					step->prev = top;
					step->next = NULL;
					top = step;
				}
//******************************************************************************
//	add interesting stuff here!
				dummy = p->min + pos(p->chi - step->chi);
				if(step->min > dummy)
					step->min = dummy;

				process_roots(s, p);
//******************************************************************************
			}
		}
		
		for(i=0; i<nu; i++)
			if(p->down[i]!=NULL)
				del_point(p->down[i]);

		min = p->min;
		p = p->next;
	}
	printf("\nmin: %d, neg: %d, total: %d.\n", min, neg, counter);
}

