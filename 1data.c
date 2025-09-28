#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add_details();
void copying(FILE*,FILE*);
void print_details();
void edit_details();
void delete_details();
struct Details
{
    char name[30];
    char mob[12];
    char email[30];
    char address[30];
}User;
void search_details(struct Details);
int main()
{
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        printf("---------------------------------------------------\n");
        printf("1.Add Details\n2.Search Details\n3.Print Details\n4.Edit Details\n5.Delete Details\n6.Exit\n");
        printf("---------------------------------------------------\n");
        int choice;
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:add_details();
                   break;
            case 2:search_details(User);
                   break;
            case 3:print_details();
                   break;
            case 4:edit_details();
                   break;
            case 5:delete_details();
                   break;
            case 6: 
                printf("Exiting From Program.\n");
                exit(0);
            default:printf("Invalid");
        }
        if(choice!=6)
        {
         printf("Do you want to continue(y/n): ");
         scanf(" %c",&ch);
        }
    }
}
void add_details()
{
     FILE *fptr=fopen("data.csv","r");
     FILE *fptr1=fopen("tempp.csv","w");
     int count;
     fscanf(fptr,"%d\n",&count);
     count++;
     fprintf(fptr1,"%d\n",count);
     for(int i=0;i<count-1;i++)
     {
        fscanf(fptr," %[^,],%[^,],%[^,],%[^\n]\n",User.name,User.mob,User.email,User.address);
        fprintf(fptr1,"%s,%s,%s,%s\n",User.name,User.mob,User.email,User.address);
     }
     printf("Enter The Name: ");
     scanf(" %[^\n]",User.name);
     printf("Enter Your Mobile number: ");
     scanf(" %[^\n]",User.mob);
     printf("Enter Your Email: ");
     scanf(" %[^\n]",User.email);
     printf("Enter Your Address: ");
     scanf(" %[^\n]",User.address);
     fprintf(fptr1,"%s,%s,%s,%s\n",User.name,User.mob,User.email,User.address);
     fclose(fptr);
     fclose(fptr1);
     fptr=fopen("data.csv","w");
     fptr1=fopen("tempp.csv","r");
     copying(fptr,fptr1);
     fclose(fptr);
     fclose(fptr1);
}
void copying(FILE *fptr, FILE *fptr1) 
{
    char ch;
    while((ch=fgetc(fptr1))!=EOF) 
    {
        fputc(ch,fptr);
    }
}
void search_details(struct Details User) 
{
    FILE *fptr=fopen("data.csv", "r");
    int count;
    fscanf(fptr,"%d\n",&count);
    struct Details temp;
    char search_name[30];
    int found=0;
    printf("Enter the name to search:\n");
    scanf(" %[^\n]",search_name);
    for (int i=0;i<count;i++)
     {
        fscanf(fptr, " %[^,],%[^,],%[^,],%[^\n]\n",temp.name,temp.mob,temp.email,temp.address);
        if (strcmp(temp.name,search_name)==0)
         {
            printf("Details Found:\n");
            printf("---------------------------------------------------\n");
            printf("Name: %s\n",temp.name);
            printf("Mobile: %s\n",temp.mob);
            printf("Email: %s\n",temp.email);
            printf("Address: %s\n",temp.address);
            printf("---------------------------------------------------\n");
            found=1;
            break;
        }
    }
    if (!found) 
    {
        printf("Details not found for the name: %s\n", search_name);
    }
    fclose(fptr);
}
void print_details()
{
    FILE *fptr=fopen("data.csv", "r");
    int count;
    fscanf(fptr,"%d\n",&count);
    struct Details User;
    printf("Printing All Details:\n");
    printf("---------------------------------------------------\n");
    for (int i=0;i<count;i++) 
    {
        fscanf(fptr," %[^,],%[^,],%[^,],%[^\n]\n", User.name, User.mob, User.email, User.address);
        printf("%s,%s,%s,%s\n",User.name, User.mob, User.email, User.address);
    }
    printf("---------------------------------------------------\n");
    fclose(fptr);
}
void edit_details()
 {
    FILE *fptr = fopen("data.csv", "r");
    FILE *fptr1 = fopen("tempp.csv", "w");
    int count;
    fscanf(fptr, "%d\n", &count);
    fprintf(fptr1, "%d\n", count);
    struct Details temp;
    char search_name[30];
    int found = 0;
    int choice;
    printf("Enter the name to edit:\n");
    scanf(" %[^\n]", search_name);
    for (int i = 0; i < count; i++)
     {
        fscanf(fptr, " %[^,],%[^,],%[^,],%[^\n]\n", temp.name, temp.mob, temp.email, temp.address);
        if (strcmp(temp.name, search_name) == 0)
         {
            found = 1; 
            printf("1. Edit Name\n");
            printf("2. Edit Mobile Number\n");
            printf("3. Edit Email\n");
            printf("4. Edit Address\n");
            printf("Enter the choice:\n");
            scanf("%d", &choice);
            switch (choice) 
            {
                case 1:
                    printf("Re-enter the name:\n");
                    scanf(" %[^\n]", temp.name);
                    break;
                case 2:
                    printf("Re-enter the mobile number:\n");
                    scanf(" %[^\n]", temp.mob);
                    break;
                case 3:
                    printf("Re-enter the email:\n");
                    scanf(" %[^\n]", temp.email);
                    break;
                case 4:
                    printf("Re-enter the address:\n");
                    scanf(" %[^\n]", temp.address);
                    break;
                default:
                    printf("Invalid input!!\n");
                    break;
            }
            printf("Details Edited Successfully\n");
        }
        fprintf(fptr1, "%s,%s,%s,%s\n", temp.name, temp.mob, temp.email, temp.address);
    }
    if (!found) 
    {
        printf("Details not found for the name: %s\n", search_name);
    }
    fclose(fptr);
    fclose(fptr1);
    fptr = fopen("data.csv", "w");
    fptr1 = fopen("tempp.csv", "r");
    copying(fptr, fptr1);
    fclose(fptr);
    fclose(fptr1);
}
void delete_details() 
{
    FILE *fptr = fopen("data.csv", "r");
    FILE *fptr1 = fopen("tempp.csv", "w");
    int count;
    fscanf(fptr, "%d\n",&count);
    fprintf(fptr1, "%d\n",count);
    struct Details temp;
    char search_name[30];
    int found = 0;
    printf("Enter the name to delete:\n");
    scanf(" %[^\n]", search_name);
    for (int i = 0; i < count; i++) {
        fscanf(fptr, " %[^,],%[^,],%[^,],%[^\n]\n", temp.name, temp.mob, temp.email, temp.address);
        if (strcmp(temp.name, search_name) == 0)
         {
            found = 1; 
            printf("Details deleted successfully for the name: %s\n", search_name);
            continue;
        }
        fprintf(fptr1, "%s,%s,%s,%s\n", temp.name, temp.mob, temp.email, temp.address);
    }
    if (found) 
    {
        rewind(fptr1);
        fprintf(fptr1, "%d\n", count - 1);
    } 
    else 
    {
        printf("Details not found for the name: %s\n", search_name);
    }
    fclose(fptr);
    fclose(fptr1);
    fptr = fopen("data.csv", "w");
    fptr1 = fopen("tempp.csv", "r");
    copying(fptr, fptr1);
    fclose(fptr);
    fclose(fptr1);
}
