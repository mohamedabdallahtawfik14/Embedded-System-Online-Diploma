/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Mohamed
 */

#include "platform_Types.h"
#include "linked_list.h"
//#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char_t decision;
	uint32 selectedOpt, pos, flagCount = 0;
	struct list SDataBase;
	SDataBase.count = 0;
	SDataBase.firstNode = NULL;
	SDataBase.head = SDataBase.firstNode;
	struct Sdata studentData;
	do
	{
		printf("\n=================================================================================\n");
		printf("\t\tChoose one of the following options\n");
		printf("1: Add Student\n");
		printf("2: Add Student in the beginning\n");
		printf("3: Add Student at specified position\n");
		printf("4: Delete last Student\n");
		printf("5: Delete first Student\n");
		printf("6: Delete Student from specified position\n");
		printf("7: How many students in the dataBase?\n");
		printf("8: View Students\n");
		printf("9: Get specified student based on his position\n\n");
		printf("Enter option number: ");
		scanf("%u", &selectedOpt);
		if(LIST_Is_Empty(&SDataBase) == LIST_empty && flagCount != 0)
		{
			printf("=================================================================================\n");
			printf("\t\t\t\tEMPTY LIST\n");
			printf("=================================================================================\n");
		}
		else
		{
			switch(selectedOpt)
			{
				case 1:
				{
					printf("\n=================================================================================\n");
					printf("Enter the ID: ");
					scanf("%u", &studentData.ID);
					printf("\nEnter Student Full Name: ");
					scanf("%s", studentData.name);
					printf("\nEnter height: ");
					scanf("%f", &studentData.height);
					LIST_Push_Back(&SDataBase, studentData);
				}
				break;
				case 2:
				{
					printf("\n=================================================================================\n");
					printf("Enter the ID: ");
					scanf("%u", &studentData.ID);
					printf("\nEnter Student Full Name: ");
					scanf("%s", studentData.name);
					printf("\nEnter height: ");
					scanf("%f", &studentData.height);
					LIST_Push_Front(&SDataBase, studentData);
				}
				break;
				case 3:
				{
					printf("\n=================================================================================\n");
					printf("Enter the Position: ");
					scanf("%u", &pos);
					printf("Enter the ID: ");
					scanf("%u", &studentData.ID);
					printf("\nEnter Student Full Name: ");
					scanf("%s", studentData.name);
					printf("\nEnter height: ");
					scanf("%f", &studentData.height);
					LIST_Push_Anywhere(&SDataBase, studentData, pos);
				}
				break;
				case 4:
				{
					LIST_Delete_Back(&SDataBase);

				}
				break;
				case 5:
				{

					LIST_Delete_Front(&SDataBase);
				}
				break;
				case 6:
				{
					printf("Enter the Position: ");
					scanf("%u", &pos);

					scanf("%c", &decision);
					LIST_Delete_Anywhere(&SDataBase, pos);
				}
				break;
				case 7:
				{
					printf("\n=================================================================================\n");
					printf("There'r %u students in the data base", LIST_Get_No_Of_Elements(SDataBase));
					printf("\n=================================================================================\n");
				}
				break;
				case 8:
				{
					LIST_print(&SDataBase);
				}
				break;
				case 9:
				{
					printf("\n=================================================================================\n");
					printf("Enter the index of the node: ");
					scanf("%u", &pos);
					if(SDataBase.count < pos)
					{
						printf("=================================================================================\n");
						printf("\t\t\tWARNNING!!! ===> Here is garbage value you have %u students only\n", SDataBase.count);
						printf("=================================================================================\n");
					}
					else
					{
						studentData = LIST_Get_Specified_item(&SDataBase, pos);
						printf("Record Number ===> %u\n", pos + 1);
						printf("\t\tID : %u\n", studentData.ID);
						printf("\t\tName : %s\n", studentData.name);
						printf("\t\tHeight : %g\n\n", studentData.height);
					}

				}
				break;
			}
			printf("\n=================================================================================\n");
	//		printf("DO you want to do another operation? Press y to continue else to terminate");
	//		scanf("%c", &decision);
			flagCount++;
		}

	}while(1);

//	struct list new_List;
//	new_List.count =0;
//	new_List.firstNode = NULL;
//	new_List.head = new_List.firstNode;
//	struct Sdata new_data = {
//			20,
//			"hey",
//			20.5
//	};
//	LIST_Push_Back(&new_List, new_data);
//	struct Sdata f = {
//				20,
//				"hey",
//				45.9
//		};
//	LIST_Push_Back(&new_List, f);
//	struct Sdata h = {
//					20,
//					"hey",
//					4
//			};
//	LIST_Push_Front(&new_List, h);
//	LIST_print(&new_List);
//	struct Sdata q = {
//					20,
//					"hey",
//					56
//			};
//	LIST_Push_Anywhere(&new_List, q,1);
//	struct Sdata u = {
//					20,
//					"hey",
//					76
//			};
//	LIST_Push_Anywhere(&new_List, u,1);
//	LIST_print(&new_List);
////	LIST_Delete_Front(&new_List);
//	LIST_Delete_Back(&new_List);
//	LIST_print(&new_List);
//	LIST_Delete_Anywhere(&new_List,1);
//	LIST_print(&new_List);
//	LIST_Delete_Anywhere(&new_List,3);
//	LIST_print(&new_List);
//	struct Sdata j = {
//						20,
//						"hey",
//						85.24
//				};
//	LIST_Push_Front(&new_List, j);
//	LIST_Delete_Anywhere(&new_List,3);
//	LIST_print(&new_List);
//	printf("%u", LIST_Get_No_Of_Elements(new_List));
////	LIST_Delete_Back(&new_List);
//	LIST_Delete_Back(&new_List);
//	LIST_Delete_Anywhere(&new_List,1);
//	printf("%u", LIST_Get_No_Of_Elements(new_List));
//	LIST_print(&new_List);
//
//	struct Sdata currData = LIST_Get_Specified_item(&new_List, 0);
//	printf("%s", currData.name);

return 0;
}

