#include "stdio.h"
#include "dataBaseFifo.h"
#include "platform_Types.h"
#include "stdlib.h"

#define dataBase_Length 50

SFIFO_Buf_t database_fifo;
//declare 50 students data
SstudentInfo st[50];

int main(void)
{
	//init for fifo
	SFIFO_Init(&database_fifo, st, dataBase_Length);
	uint8 choice;
	printf("Welcome to the Student Mangement System\n");
	while(1)
	{
		printf("Choose The Task that you want to perform\n");
		printf("1. Add the Student Details Manually\n");
		printf("2. Add the Student Details From Text File\n");
		printf("3. Find the Student Details by Roll Number\n");
		printf("4. Find the Student Details by First Name\n");
		printf("5. Find the Student Details by Course Id\n");
		printf("6. Find the total number od Students\n");
		printf("7. Delete the Student Details by Roll Number\n");
		printf("8. Update the Student Details by Roll number\n");
		printf("9. Show all information\n");
		printf("10. To Exit\n");
		printf("------------------------------------------------------\n");
		printf("Enter your choice to perform the task: ");
		scanf("%u", &choice);
		printf("------------------------------------------------------\n");
		switch(choice)
		{
			case 1:
			{
				add_student_manually();
			}
			break;

			case 2:
			{
				add_student_file();
			}
			break;

			case 3:
			{
				find_rl();
			}
			break;

			case 4:
			{
				find_fn();
			}
			break;

			case 5:
			{
				fine_c();
			}
			break;

			case 6:
			{
				tot_s();
			}
			break;

			case 7:
			{
				del_s();
			}
			break;

			case 8:
			{
				up_s();
			}
			break;

			case 9:
			{
				show_s();
			}
			break;

			case 10:
			{
				exit(1);
			}
			break;
		}
	}
	uint32 i;
	scanf("%d", &i);
	return 0;
}