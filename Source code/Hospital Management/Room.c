/**#include <stdio.h>
#include "Room.h"

void RoomMain()
{
    int RoomTF=1;
    while(RoomTF)
    {
        printf("1. View Rooms\n");
        printf("2. Assign Room\n");
        printf("3. Release Room\n");
        printf("4. Search Room\n");
        printf("5. Exit \n");
        char RoomIO;
        scanf(" %c",&RoomIO);
        switch (RoomIO)
        {
        case '1':
        {
            viewRooms();
            break;
        }
        case '2':
        {
            char a[50];
            scanf(" %[^\n]",a);
            assignRoom(a);
            break;
        }
        case '3':
        {
            releaseRoom();
            break;
        }
        case '4':
        {
            char s[50];
            scanf(" %[^\n]",s);
            searchRoom(s);
            break;
        }
        case '5':
        {
            RoomTF =0;
            break;
        }
        default:
        {
            printf(">>> Error encountered while talking input ");
        }

        }
    }
}
void viewRooms()
{


}
void assignRoom(char room[])
{
    FILE *room_f;
    room_f = fopen("Room.txt","a");
    if (room_f == NULL)
    {
        printf(">>> Error: Opening Room.txt \n");
        return;
    }
    else
    {
        fprintf(room_f,"\n %s ",room);

    }
    fclose(room_f);
}
void releaseRoom()
{

}
int searchRoom(char search[])
{

}**/
