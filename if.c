#include <stdlib.h>
#include <stdio.h>

#include "aux.h"
#include "if.h"


void main_loop(FILE *f)
{
	char c;
	data * I = init_data();
	while(1)
	{
		if(f == stdin)
			printf("> ");
		c = getc(f);
		switch(c)
		{
			case 'c':
				calculate_root(I);
				break;
			case 'i':
				input_data(I, f);
				break;
			case 'p':
				print_comm(I, f);
				break;
			case 'q':
				return;
			case EOF:
				printf("End of file.\n");
				del_data(I);
				return;
			case '\n':
				break;
			default:
				printf("Unknown command %c.\n", c);
		}
		while(c != '\n' && c != EOF)
			c = getc(f);
		if(c == EOF)
		{
			del_data(I);
			return;
		}
	}
	del_data(I);
}

void input_data(data * I, FILE *f)
{
	int i,j;
	switch(getc(f))
	{
		case 'n':
			fscanf(f, "%d", &I->n);
			printf("Obtained value for n: %d.\n", I->n);
			return;
		case 'v':
			fscanf(f, "%d", &I->nu);
			if(I->ZKbad != NULL)
				free(I->ZKbad);
			I->ZKbad = (int*) malloc(I->nu*sizeof(int));
			printf("Obtained value for nu: %d.\n", I->nu);
			return;
		case 'I':
			if(I->n <= 0)
			{
				printf("Input postitive number for n.\n");
				return;
			}
			if(I->m != NULL)
				free(I->m);
			I->m = (int*) malloc(I->n*I->n*sizeof(int));
			for(i=0; i<I->n; i++)
			{
				for(j=0; j<I->n; j++)
				{
					fscanf(f, "%d", I->m + I->n*i + j);
				}
			}
			printf("Intersection matrix obtained.\n");
			break;
		case 'b':
			if(I->nu <= 0)
			{
				printf("Input postitive number for nu.\n");
				return;
			}
			if(I->bad != NULL)
				free(I->bad);
			I->bad = (int*) malloc(I->nu*sizeof(int));
			for(i=0; i<I->nu; i++)
				fscanf(f, "%d", I->bad + i);
			printf("Bad vertices:");
			for(i=0; i<I->nu; i++)
				printf(" %d", I->bad[i]);
			printf(".\n");
			break;
			
		case 'K':
			if(I->nu <= 0)
			{
				printf("Input postitive number for nu.\n");
				return;
			}
			if(I->ZKbad != NULL)
				free(I->ZKbad);
			I->ZKbad = (int*) malloc(I->nu*sizeof(int));
			for(i=0; i<I->nu; i++)
				fscanf(f, "%d", I->ZKbad + i);
			printf("Values of Z_K on bad vertices:");
			for(i=0; i<I->nu; i++)
				printf(" %d", I->ZKbad[i]);
			printf(".\n");
			break;
	}
}

void print_comm(data * I, FILE *f)
{
	int i,j;
	switch(getc(f))
	{
		case 'n':
			printf("n = %d.\n", I->n);
			break;
		case 'v':
			printf("nu = %d.\n", I->nu);
			break;
		case 'I':
			for(i=0; i<I->n; i++)
			{
				for(j=0; j<I->n; j++)
					printf("%d ", I->m[I->n*i + j]);
				printf("\n");
			}
			break;
		case 'r':
			printf("asdf\n");
			print_data(I);
	}
}
