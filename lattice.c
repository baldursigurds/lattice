#include <stdlib.h>
#include <stdio.h>

#include "aux.h"

int main()
{

	data * I = init_data();
	calculate_root(I);
	print_root(I->R);
}

