/*
 * ex4.c
 *
 *  Created on: Jan 7, 2022
 *      Author: mohamed
 */

#include <stdio.h>

struct students
{
	char name[50];
	int roll;
	float marks;
};

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	struct students student[10];
	int count;
	printf("Enter information of students:\n\n");
	for (count = 0; count < 10; ++count)
	{
		student[count].roll = count + 1;
		printf("For roll number %d\n", student[count].roll);
		printf("Enter name: ");
		scanf("%s", student[count].name);
		printf("Enter marks: ");
		scanf("%f", &student[count].marks);
	}
	printf("Displaying information of students:\n\n");
	for (count = 0; count < 10; ++count)
	{
		printf("Information for roll number %d\n", student[count].roll);
		printf("Name: %s\n", student[count].name);
		printf("Marks: %g\n", student[count].marks);
	}
	return 0;
}

