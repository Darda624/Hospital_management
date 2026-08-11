#include <stdio.h>
#include "Room.h"

void RoomMain(){
    printf("1. View Rooms\n");
    printf("2. Assign Room\n");
    printf("3. Release Room\n");
    printf("4. Search Room\n");
    printf("5. Exit \n");
    int RoomTF=1;
    while(RoomTF){
        char RoomIO;
        scanf(" %c",&RoomIO);
        switch (RoomIO){
            case '1':{
            viewRooms();
            break;
            }
            case '2':{
            assignRoom();
            break;
            }
            case '3':{
            releaseRoom();
            break;
            }
            case '4':{
            searchRoom();
            break;
            }
            case '5':{
            RoomTF =0;
            break;
            }
            default:{
            printf(">>> Error encountered while talking input ");
            }

        }
    }
}
void viewRooms(){

}
void assignRoom(){

}
void releaseRoom(){

}
void searchRoom(){

}
