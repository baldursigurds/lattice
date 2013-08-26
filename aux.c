#include <stdlib.h>
#include <stdio.h>

#include "aux.h"


// The basic set of data to be analized

data * init_data()
{
//******************************************************************************
//Data 1
/*******************************************************************************
  	int n = 20;
  	int nu = 2;
	int numbers[n][n] = {
		{ -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, -3, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -2, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -2, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, -2, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -3, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -13, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, -1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -3} };

	int BAD[nu] = {14, 18};
	int ZKBAD[nu] = {56, 20};

//*****************************************************************************/
//Data 2
/*******************************************************************************

	int numbers[n][n] = {
		{-1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{0,-2,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,-2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,-2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,1,-2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,-2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,1,-2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,1,-2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{1,0,0,0,0,0,0,1,-18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,-1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,1,-2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,1,-2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,1,0,0,-7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,-9,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,-2,1,0,1,0,0,0,1,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-3,1,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-4,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,-2,1,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2,1,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2,1,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,-2,1,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2,1,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2,1,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2,1,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-4,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-2}};
	int BAD[nu] = {0,9,14};
	int ZKBAD[nu] = {182,261,345};


//*****************************************************************************/
//Data 3
//******************************************************************************
	int numbers[10][10] = { {-2,  1,  0,  0,  0,  0,  0,  0,  0,  0},
		{ 1, -1,  1,  1,  0,  0,  0,  0,  0,  0},
		{ 0,  1, -3,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  1,  0,-19,  1,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  1, -1,  1,  1,  0,  0,  0},
		{ 0,  0,  0,  0,  1, -2,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  1,  0, -3,  1,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  1, -2,  1,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  1, -3,  1},
		{ 0,  0,  0,  0,  0,  0,  0,  0,  1, -2} };


	int BAD[2] = {1, 4};
	int ZKBAD[2] = {1643, 3485};

// ****************************************************************************/
	

	int i,j;
	data * I = malloc(sizeof(data));
	I->n = 0;
	I->nu = 0;
//	I->bad = malloc(I->nu*sizeof(int));
	I->bad = NULL;
//	I->ZKbad = malloc(I->nu*sizeof(int));
	I->ZKbad = NULL;
//	for(i=0; i<I->nu; i++)
//	{
//		I->bad[i] = BAD[i];
//		I->ZKbad[i] = ZKBAD[i];
//	}
//	I->m = malloc(I->n*I->n*sizeof(int));
	I->m = NULL;
//	for(i=0; i<I->n; i++)
//		for(j=0; j<I->n; j++)
//			I->m[I->n*i+j] = numbers[i][j];
	I->min = 0;
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
	p->newcomp = p->chi+1;
	p->I = I;
	p->next = NULL;
	p->prev = NULL;
	p->updown = malloc(I->nu*I->nu*sizeof(point*));
	p->up = malloc(I->nu*sizeof(point*));
	p->down = malloc(I->nu*sizeof(point*));
	for(i=0; i<I->nu; i++)
	{
		p->up[i] = NULL;
		p->down[i] = NULL;
		for(j=0; j<I->nu; j++)
			if(i==j)
				p->updown[i*I->nu+j] = p;
			else
				p->updown[i*I->nu+j] = NULL;
	}
	p->roots = (rnode **) malloc(sizeof(rnode*));
	create_rnode(0, p);
	p->min = 0;
	return p;
}


point * create_point(int s, point * p)
{
	int i,j;
	point * new = malloc(sizeof(point));
	new->coord = malloc(p->I->n*sizeof(int));
	new->I = p->I;
	for(i=0; i<p->I->n; i++)
		new->coord[i] = p->coord[i];
	new->chi = p->chi;

	ALN(s, new);
	
	new->min = p->min + pos(p->chi - new->chi);

	new->roots = malloc(pos(-1*new->chi+1)*sizeof(rnode*));
	create_rnodes(p, new);

	new->up = malloc(p->I->nu*sizeof(point*));
	new->down = malloc(p->I->nu*sizeof(point*));
	new->updown = malloc(p->I->nu*p->I->nu*sizeof(point*));
	
	for(i=0; i<p->I->nu; i++)
	{
		new->up[i] = NULL;
		if(new->coord[new->I->bad[i]] != 0)
		{
			new->down[i] = p->updown[p->I->nu*s+i];
			new->down[i]->up[i] = new;
			
		}
		else
			new->down[i] = NULL;
		new->updown[p->I->nu*i+i] = new;
	}
	
	for(i=0; i<p->I->nu; i++)
		for(j=0; j<p->I->nu; j++)
			if(is_in_box(new, i, j))
			{
				new->updown[p->I->nu*i+j] = p->updown[p->I->nu*s+j]->up[i];
				if(new->updown[p->I->nu*i+j] != NULL)
					new->updown[p->I->nu*i+j]->updown[p->I->nu*j+i] = new;
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
	while(p != NULL)
	{
		if(counter++ % 100000 == 0)
		{
			printf("we're at");
			for(i=0; i<I->nu; i++)
				printf(" %d", p->coord[p->I->bad[i]]);
			printf(", min is %d, chi is %d", p->min, p->chi);
			printf(" and p = %p\n", p);
		}
		if(counter % 1000000 == 0)
			printf("%d million points down!\n", counter/1000000);
		if(p->chi<1)
			neg++;
		for(s=0; s<I->nu; s++)
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
				dummy = p->min + pos(p->chi - step->chi);
				if(step->min > dummy)
					step->min = dummy;

				process_roots(s, p);
			}
		}
		finish_roots(p);
		
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
