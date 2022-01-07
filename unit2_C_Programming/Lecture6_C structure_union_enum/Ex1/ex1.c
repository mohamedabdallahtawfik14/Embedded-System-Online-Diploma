/*
 * ex1.c
 *
 *  Created on: Jan 7, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	struct SStudents
	{
		char name[50];
		int roll, marks;
	} student;
	printf("Enter information of students: \n");
	printf("\nEnter name: ");
	gets(student.name);
	printf("Enter roll number: ");
	scanf("%d", &student.roll);
	printf("Enter Marks: ");
	scanf("%d", &student.marks);
	printf("\nDisplaying Information\nname: %s\nRoll: %d\nMarks: %d", student.name, student.roll, student.marks);
	return 0;
}
