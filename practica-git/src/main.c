#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../inc/stack.h"

#define MAX_BUFFER 500

int check_number(char * s){
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		if(isalpha(s[i])){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[]){
	char buffer[MAX_BUFFER];
	double sum = 0;
	double mul = 1;
	double aux;

	while(1){
		fgets(buffer,MAX_BUFFER,stdin);
		if(strncmp(buffer,"sum",3) == 0){
			printf("Resultado: %f\n", sum);
			return 0;
		} else if (strncmp(buffer,"mul",3) == 0){
			printf("Resultado: %f\n", mul);
			return 0;
		}
		aux = strtod (buffer, NULL);
		if(check_number(buffer)){
			fprintf(stderr, "ERROR\n");
			return 1;
		}
		sum += aux;
		mul *=aux;
	}
	return 1;
}
