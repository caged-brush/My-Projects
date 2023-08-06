#include<stdio.h>
void createFile();
void displayFile();
void seekRecord();
void updateRecord();
void deleteRecord();
//record structures
struct Student
{
 char fileName[1000];
 int studentNumber;
 char studentName[1000];
 char email[1000];
 int courseID;
 char grade[100];
};


int main()
{   
    int choice;
    //user menu
    while(choice!=6)
    {
        printf("      MAIN MENU    \n");
        printf("1. Create the Binary File\n");
        printf("2. Display the contents of the file\n");
        printf("3. Seek a specific record\n");
        printf("4. Update the contents of a record\n");
        printf("5. Delete a record for the specific name\n");
        printf("6. Exit\n");
    
        printf("Please Enter Your Choice... ");
        scanf("%d",&choice);
    
        switch (choice)
        {
            case 1:
                createFile();
                break;
            case 2:
                displayFile();
                break;
            case 3:
                seekRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                printf("Goodbye!!!");
                break;
            default:
                printf("Incorrect Input\n");
            break;
        }
    }
}
//function to create file
void createFile()
{
    int noOfStudents;

    FILE* bin_file=fopen("file.bin","wb");

    if(bin_file==NULL)
    {
        printf("Error locating file");
        return;
    }
    struct Student student;
    printf("Enter number of students: ");
    scanf("%d",&noOfStudents);

    for(int i=1; i<=noOfStudents; i++)
    {

        printf("Enter student number: T00");
        scanf("%d",&student.studentNumber);
    

        printf("Enter student name: ");
        scanf("%s",student.studentName);
    

        printf("Enter Email ID: ");
        scanf("%s",student.email);
    
        printf("Enter Course ID: ");
        scanf("%d",&student.courseID);
    
        printf("Enter Grade: ");
        scanf("%s",student.grade);

        fwrite(&student, sizeof(struct Student), 1, bin_file);
    }
    
    

    printf("File created Successfully");

    fclose(bin_file);
}
//function to display file content
void displayFile()
{
    FILE* bin_file=fopen("file.bin","rb");

    if(bin_file==NULL)
    {
        printf("Error locating file");
        return;
    }
        struct Student student;

     while (fread(&student, sizeof(struct Student), 1, bin_file))
    {
        printf("Student Number: T00%d\n", student.studentNumber);
        printf("Student Name: %s\n",student.studentName);
        printf("Email ID: %s\n",student.email);
        printf("Course ID: %d\n",student.courseID);
        printf("Grade: %s\n",student.grade);

    }
    fclose(bin_file);
}
//function to seek a specific record
void seekRecord()
{
     struct Student st;
     int num;
     int found=0;
     printf("Enter student number to search: T00");
        scanf("%d",&num);


     FILE* bin_file=fopen("file.bin","rb");

    if(bin_file==NULL)
    {
        printf("Error locating file");
        return;
    }
        struct Student student;

     while (fread(&student, sizeof(struct Student), 1, bin_file) == 1)
    {
        
        if(student.studentNumber==num)
        {
            printf("Student Number: T00%d\n", student.studentNumber);
            printf("Student Name: %s\n",student.studentName);
            printf("Email ID: %s\n",student.email);
            printf("Course ID: %d\n",student.courseID);
            printf("Grade: %s\n",student.grade);
            found=1;
        }

    }

    if(!found)
    {
        printf("Record not found\n");
    }
    fclose(bin_file);

    
}
//function to update a specific record
void updateRecord()
{
    struct Student st;
    int num;
    int found=0;
    printf("Enter student number to update: T00");
    scanf("%d",&num);


    FILE* bin_file=fopen("file.bin","rb");
    FILE* bin_file2=fopen("temp.bin","wb");

    if(bin_file==NULL)
    {
        printf("Error locating file");
        return;
    }
        struct Student student;

     while (fread(&student, sizeof(struct Student), 1, bin_file) == 1)
    {
        
        if(student.studentNumber==num)
        {
            printf("Enter student number: T00");
            scanf("%d",&student.studentNumber);
    

            printf("Enter student name: ");
            scanf("%s",student.studentName);
    

            printf("Enter Email ID: ");
            scanf("%s",student.email);
        
            printf("Enter Course ID: ");
            scanf("%d",&student.courseID);
        
            printf("Enter Grade: ");
            scanf("%s",student.grade);
            found=1;
            
        }
        fwrite(&student, sizeof(struct Student), 1, bin_file2);

    }
    fclose(bin_file);
    fclose(bin_file2);
    if(found)
    {
        bin_file2=fopen("temp.bin","r");
        bin_file=fopen("file.bin","w");

        while(fread(&student,sizeof(struct Student),1,bin_file2))
        {
            fwrite(&student, sizeof(struct Student), 1, bin_file);
        }
        fclose(bin_file);
        fclose(bin_file2);
    }
    else
    {
        printf("Record not found");
    }

    
}
//function to delete record
void deleteRecord()
{
     struct Student st;
     int num;
     int found=0;
     printf("Enter student number to update: T00");
        scanf("%d",&num);


     FILE* bin_file=fopen("file.bin","rb");
     FILE* bin_file2=fopen("temp.bin","wb");

    if(bin_file==NULL)
    {
        printf("Error locating file");
        return;
    }
        struct Student student;

     while (fread(&student, sizeof(struct Student), 1, bin_file) == 1)
    {
        
        if(student.studentNumber==num)
        {
            found=1;
        }
        else
        {
            fwrite(&student, sizeof(struct Student), 1, bin_file2);
        }

    }
    fclose(bin_file);
    fclose(bin_file2);
    if(found)
    {
        bin_file2=fopen("temp.bin","r");
        bin_file=fopen("file.bin","w");

        while(fread(&student,sizeof(struct Student),1,bin_file2))
        {
            fwrite(&student, sizeof(struct Student), 1, bin_file);
        }
        fclose(bin_file);
        fclose(bin_file2);
    }
    else
    {
        printf("Record not found");
    }

    
}