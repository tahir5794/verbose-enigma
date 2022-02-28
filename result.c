#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX_MARKS 20 // defining a constant MAXIMUM MARKS in each subject.
#define MAX_STUDENTS 2 // defining a constant MAXIMUM number of STUDENTS

typedef struct
{
    string name;
    int roll;
    int eng, math, sci;
    float percent;
}records;

void sort(records student[]);               //Prototype of user defined sort function.
void display(records student[]);	   //Prototype of user defined display function.
void search(records student[]); 	  //Prototype of user defined search function.

int main()
{
    records student[MAX_STUDENTS];

	for(int i = 0; i < MAX_STUDENTS; i++)
    {
        student[i].name = get_string("Enter Name: ");
        student[i].roll = get_int("Enter Roll Number: ");
        student[i].eng = get_float("Marks in English: ");		//Taking details of students as input.
        student[i].math = get_float("Marks in Math: ");
        student[i].sci = get_float("Marks in Science: ");
        student[i].percent = ((float)(student[i].eng + student[i].math + student[i].sci) / (MAX_MARKS * 3)) * 100;
    }

    sort(student);                  //Calling the Sort function.
    display(student);		   //Calling the Display function.
    search(student);		  // Calling the Search Function.
}

void sort(records student[])
{
    int largest_index;

    for(int i = 0; i < MAX_STUDENTS; i++)
    {
        largest_index = i;
        for(int j = i+1; j < MAX_STUDENTS; j++)
        {
            if(student[i].percent < student[j].percent && student[j].percent > student[largest_index].percent)
            {
                largest_index = j;
            }
        }
        int temp = student[i].roll;
        student[i].roll = student[largest_index].roll; // swapping only roll numbers on the basis of percentage.
        student[largest_index].roll = temp;

        records swap = student[i];
	student[i] = student[largest_index];         // sorting the array by swapping the value at largest index and value at selected index.
	student[largest_index] = swap;
    }
}

void display(records student[])
{
    printf("S.no    NAME    RANK    PERCENTAGE\n\n");
    for(int i = 0; i < MAX_STUDENTS; i++)
    {
        printf("%i      %s    %i    \t %.2f%%\n",i+1, student[i].name, student[i].roll, student[i].percent);
        	//Printing the list of records.
    }
}

void search(records student[])
{
	printf("\nTo view the marks enter a name to search.\n\n");
	string query = get_string("Enter Name: ");

	for(int i = 0; i < MAX_STUDENTS; i++)
	{
		if(strcmp(query, student[i].name)==0)  // comparing the Searched Name with student name.
		{	
					//Showing the user the result of search student.
			
			printf("\n=> Name: %s", student[i].name);
			printf("\n=> Rank: %i", student[i].roll);
			printf("\n=> English: %i out of %i", student[i].eng, MAX_MARKS);
			printf("\n=> Math: %i out of %i", student[i].math, MAX_MARKS);
			printf("\n=> Science: %i out of %i", student[i].sci, MAX_MARKS);
			printf("\n=> Percentage: %.2f%%", student[i].percent);

			if(student[i].percent >= 90)
			{
				printf("\n=> Remarks: Excellent! Keep it up.\n");
			}
			else if(student[i].percent < 90 && student[i].percent >= 75)
			{
				printf("\n=> Remarks: Very Good! You can do more better.\n");
			}
			else if(student[i].percent < 75 && student[i].percent >= 60)
			{
				printf("\n=> Remarks: Average Performance! But needs to improve.\n");
			}
			else if(student[i].percent < 60 && student[i].percent >= 40)
			{
				printf("\n=> Remarks: Poor Performance! Needs to work very hard.\n");
			}
			else
			{
				printf("\n=> Remarks: Fail! Try again next year!\n");
			}
			
			return;
		}
	}
	printf("\n\nSorry! No records found for %s", query);
}
