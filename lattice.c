#include <stdlib.h>
#include <stdio.h>

#include "aux.h"
#include "if.h"

int main(int argc, char ** argv)
{
	if(argc == 1)
	{
		main_loop(stdin);
		return 0;
	}

	FILE *f = fopen(argv[1], "r");
	if(f != NULL)
	{
		printf("Reading file %s.\n", argv[1]);
		main_loop(f);
	}
	else
		printf("Could not read file %s.\n", argv[1]);
//	data * I = init_data();
//	calculate_root(I);
//	print_data(I);
//	del_data(I);
}

