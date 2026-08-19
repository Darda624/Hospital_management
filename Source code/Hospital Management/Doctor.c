#include<stdio.h>
#include "Doctor.h"
void DoctorMain()
{
    int DoctorTF=1;
    while(DoctorTF)
    {
        printf("\n1. Add Doctor \n");
        printf("2. View Doctors \n");
        printf("3. Search Doctor \n");
        printf("4. Update Doctor \n");
        printf("5. DeleteDoctor \n");
        printf("6. Exit \n");
        char DoctorIO;
        scanf(" %c",&DoctorIO);
        switch (DoctorIO)
        {
        case '1':
        {
            system("cls");
            addDoctor();
            break;
        }
        case '2':
        {
            system("cls");
            viewDoctors();
            break;
        }
        case '3':
        {
            int TF = 0;
            char search[50];
            printf("Enter Doctor Name:");
            scanf(" %49[^\n]",search);
            TF=searchDoctor(search);
            if(TF==0)
            {
                system("cls");
                printf("Not Found");
            }
            break;
        }
        case '4':
        {
            system("cls");
            updateDoctor();
            break;
        }
        case '5':
        {
            system("cls");
            deleteDoctor();
            break;
        }
        case '6':
        {
            system("cls");
            DoctorTF =0;
            break;
        }
        default:
        {
            system("cls");
            printf(">>> Error encountered while talking input ");
        }
        }
    }
    return 0;
}
void addDoctor()
{
    char Name[20];
    char Speciality[20];
    char Availability[30];
    char Phone[12];
    char Id[11];
    char Room[5];

    printf("Doctor Name: ");
    scanf(" %19[^\n]",Name);
    printf("\nSpeciality: ");
    scanf(" %19[^\n]",Speciality);
    printf("\nAvailability Time (_pm - _pm): ");
    scanf(" %29[^\n]",Availability);
    printf("\nPhone Number:");
    scanf(" %11[^\n]",Phone);
    printf("\nId No.:");
    scanf(" %10[^\n]",Id);
    printf("\nRoom No.:");
    scanf(" %4[^\n]",Room);

    system("cls");

    FILE *doctor_f;
    doctor_f=fopen("Doctor.txt","a");

    if(doctor_f==NULL)
    {
        system("cls");
        printf(">>>Error encounters while opening Doctor.txt\n");
        return;
    }
    else
    {
        system("cls");
        fprintf(doctor_f,"\n%s %s %s %s %s %s",Name,Speciality,Availability,Phone,Id,Room);
        printf(">>>Added to file Doctor.txt\n");
    }
    fclose(doctor_f);
}
void viewDoctors()
{
    FILE *doctor_f;
    char str[10000];

    doctor_f=fopen("Doctor.txt","r");
    if(doctor_f==NULL)
    {
        printf("File not found!\n");
        return;
    }
    printf("Name:      Speciality   Availability  Phone:     ID:     Room:");
    while(fgets(str,10000,doctor_f)!=NULL)
    {
        printf("%s",str);
    }

    fclose(doctor_f);
}

int searchDoctor(char search[])
{
    char line[100];
    FILE *doctor_f;
    doctor_f=fopen("Doctor.txt","r");
    if(doctor_f==NULL)
    {
        printf(">>>Error encounted while Opening Doctor.txt\n");
        return 0;
    }
    while(fgets(line,100,doctor_f)!=NULL)
    {
        if(strstr(line,search)!=NULL)
        {
            system("cls");
            printf("%s",line);
            fclose(doctor_f);
            return 1;
        }
    }
    fclose(doctor_f);
    return 0;
}
void updateDoctor()
{
    FILE *doctor_f1;
    FILE *doctor_f2;
    doctor_f1=fopen("Doctor.txt","r");
    if(doctor_f1==NULL)
    {
        printf("Error while opening file Doctor.txt\n");
        return;
    }

    doctor_f2=fopen("Temp.txt","w");
    if(doctor_f2==NULL)
    {
        printf("Error while opening file Doctor.txt\n");
        fclose(doctor_f1);
        return;
    }

    char Name_Update[50];
    printf("Enter Doctor Name to update:");
    scanf(" %49[^\n]",Name_Update);

    char line[100];
    int found=0;

    while(fgets(line,100,doctor_f1)!=NULL)
    {
        if(strstr(line,Name_Update)!=NULL)
        {
            found=1;
            system("cls");
            printf(">>>Found!Enter new details below:\n\n");

            char Name[20];
            char Speciality[20];
            char Availability[30];
            char Phone[12];
            char Id[11];
            char Room[5];

            printf("Doctor Name: ");
            scanf(" %19[^\n]",Name);
            printf("\nSpeciality: ");
            scanf(" %19[^\n]",Speciality);
            printf("\nAvailability Time (_pm-_pm): ");
            scanf(" %29[^\n]",Availability);
            printf("\nPhone Number:");
            scanf(" %11[^\n]",Phone);
            printf("\nId No.:");
            scanf(" %10[^\n]",Id);
            printf("\nRoom No.:");
            scanf(" %4[^\n]",Room);

            fprintf(doctor_f2,"\n%s %s %s %s %s %s",Name,Speciality,Availability,Phone,Id,Room);

        }
        else
        {
            fputs(line,doctor_f2);
        }
    }

    fclose(doctor_f1);
    fclose(doctor_f2);

    remove("Doctor.txt");
    rename("Temp.txt","Doctor.txt");

    if(found)
    {
        system("cls");
        printf(">>>Doctor Information Update Successfully!\n");
    }
    else
    {
        system("cls");
        printf(">>>Doctor Not Found!\n");
    }
}
void deleteDoctor()
{
    FILE *doctor_f1;
    FILE *doctor_f2;
    doctor_f1=fopen("Doctor.txt","r");
    if(doctor_f1==NULL)
    {
        printf("Error while opening file Doctor.txt\n");
        return;
    }

    doctor_f2=fopen("Temp.txt","w");
    if(doctor_f2==NULL)
    {
        printf("Error while opening file Doctor.txt\n");
        fclose(doctor_f1);
        return;
    }

    char Name_Remove[50];
    printf("Enter Doctor Name to delete:");
    scanf(" %49[^\n]",Name_Remove);

    char line[100];
    int found=0;

    while(fgets(line,100,doctor_f1)!=NULL)
    {
        if(strstr(line,Name_Remove)==NULL)
        {
            fputs(line,doctor_f2);
        }
        else
        {
            found=1;
        }
    }

    fclose(doctor_f1);
    fclose(doctor_f2);

    remove("Doctor.txt");
    rename("Temp.txt","Doctor.txt");

    if(found)
    {
        system("cls");
        printf(">>>Doctor Deleted Successfully!\n");
    }
    else
    {
        system("cls");
        printf(">>>Doctor Not Found!\n");
    }
}
