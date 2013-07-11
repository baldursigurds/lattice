#ifndef __aux_h__
#define __aux_h__

//corresponding to data 1
//#define nu 2
//#define n 20

// corresponding to data 2
#define nu 3
#define n 27


// The basic set of data
typedef struct data data;
struct data
{
	int *m;
	int *bad;
	int *ZKbad;
};

// Nodes of which the root conists
typedef struct rnode rnode;
struct rnode
{
	rnode * next;
	rnode * prev;
	int name;
	rnode * parent;
	rnode * owner;
};

// The root to be constructed
typedef struct root root;
struct root
{
	int level;
	int names;
	rnode * list;
	root * next;
};

// The points in the box
typedef struct point point;
struct point
{
	int * coord;
	int chi;
	int min;
	data * I;
	point * next;
	point * prev;
	point ** updown;
	point ** up;
	point ** down;
	rnode ** roots;
};

// Initiates basic data
data * init_data();

// Initiates a root
root * init_root();

// Initiates a point
point * init_point();

// Creates a new point up in the direction of s.
point * create_point(int s, point * p);

// A nifty tool
int pos(int i);

// Artin Laufer Nemethi algorithm
void ALN(int s, point * p);

// Delete a point from a linked list
void del_point(point * p);

// Find point
//point * find_point(int s, point * p);
#endif
