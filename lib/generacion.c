
#include <stdio.h>

void escribir_cabecera_bss(FILE* fpasm){
	f = fopen(fpasm,"w");
	fwrite(f,"segment .data\nsegment.bss\n\t__esp resd 1");
	fclose(f);
}
