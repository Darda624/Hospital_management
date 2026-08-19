#include<stdio.h>
#include "patient.h"
#include "Room.h"
void PatientMain()
{
    int PatientTF=1;
    while(PatientTF)
    {
        printf("\n");
        printf("1. Add Patient \n");
        printf("2. View Patients \n");
        printf("3. Search Patient \n");
        printf("4. Update Patient \n");
        printf("5. Delete Patient \n");
        printf("6. Exit \n");

        char PatientIO;
        scanf(" %c",&PatientIO);
        switch (PatientIO)
        {
        case '1':
        {
            system("cls");
            addPatient();
            break;
        }
        case '2':
        {
            system("cls");
            viewPatients();
            break;
        }
        case '3':
        {
            char search_p[50];
            printf("Enter Patient Name: ");
            scanf(" %[^\n]",search_p);
            int TF = searchPatient(search_p);
            if(TF==0)
            {
                system("cls");
                printf("Not Found");
            }
            break;
        }
        case '4':
        {
            updatePatient();
            break;
        }
        case '5':
        {
            char Name_Remove[50];
            printf("Enter Patient Name to delete:");
            scanf(" %49[^\n]",Name_Remove);
            deletePatient(Name_Remove);
            break;
        }
        case '6':
        {
            system("cls");
            PatientTF =0;
            break;
        }
        default:
        {
            system("cls");
            printf(">>> Error encountered while talking input ");
        }

        }
    }
}
void addPatient()
{
    char Name[15];
    char Age[3];
    char phone[12];
    char Nid[11];
    char room[4];
    printf("Patient Name: ");
    scanf(" %10[^\n]",Name);
    printf("\nPatient Age: ");
    scanf(" %2[^\n]",Age);
    printf("\nPatient Phone: ");
    scanf(" %10[^\n]",phone);
    printf("\nPatient NID: ");
    scanf(" %[^\n]",Nid);
    printf("\nRoom Assigned to Patient : ");
    scanf(" %3[^\n]",room);
    system("cls");
    int EFR = searchPatient(room);
    FILE *patient_f;
    patient_f = fopen("Patient.txt","a");
    if (EFR==1)
    {
        printf(">>>%s This room is in Use by ^^^ ",room);
    }
    if(patient_f==NULL)
    {
        system("cls");
        printf(">>>Error encountered while Opening Patient.txt ");
    }
    else if (EFR==0&&patient_f!=NULL)
    {
        system("cls");
        fprintf(patient_f,"\n%s   %s   %s  %s  %s ",Name,Age,phone,Nid,room);
        printf(">>>Added to File Patient.txt ");
    }

    fclose(patient_f);


}
void viewPatients()
{
    FILE *patient_f;
    char str[10000];

    patient_f = fopen("Patient.txt", "r");
    if (patient_f == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    while (fgets(str, 10000,patient_f) != NULL)
    {
        printf("%s", str);
    }

    fclose(patient_f);
}
int searchPatient(char search[])
{
    char line[100];
    FILE *patient_f = fopen("Patient.txt", "r");

    if (patient_f == NULL)
    {
        printf("Error: Error encountered while Opening Patient.txt \n");
        return 0;
    }

    while (fgets(line, sizeof(line), patient_f) != NULL)
    {
        if (strstr(line, search) != NULL)
        {
            system("cls");
            printf("%s", line);
            fclose(patient_f);
            return 1;
        }
    }

    fclose(patient_f);
    return 0;
}

void updatePatient()
{
    FILE *patient_f1;
    FILE *patient_f2;
    patient_f1=fopen("Patient.txt","r");
    if(patient_f1==NULL)
    {
        printf("Error while opening file Patient.txt\n");
        return;
    }

    patient_f2=fopen("Temp.txt","w");
    if(patient_f2==NULL)
    {
        printf("Error while opening file Temp.txt\n");
        return;
    }

    char Name_Update[50];
    printf("Enter Patient Name to update:");
    scanf(" %49[^\n]",Name_Update);

    char line[100];
    int found=0;

    while(fgets(line,100,patient_f1)!=NULL)
    {
        if(strstr(line,Name_Update)!=NULL)
        {
            found=1;
            system("cls");
            printf(">>>Found!Enter new details below:\n");

            char Name[15];
            char Age[3];
            char phone[12];
            char Nid[11];
            char room[4];
            printf("Patient Name: ");
            scanf(" %10[^\n]",Name);
            printf("\nPatient Age: ");
            scanf(" %2[^\n]",Age);
            printf("\nPatient Phone: ");
            scanf(" %10[^\n]",phone);
            printf("\nPatient NID: ");
            scanf(" %[^\n]",Nid);
            printf("\nRoom Assigned to Patient : ");
            scanf(" %3[^\n]",room);
            system("cls");

            fprintf(patient_f2,"\n%s %s %s %s %s ",Name,Age,phone,Nid,room);

        }
        else
        {
            fputs(line,patient_f2);
        }
    }
    fclose(patient_f1);
    fclose(patient_f2);

    remove("Patient.txt");
    rename("Temp.txt","Patient.txt");

    if(found)
    {
        system("cls");
        printf(">>>Patient Information Update Successfully!\n");
    }
    else
    {
        system("cls");
        printf(">>>Patient Not Found!\n");
    }
}
void deletePatient(char Name_Remove[])
{
    FILE *patient_f1;
    FILE *patient_f2;
    patient_f1=fopen("Patient.txt","r");
    if(patient_f1==NULL)
    {
        printf("Error while opening file Doctor.txt\n");
        return;
    }

    patient_f2=fopen("Temp.txt","w");
    if(patient_f2==NULL)
    {
        printf("Error while opening file Doctor.txt\n");
        return;
    }

    char line[100];
    int found=0;

    while(fgets(line,100,patient_f1)!=NULL)
    {
        if(strstr(line,Name_Remove)==NULL)
        {
            fputs(line,patient_f2);
        }
        else
        {
            found=1;
        }
    }

    fclose(patient_f1);
    fclose(patient_f2);

    remove("Patient.txt");
    rename("Temp.txt","Patient.txt");

    if(found)
    {
        system("cls");
        printf(">>>Patient Removed Successfully!\n");
    }
    else
    {
        system("cls");
        printf(">>>Patient Not Found!\n");
    }
}
