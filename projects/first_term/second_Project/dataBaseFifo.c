#include "dataBaseFifo.h"
#include "string.h"

extern SstudentInfo st[50];
extern SFIFO_Buf_t database_fifo;
//FIFO APIs definition
//init
SFIFO_Buf_Status SFIFO_Init (SFIFO_Buf_t* fifo, SstudentInfo* buff, uint32 length)
{
	//make base, head, tail point to base of buffet at first
	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	//set length
	fifo->length = length;
	// set number of elements in queue with 0 at first
	fifo->count = 0;
	// init done and return no_error occurred
	return SFIFO_no_error;
}

SFIFO_Buf_Status SFIFO_enqueue (SFIFO_Buf_t* fifo, SstudentInfo item)
{
	//check if fifo is full or not
	if(SFIFO_Is_Full(fifo) == SFIFO_full)
	{
		return SFIFO_full;
	}
	else // fifo not full
	{
		// enqueue value
		*(fifo->head) = item;
		fifo->count++;
		fifo->head++;
		//fifo enqueued succeeded and returned no_error
		return SFIFO_no_error;
	}
}

SFIFO_Buf_Status SFIFO_Is_Full (SFIFO_Buf_t* fifo)
{
	//check if fifo is full returned FIFO_full
	if(fifo->count == fifo->length)
	{
		return SFIFO_full;
	}
	// if not returned FIFO_not_full
	else
	{
		return SFIFO_not_full;
	}
}

sint8 student_search(uint32 roll)
{
	sint32 i, flag = 0;
	for (i = 0; i < database_fifo.count; ++i)
	{
		if(st[i].roll == roll)
		{
			flag = 1;
			break;
		}
	}
	return (flag == 1)? 1:-1;
}
SFIFO_Buf_Status status;

uint32 count = 0;
char str1;
void add_student_file()
{
	// temp of student data
	SstudentInfo temp;
	//pointer to our file
	FILE* fptr;
	fptr = fopen("E:\\Abdallah\\Master\\Embedded-System-Online-Diploma\\projects\\first_term\\second_Project\\New folder\\input.txt", "r");
	if(!fptr)
	{
		printf("File not found");
	}
	else
	{
		/* how can i read multiple lines? 
			feof(fptr) return non zero if the file reach its end so i will break if the file reachs its end
		*/
		while(1)
		{
			//scan roll id for the student
			fscanf(fptr, "%u", &temp.roll);
			//check if file ended or not
			if (feof(fptr))
			{
				break;
			}
			else
			{
				//scan rest of stdent's data
				fscanf(fptr, "%s %s %f", &temp.fname, &temp.lname, &temp.GPA);
				uint8 i;
				for (i = 0; i < 5; ++i)
				{
					fscanf(fptr, "%u", &temp.cid[i]);
				}
				//check if roll id already taken (-1 means not taken)
				if(student_search(temp.roll) == -1)
				{
					if(SFIFO_enqueue(&database_fifo, temp) == SFIFO_no_error)
					{
						printf("[INFO] Roll number %u saved successfully\n", temp.roll);
					}
				}
				else
				{
					printf("[ERROR] Roll number %u is already taken\n", temp.roll);
				}
				
			}
		}
		fclose(fptr);
		printf("------------------------------------------------------\n");
		printf("[INFO] The total number of Students are %u\n", database_fifo.count);
		printf("[INFO] You can add up to 50\n");
		printf("[INFO] You can add %u more students\n", (50 - database_fifo.count));
		printf("------------------------------------------------------\n");
	}	
}
void add_student_manually()
{
	// temp of student data
	SstudentInfo temp;
	printf("Enter roll id : ");
	scanf("%u", &temp.roll);
	if(student_search(temp.roll) == -1)
	{		
		printf("Enter student first name : ");
		scanf("%s", temp.fname);
		printf("Enter student last name : ");
		scanf("%s", temp.lname);
		printf("Enter student GPA : ");
		scanf("%f", &temp.GPA);
		uint8 i;
		for ( i = 0; i < 5; ++i)
		{
			printf("Enter Course id : ");
			scanf("%u", &temp.cid[i]);
		}
		if(SFIFO_enqueue(&database_fifo, temp) == SFIFO_no_error)
		{
			printf("[INFO] Roll number %u saved successfully\n", temp.roll);
		}
	}
	else
	{
		printf("[ERROR] Roll number %u is already taken\n", temp.roll);
	}
	printf("------------------------------------------------------\n");
	printf("[INFO] The total number of Students are %u\n", database_fifo.count);
	printf("[INFO] You can add up to 50\n");
	printf("[INFO] You can add %u more students\n", (50 - database_fifo.count));
	printf("------------------------------------------------------\n");	
}
void find_rl()
{
	uint32 rollID, i;
	uint8 flag = 0;
	SstudentInfo* temp = database_fifo.tail;
	printf("Enter roll id you want to seearch: ");
	scanf("%u", &rollID);
	printf("------------------------------------------------------\n");
	for(i = 0; i < database_fifo.count; i++)
	{
		if(temp->roll == rollID)
		{	
			flag = 1;
			break;
		}
		temp++;
	}
	if(flag == 1)
	{
		printf("Student first name: %s\n", temp->fname);
		printf("Student last name: %s\n", temp->lname);
		printf("Student roll number: %u\n", temp->roll);
		printf("Student GPA number: %g\n", temp->GPA);
		for(i= 0; i < 5; ++i)
		{
			printf("The course ID is: %u\n", temp->cid[i]);
		}
		printf("------------------------------------------------------\n");
	}
	else
	{
		printf("[ERROR] The roll id didn't found\n");
		printf("------------------------------------------------------\n");
	}
}
void find_fn()
{
	uint32 i;
	uint8 j, flag = 0;
	char_t fname[50];
	SstudentInfo* temp = database_fifo.tail;
	printf("Enter student first name you want to seearch: ");
	scanf("%s", fname);
	printf("------------------------------------------------------\n");
	for(i = 0; i < database_fifo.count; ++i)
	{
		if(strcmp(temp->fname, fname) == 0)
		{
			flag = 1;
			printf("Student first name: %s\n", temp->fname);
			printf("Student last name: %s\n", temp->lname);
			printf("Student roll number: %u\n", temp->roll);
			printf("Student GPA number: %g\n", temp->GPA);
			for(j= 0; j < 5; ++j)
			{
				printf("The course ID is: %u\n", temp->cid[j]);
			}
			printf("------------------------------------------------------\n");
		}
		temp++;
	}
	if(flag == 0)
	{
		printf("[ERROR] There are not students with this first name!!!\n");
		printf("------------------------------------------------------\n");
	}
}
void fine_c()
{
	uint32 i, cid;
	uint8 j, flag = 0;
	SstudentInfo* temp = database_fifo.tail;
	printf("Enter course Id you want to seearch: ");
	scanf("%u", &cid);
	printf("------------------------------------------------------\n");
	for(i = 0; i < database_fifo.count; ++i)
	{
		for(j = 0; j < 5; ++j)
		{
			if(cid == temp->cid[j])
			{
				flag = 1;
				printf("Student first name: %s\n", temp->fname);
				printf("Student last name: %s\n", temp->lname);
				printf("Student roll number: %u\n", temp->roll);
				printf("Student GPA number: %g\n", temp->GPA);
				for(j= 0; j < 5; ++j)
				{
					printf("The course ID is: %u\n", temp->cid[j]);
				}
				printf("------------------------------------------------------\n");
			}
		}
		temp++;
	}
	if(flag == 0)
	{
		printf("[ERROR] There are not students enrolled in this course\n");
		printf("------------------------------------------------------\n");
	}
}
void tot_s()
{
	printf("[INFO] The total number of students are : %u\n", database_fifo.count);
	printf("------------------------------------------------------\n");
}
void del_s()
{
	//check if there are no students in the database
	if(database_fifo.count == 0)
	{
		printf("[ERROR] There are no students in the database already!!!\n");
		printf("------------------------------------------------------\n");
	}
	else
	{
		uint32 i, rollID;
		uint8 j, flag = 0;
		SstudentInfo* tempptr = database_fifo.tail;
		SstudentInfo temp;
		printf("Enter roll Id you want to delete it: ");
		scanf("%u", &rollID);
		printf("------------------------------------------------------\n");
		for(i = 0; i < database_fifo.count; i++)
		{
			if(tempptr->roll == rollID)
			{	
				flag = 1;
				break;
			}
			tempptr++;
		}
		if(flag == 0)
		{
			printf("[ERROR] The roll id didn't found\n");
			printf("------------------------------------------------------\n");
		}
		else
		{
			while((i + 1) != database_fifo.count)
			{
				temp = st[i];
				st[i] = st[i + 1];
				st[i + 1] = temp; 
				i++;
			}
			database_fifo.head--;
			database_fifo.count--;
		}
	}
}
void up_s()
{
	uint32 i, rollID, updateChoice;
	uint8 j, flag = 0;
	SstudentInfo* temp = database_fifo.tail;
	printf("Enter roll Id you want to update details: ");
	scanf("%u", &rollID);
	printf("1. update student first name\n");
	printf("2. update student last name\n");
	printf("3. update student GPA\n");
	printf("enter what you want to update: ");
	scanf("%u", &updateChoice);
	printf("------------------------------------------------------\n");
	for(i = 0; i < database_fifo.count; i++)
	{
		if(temp->roll == rollID)
		{	
			flag = 1;
			break;
		}
		temp++;
	}
	if(flag == 0)
	{
		printf("[ERROR] The roll id didn't found\n");
		printf("------------------------------------------------------\n");
	}
	else
	{
		switch(updateChoice)
		{
			case 1:
			{
				char_t fname[50], tempName[50];
				printf("Enter new student first name: ");
				scanf("%s", fname);
				i = 0;
				while(fname[i] != '\0')
				{
					tempName[i] = temp->fname[i];
					temp->fname[i] = fname[i];
					i++;
				}
				tempName[i] = '\0';
				temp->fname[i] = '\0';
				printf("[INFO] You updated student first name %s ---> %s Successfully\n", tempName, temp->fname);
				printf("------------------------------------------------------\n");

			}
			break;

			case 2:
			{
				char_t lname[50], tempName[50];
				printf("Enter new student last name: ");
				scanf("%s", lname);
				i = 0;
				while(lname[i] != '\0')
				{
					tempName[i] = temp->lname[i];
					temp->lname[i] = lname[i];
					i++;
				}
				tempName[i] = '\0';
				temp->lname[i] = '\0';
				printf("[INFO] You updated student last name %s ---> %s Successfully\n", tempName, temp->lname);
				printf("------------------------------------------------------\n");
			}
			break;

			case 3:
			{
				float GPA, tempGPA;
				printf("Enter new student GPA: ");
				scanf("%f", &GPA);
				tempGPA = temp->GPA;
				temp->GPA = GPA;
				printf("[INFO] You updated student GPA %g ---> %g Successfully\n", tempGPA, temp->GPA);
				printf("------------------------------------------------------\n");
			}
			break;
		}
	}
	
}
void show_s()
{
	if(database_fifo.count == 0)
	{
		printf("[ERROR] There are no students in the database already!!!\n");
		printf("------------------------------------------------------\n");
	}
	else
	{
		//temp to navigate on students in our fifo
		SstudentInfo* temp = database_fifo.tail;
		uint32 i, j;
		for(i = 0; i < database_fifo.count; ++i)
		{
			printf("Student first name: %s\n", temp->fname);
			printf("Student last name: %s\n", temp->lname);
			printf("Student roll number: %u\n", temp->roll);
			printf("Student GPA number: %g\n", temp->GPA);
			for(j= 0; j < 5; ++j)
			{
				printf("The course ID is: %u\n", temp->cid[j]);
			}
			printf("------------------------------------------------------\n");
			temp++;
		}
	}
}