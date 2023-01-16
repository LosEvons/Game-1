#include <stdio.h>
#include <stdlib.h>

#include "setup.h"

static void **vclean;
static size_t nclean;

void atexit_add(void *data){
	vclean = realloc(vclean, sizeof(void *) * (nclean + 1));
	vclean[nclean++] = data;
}

void clean(void){
	size_t i;

	for (i = 0; i < nclean; i++){
		free(vclean[i]);
	}
	
	free(vclean);
}