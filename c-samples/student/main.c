#include "student.h"

int main( void )
{/*
	#if defined( NUMBEROFSTUDENTS )
		printf( "NumberOfStudents:%d\n", NUMBER_OF_STUDENTS );
	#else
		printf( "There is no constant...\n" );
	#endif*/
		
	srand( time( NULL ) );

	generateStudentGrades();
	changeStudentNotes();

	printStudentGrades();
	printPassedStudents();

	return 0;
}