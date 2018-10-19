#include <stdio.h>
#include <stdlib.h>

int main(void){
	long number;
	char firstName[15];
	char lastName[20];
	unsigned int finalGrade;

	FILE *studentFile;
	if((studentFile = fopen("student.dat", "w")) == NULL){
		printf("The file connot be opened...\n");
		exit(EXIT_FAILURE);
	}
	else{
		printf("Enter student information : ");
		scanf("%ld%14s%19s%d", &number, firstName, lastName, &finalGrade);

		while(!feof(stdin)){
			fprintf(studentFile, "%ld %s %s %d\n", number, firstName, lastName, finalGrade);
			printf("Enter student information : ");
			scanf("%ld%14s%19s%d", &number, firstName, lastName, &finalGrade);
		}	
		printf("\n");
		fclose(studentFile);
	}
	return 0;
}
