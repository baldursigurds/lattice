#include <stdlib.h>
#include <stdio.h>

#include "aux.h"
#include "if.h"

int main(int argc, char ** argv)
{
	data * I = init_data(0,0);
	int i;
	for(i=1; i<argc; i++)
	{
		FILE *f = fopen(argv[i], "r");
		if(f != NULL)
		{
			printf("Reading file %s.\n", argv[1]);
			main_loop(f, I);
			fclose(f);
		}
		else
			printf("Could not read file %s.\n", argv[i]);
	}
	main_loop(stdin, I);
	del_data(I);
}

