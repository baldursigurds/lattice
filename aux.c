#include <stdlib.h>
#include <stdio.h>

#include "aux.h"


// The basic set of data to be analized

data * init_data()
{
	int i,j;
	data * I = malloc(sizeof(data));
	I->n = 0;
	I->nu = 0;
	I->nup = 1;
	I->bad = NULL;
	I->ZKbad = NULL;
	I->m = NULL;
	I->min = 0;
	I->R = NULL;
	return I;
}

root * init_root()
{
	root * R = malloc(sizeof(root));
	R->level = 0;
	R->names = 0;
	R->next = NULL;
	R->list = NULL;
}

point * init_point(data*I, root*R)
{
	int i,j;
	point * p = malloc(sizeof(point));
	p->coord = malloc(I->n*sizeof(int));
	for(i=0; i<I->n; i++)
		p->coord[i] = 0;
	p->chi = 0;
	p->min = 0;
	p->newcomp = p->chi+1;
	p->processed = 1;
	p->I = I;
	p->next = NULL;
	p->prev = NULL;
	p->updown = malloc(I->nup*I->nup*sizeof(point*));
	p->up = malloc(I->nup*sizeof(point*));
	p->down = malloc(I->nu*sizeof(point*));
	for(i=0; i<I->nu; i++)
	{
		p->down[i] = NULL;
	}
	for(i=0; i<I->nup; i++)
	{
		p->up[i] = NULL;
		for(j=0; j<I->nup; j++)
		{
			p->updown[I->nup*i + j] = NULL;
		}
		p->updown[I->nup*i + i] = p;
	}
	p->up[0] = p;
	p->roots = (rnode **) malloc(sizeof(rnode*));
	create_rnode(0, p);
	return p;
}

point * create_point(int s, point * p)
{
	int i,j,k,high;
	int nup = p->I->nup;
	point * new = malloc(sizeof(point));
	new->coord = malloc(p->I->n*sizeof(int));
	new->processed = 0;
	new->I = p->I;
	for(i=0; i<p->I->n; i++)
		new->coord[i] = p->coord[i];
	high = 0;
	while(1)
	{
		if(s/(1<<high) == 1)
			break;
		else
			if(s^(1<<high))
				new->coord[high]++;
		high++;
	} 

	new->chi = p->chi;

	ALN(s, new);
	
	new->min = p->min + pos(p->chi - new->chi);

	new->roots = malloc(pos(-1*new->chi+1)*sizeof(rnode*));
	create_rnodes(p, new);

	new->up = malloc(p->I->nup*sizeof(point*));
	new->down = malloc(p->I->nu*sizeof(point*));
	new->updown = malloc(p->I->nup*p->I->nup*sizeof(point*));

	printf("melding: s = %d,  (1<<high) = %d\n", s, (1<<high));
	point * below = p->updown[nup*s + (1<<high)];
	if(below == NULL)
		printf("something went horribly wrong with the pointer 'below'.\n");
	
	// The following enters the new point into the up and updown data for
	// all points which might point at it.
	// First set everything in new to NULL except for the trivial ones
	for(i=0; i<nup; i++)
	{
		new->up[i] = NULL;
		for(j=0; j<nup; j++)
			new->updown[p->I->nup*i+j] = NULL;
		new->updown[p->I->nup*i+i] = p;
	}
	new->up[0] = p;
	// This is for new->down
	for(i=0; i<p->I->nu; i++)
	{
		if(i == high)
			new->down[i] = below;
		else
			new->down[i] = below->updown[(nup<<high) + (1<<i)];
	}
	// This configures up and updown data pointing at or from the new point
	point * dummy;
//	// i is a step down from the new point
//	for(i=0; i<nup; i++)
//	{
//		dummy = p->updown[p->I->nup*s + i];
//		if(dummy == NULL)
//			break;
//		// up data pointing at the new point:
//		dummy->up[i] = new;
//
//		
//		// j is a step up from the new point, if it can be taken as a step
//		// up from i below
//		for(j=0; j<p->I->nup; j++)
//		{
//			if(i^j)
//				break;
//			// any up data pointing from the new point is configured here
//			if(dummy->up[i+j] != NULL)
//				new->up[j] = dummy->up[i+j];
//			for(k=0; k<nup; k++)
//				if(dummy->updown[nup*(i+j)+k] != NULL)
//				{
//					// any updown data pointing at or from the new point
//					// is configured here
//					new->updown[nup*j+k] = dummy->updown[nup*(i+j)+k];
//					new->updown[nup*j+k]->updown[nup*k+j] = new;
//				}
//		}
//	}
//	The following sets the updown data
//
//	EMERGENCY! Find a way to put in _all_ new updown data, assuming all data
//	was there in the previous setting!
	int dstep;
	new->updown[0] = new;
	for(i=1; i<nup; i++)
	{
		dstep = 1;
		while(dstep^i)
			dstep <<= 1;
	}



		dstep = 0;
		while(new->down[dstep] == NULL || (i^(1<<dstep)) && dstep < p->I->nu)
		{
			++dstep;
			printf("asd;lfkj %d\n", dstep);
		}

		for(j=0; j<nup; j++)
		{
			dummy = new->down[dstep]->updown[nup*(i+(1<<dstep))+j];
			new->updown[nup*i + j] = dummy;
			if(dummy != NULL)
				dummy->updown[nup*j + i] = new;
		}
	}
	

//	printf("created  %d  %d %d\n", new, new->coord[new->I->bad[0]],
//		           new->coord[new->I->bad[1]]);
	return new;
}

int is_in_box(point * p, int i, int j)
{
	if(p->coord[p->I->bad[i]] < p->I->ZKbad[i]
		&& 0 < p->coord[p->I->bad[j]])
		return 1;
	return 0;
}

int pos(int i)
{
	if(i > 0)
		return i;
	else
		return 0;
}

void ALN(int s, point * p)
{
	int i, j;
	int d;
	int Bad[p->I->n];
	int dummy1 = 1;
	int dummy2 = 1;

	for(i=0; i<p->I->n; i++)
		Bad[i] = 0;

	for(i=0; i<p->I->nu; i++)
		Bad[p->I->bad[i]] = 1;



	// The first step in the sequence (the one that provides possible
	// contribution to the geometric genus!)
	d = 0;
	for(j=0; j<p->I->n; j++)
		d += p->coord[j] * p->I->m[p->I->bad[s]*p->I->n+j];
	p->chi += 1-d;
	p->coord[p->I->bad[s]]++;
	
	// The rest of them
	while(dummy1)
	{
		dummy1 = 0;
		dummy2 = 1;
		for(i=0; i<p->I->n && dummy2; i++)
		{
			if(!Bad[i])
			{
				d = 0;
				for(j=0; j<p->I->n; j++)
					d += p->coord[j] * p->I->m[p->I->n*i+j];
				if(d > 0)
				{
					p->chi += 1 - d;
					p->coord[i]++;
					dummy2 = 0;
					dummy1 = 1;
				}
			}
		}
	}
}

void del_point(point * p)
{
	int i;
	for(i=0; i<p->I->nu; i++)
		if(p->up[i] != NULL)
			p->up[i]->down[i] = NULL;
	free(p->coord);
	free(p->updown);
	free(p->up);
	free(p->down);
	free(p->roots);
	if(p->next != NULL)
		p->next->prev = p->prev;
	if(p->prev != NULL)
		p->prev->next = p->next;
	free(p);
}

void process_roots(int s, point * p)
{
	int i;
	point * u = p->up[s];
	rnode * po;
	rnode * uo;
	for(i=0; i>=p->chi && i>=u->chi; i--)
	{
		if(u->roots[-i] == NULL)
			u->roots[-i] = ult_owner(p->roots[-i]);
		po = ult_owner(p->roots[-i]);
		uo = ult_owner(u->roots[-i]);
		if(po != uo)
			po->owner = uo;
	}
	p->processed = 1;
}

void create_rnodes(point * p, point * u)
{
	int i;
	if(u->chi > 0)
		return;
	
	for(i=0; i>=p->chi && i>=u->chi; i--)
		u->roots[-i] = ult_owner(p->roots[-i]);
	u->newcomp = i;
	for(i=i; i>=u->chi; i--)
		create_rnode(i, u);
	
//	printf("Creatad rnodes for %d-%d, they are:",
//			u->coord[u->I->bad[0]], u->coord[u->I->bad[1]]);
//	for(i=0; i>=u->chi; i--)
//		printf(" %d", u->roots[-i]);
//	printf("\n");
}

void del_rnode(rnode * rn)
{
	if(rn->next != NULL)
		rn->next->prev = rn->prev;
	if(rn->prev != NULL)
		rn->prev->next = rn->next;
	free(rn);
}

rnode * ult_owner(rnode * r)
{
	if(r == NULL)
	{
		printf("Can not compute ult_owner(NULL).\n");
		return NULL;
	}
	while(r->owner != NULL)
		r = r->owner;
	return r;
}

void create_rnode(int i, point * p)
{
	int j;
	root * R = p->I->R;
	rnode * new = malloc(sizeof(rnode));
	while(R->level != i)
	{
		if(R->next == NULL)
		{
			printf("New level: %d.\n", R->level - 1);
			R->next = malloc(sizeof(root));
			R->next->level = R->level - 1;
			R->next->names = 0;
			R->next->list = NULL;
			R->next->next = NULL;
		}
		R = R->next;
	}
	new->next = R->list;
	new->prev = NULL;
	if(R->list != NULL)
		R->list->prev = new;
	R->list = new;
	new->name = R->names++;

	if(i!=0)
		new->parent = ult_owner(p->roots[-i-1]);
	else
		new->parent = NULL;
	
	new->owner = NULL;
	p->roots[-i] = new;
}

void put_roots(point * p)
{
	int i,j;
	rnode * r1;
	rnode * r2;
	for(i=0; i>=p->chi; i--)
	{
		p->roots[-i] = NULL;
		for(j=0; j<p->I->nu; j++)
		{
			if(p->coord[p->I->bad[j]] && p->down[j]->chi >= i)
			{
				if(p->roots[-i] == NULL)
				{
					printf("ping\n");
					p->roots[-i] = ult_owner(p->down[j]->roots[-i]);
					printf("pong\n");
				}
				if(p->roots[-i] != NULL)
				{
					printf("ping\n");
					r1 = ult_owner(p->roots[-i]);
					r2 = ult_owner(p->down[j]->roots[-i]);
					printf("pong\n");
					if(r1 != r2)
						r2->owner = r1;
				}
			}
		}
		if(p->roots[-i] == NULL)
			create_rnode(i, p);
	}
}

void finish_roots(point * p)
{
	int i;
	for(i=0; i>=p->chi; i--)
		if(p->roots[-i] == NULL)
			create_rnode(i, p);
}

void print_data(data * I)
{
	if(I->R == NULL)
	{
		printf("There is no root!\n");
		return;
	}
	root * run = I->R;
	rnode * rnrun;
	int eu = -1;
	int lev = 1;
	while(run != NULL)
	{
		printf("\nLevel %d:\n", run->level);
		rnrun = run->list;
		while(rnrun != NULL)
		{
			if(rnrun->owner == NULL)
			{
				printf("Item no. %d", rnrun->name);
				if(rnrun->parent == NULL)
					printf(" has no parent.\n");
				else
					printf(" has parent %d.\n", ult_owner(rnrun->parent)->name);
				eu++;
			}
			rnrun = rnrun->next;
		}
		run = run->next;
		lev--;
	}
	printf("\neu_0: %d, min: %d, min level: %d\n", eu, I->min, lev);
}


void calculate_root(data * I)
{
	root * R = init_root();
	I->R = R;
	point * p = init_point(I, R);

	int s,i,dummy,counter,neg,min;

	point * step;
	point * bot = p;
	point * top = p;


	printf("bads:");
	for(i=0; i<I->nu; i++)
		printf(" %d", p->I->bad[i]);
	printf("  bad values:");
	for(i=0; i<I->nu; i++)
		printf(" %d", p->I->ZKbad[i]);
	printf("\n");
	

	counter = 0;
	neg = 0;
	int toobig;
	while(p != NULL)
	{
//		if(counter++ % 100000 == 0)
//		{
			printf("we're at");
			for(i=0; i<I->nu; i++)
				printf(" %d", p->coord[p->I->bad[i]]);
			printf(", min is %d, chi is %d", p->min, p->chi);
			printf(" and p = %p\n", p);
//		}
//		if(counter % 1000000 == 0)
//			printf("%d million points down!\n", counter/1000000);
		if(p->chi<1)
			neg++;
		// The following constructs all relevant points in the cube with
		// smallest vertex p
		for(s=1; s<I->nup; s++)
		{
			toobig = 0;
			for(i=0; i<I->nu; i++)
				if((p->coord[I->bad[i]] > I->ZKbad[i]) && (s^(1 << i)))
					toobig = 1;
			if(!toobig)
			{
				step = p->up[s];
				if(step == NULL)
				{
					step = create_point(s, p);

					top->next = step;
					step->prev = top;
					step->next = NULL;
					top = step;
					printf("s = %d\n", s);
					printf("added the point ");
					for(i=0; i<I->nu; i++)
						printf(" %d", step->coord[p->I->bad[i]]);
					printf("\n");
				}
			}
		}
		for(s=1; s<I->nup; s*=2)
		{
			step = p->up[s];
			dummy = p->min + pos(p->chi - step->chi);
			if(step->min > dummy)
				step->min = dummy;

			process_roots(s, p);
			finish_roots(p);
		}
		
		for(i=0; i<I->nu; i++)
			if(p->down[i]!=NULL)
			{
				if(bot == p->down[i])
					bot = p->down[i]->next;
				del_point(p->down[i]);
				p->down[i] = NULL;
			}

		I->min = p->min;
		p = p->next;
	}
	point * bot1;
	while(bot != NULL)
	{
		bot1 = bot->next;
		del_point(bot);
		bot = bot1;
	}
}

void del_data(data * I)
{
	free(I->m);
	free(I->bad);
	free(I->ZKbad);
	flush_root(I);
	free(I);
}

void flush_root(data * I)
{
	root * R = I->R;
	root * R1;
	rnode * rn;
	rnode * rn1;
	while(R != NULL)
	{
		rn = R->list;
		while(rn != NULL)
		{
			rn1 = rn->next;
			del_rnode(rn);
			rn = rn1;
		}
		R1 = R->next;
		free(R);
		R = R1;
	}
	I->R = NULL;
	I->min = 0;
}
