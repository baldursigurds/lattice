#include <stdlib.h>
#include <stdio.h>

#include "aux.h"




int main()
{

	data * I = init_data();
	root * R = init_root();
	point * p = init_point(I, R);

	int s,i,dummy;

	point * step;
	point * top = p;


	printf("bads: %d %d\n", p->I->bad[0],p->I->bad[1]);
	printf("bad values: %d %d\n", p->I->ZKbad[0],p->I->ZKbad[1]);
	
	while(p != NULL)
	{
//		printf("we're at");
//		for(i=0; i<nu; i++)
//			printf(" %d", p->coord[p->I->bad[i]]);
//		printf("\nmin is %d, chi is %d\n", p->min, p->chi);
		for(s=0; s<nu; s++)
		{
			if(p->coord[I->bad[s]] != I->ZKbad[s])
			{
				step = p->up[s];
				if(step == NULL)
				{
					step = create_point(s, p);
					step->min = p->min + pos(p->chi - step->chi);
					top->next = step;
					step->prev = top;
					step->next = NULL;
					top = step;
				}
				else
				{
//******************************************************************************
//	add interesting stuff here!
dummy = p->min + pos(p->chi - step->chi);
if(dummy < step->min)
	step->min = dummy;
//******************************************************************************
				}
			}
		}
		
		for(i=0; i<nu; i++)
			if(p->down[i]!=NULL)
				del_point(p->down[i]);

		p = p->next;
	}
	printf("lok!\n");
}

