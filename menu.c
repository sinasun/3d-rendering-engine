#include <stdio.h>
#include "matrix.h"

/*print the menu option*/

void menu(){

    char *menuOptions []= {"Add object", "Add lighting", "render"};

    int length = sizeof(menuOptions)/ sizeof(menuOptions[0]);
   
    for(int i=0; i< length ; i++){
        printf("%d: %s \n",i+1, menuOptions[i]);
    }
    printf(">: ");
    int pick; 
    int check= scanf("%d", &pick);

    while(check !=1 || pick <0){
        printf("Enter a valid option\n");
        /*clear buffer*/
        while( getchar() !='\n'){
            continue;
        }
        printf(">: ");
        check= scanf("%d", &pick);
    }

    switch(pick){
        case 1: 
            matrices(1, 3,4);
            break;

        case 2:
            
            break;

        case 3:
            /*implement render.c*/
            break;
            
        default:
            printf("Enter a valid option");
            break;
    }

   

}