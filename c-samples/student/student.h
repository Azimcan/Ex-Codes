#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_STUDENTS 20
#define CHANGENOTES( grade )( ( grade ) - ( grade ) * 0.25 )

void generateStudentGrades();
void changeStudentNotes();

void printStudentGrades();
void printPassedStudents();

int midtermGrades [ NUMBER_OF_STUDENTS ];

void generateStudentGrades()
{
	for( int studentIndex = 0; studentIndex < NUMBER_OF_STUDENTS; studentIndex ++ )
	{
		midtermGrades[ studentIndex ] = 1 + rand() % 100;
	}
}

void printStudentGrades()
{
	for( int studentIndex = 0; studentIndex < NUMBER_OF_STUDENTS; studentIndex ++ )
	{
		printf( "Number:%-5dGrade:%-5d\n", studentIndex + 1, midtermGrades[ studentIndex ] );
	}
}

void printPassedStudents()
{
 	printf( "\nAfter calling printPassedStudents...\n" );
	for( int studentIndex = 0; studentIndex < NUMBER_OF_STUDENTS; studentIndex ++ )
	{
	  	if( midtermGrades[ studentIndex ] >= 50 )
	  	{
	  		printf( "Number:%-5dGrade:%-5d\n", studentIndex + 1, midtermGrades[ studentIndex ] );
	  	}
 	}
 	puts( "" );
}

void changeStudentNotes()
{
 	for( int studentIndex = 0; studentIndex < NUMBER_OF_STUDENTS; studentIndex ++ )	
 	{
  	midtermGrades[ studentIndex ] = CHANGENOTES( midtermGrades[ studentIndex ] );
 	}
}
