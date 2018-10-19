#include <stdio.h>
#include <stdlib.h>

struct person{
	char firstName[20];
	char lastName[20];
	long phoneNumber;
	struct person *nextPersonPointer;
};

typedef struct person Person;

void printPersonInformation(Person *personPointer);

int main(void){
	Person firstPerson = {"Lenka", "NULL", 123456789};
	Person secondPerson = {"Lindsey", "STIRLING", 234567891};
	Person thirdPerson = {"Indila", "NULL", 345678912};

	firstPerson.nextPersonPointer = &secondPerson;
	secondPerson.nextPersonPointer = &thirdPerson;

	printf("FirstName : %s\n", firstPerson.firstName);
	printf("LastName : %s\n", firstPerson.lastName);
	printf("Number : %ld\n", firstPerson.phoneNumber);
	printf("\n");


	printPersonInformation(&firstPerson);

	return 0;
}

void printPersonInformation(Person *personPointer){
	if(personPointer == NULL){
		printf("Empty...\n");
	}
	else{
		while(personPointer != NULL){
			printf("FirstName : %s\n", personPointer -> firstName);
			printf("LastName : %s\n", personPointer -> lastName);
			printf("Number : %ld\n", personPointer -> phoneNumber);
			printf("\n");
			personPointer = personPointer -> nextPersonPointer;
		}
	}
}
