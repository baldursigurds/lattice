#include <stdlib.h>
#include <stdio.h>

#include "aux.h"


// The basic set of data to be analized

data * init_data()
{
//******************************************************************************
//Data 1
//******************************************************************************
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

	int i,j;
	data * I = malloc(sizeof(data));
	I->bad = malloc(nu*sizeof(int));
	I->ZKbad = malloc(nu*sizeof(int));
	for(i=0; i<nu; i++)
	{
		I->bad[i] = BAD[i];
		I->ZKbad[i] = ZKBAD[i];
	}
	I->m = malloc(n*n*sizeof(int));
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			I->m[n*i+j] = numbers[i][j];
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
	p->coord = malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		p->coord[i] = 0;
	p->chi = 0;
	p->newcomp = p->chi+1;
	p->I = I;
	p->next = NULL;
	p->prev = NULL;
	p->updown = malloc(nu*nu*sizeof(point*));
	p->up = malloc(nu*sizeof(point*));
	p->down = malloc(nu*sizeof(point*));
	for(i=0; i<nu; i++)
	{
		p->up[i] = NULL;
		p->down[i] = NULL;
		for(j=0; j<nu; j++)
			if(i==j)
				p->updown[i*nu+j] = p;
			else
				p->updown[i*nu+j] = NULL;
	}
	p->roots = malloc(sizeof(rnode*));
	p->roots[0] = create_rnode(0, p);
	return p;
}


point * create_point(int s, point * p)
{
	int i,j;
	point * new = malloc(sizeof(point));
	new->coord = malloc(n*sizeof(int));
	new->I = p->I;
	for(i=0; i<n; i++)
		new->coord[i] = p->coord[i];
	new->chi = p->chi;

	ALN(s, new);
	
	new->min = p->min + pos(p->chi - new->chi);

	new->roots = malloc(pos(new->chi+1)*sizeof(rnode*));
	create_rnodes(p, new);

	new->up = malloc(nu*sizeof(point*));
	new->down = malloc(nu*sizeof(point*));
	new->updown = malloc(nu*nu*sizeof(point*));
	
	for(i=0; i<nu; i++)
	{
		new->up[i] = NULL;
		if(new->coord[new->I->bad[i]] != 0)
		{
			new->down[i] = p->updown[nu*s+i];
			new->down[i]->up[i] = new;
			
		}
		else
			new->down[i] = NULL;
		new->updown[nu*i+i] = new;
	}
	
	for(i=0; i<nu; i++)
		for(j=0; j<nu; j++)
			if(is_in_box(new, i, j))
			{
				new->updown[nu*i+j] = p->updown[nu*s+j]->up[i];
				if(new->updown[nu*i+j] != NULL)
					new->updown[nu*i+j]->updown[nu*j+i] = new;
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
	int Bad[n];

	for(i=0; i<n; i++)
		Bad[i] = 0;

	for(i=0; i<nu; i++)
		Bad[p->I->bad[i]] = 1;

	int dummy1 = 1;
	int dummy2 = 1;


	// The first step in the sequence (the one that provides possible
	// contribution to the geometric genus!)
	d = 0;
	for(j=0; j<n; j++)
		d += p->coord[j] * p->I->m[p->I->bad[s]*n+j];
	p->chi += 1-d;
	p->coord[p->I->bad[s]]++;
	
	// The rest of them
	while(dummy1)
	{
		dummy1 = 0;
		dummy2 = 1;
		for(i=0; i<n && dummy2; i++)
		{
			if(!Bad[i])
			{
				d = 0;
				for(j=0; j<n; j++)
					d += p->coord[j] * p->I->m[n*i+j];
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
	for(i=0; i<nu; i++)
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
	for(i=0; i>=p->chi && i>u->newcomp; i--)
	{
		po = ult_owner(p->roots[-i]);
		uo = ult_owner(u->roots[-i]);
		if(po != uo)
			po->owner = uo;
	}
	for(i=i; i>=p->chi && i>=u->chi; i--)
	{
		del_rnode(u->roots[-i]);
		u->roots[-i] = p->roots[-i];
		u->newcomp--;
	}
}

void create_rnodes(point * p, point * u)
{
	int i;
	u->newcomp = 0;
	for(i=0; i>=p->chi && i>=u->chi; i--)
		u->roots[-i] = ult_owner(p->roots[-i]);
	u->newcomp = i;
	for(i=i; i>=u->chi; i--)
		u->roots[-i] = create_rnode(i, u);
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
	while(r->owner != NULL)
		r = r->owner;
	return r;
}

rnode * create_rnode(int i, point * p)
{
	int j;
	root * R = p->I->R;
	rnode * new = malloc(sizeof(rnode));
	while(R->level != i)
	{
		if(R->next == NULL)
		{
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
	
	new->owner = NULL;
}
