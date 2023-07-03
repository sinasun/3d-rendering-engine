#include "menu.h"

/*print the menu option*/
const float pi = 3.14159265358979323846;
int angle_a, angle_b, angle_c;

int menu() {
  char *menuOptions[] = {"Add object", "Add lighting", "render screen", "Exit"};

  int length = sizeof(menuOptions) / sizeof(menuOptions[0]);

  while (1) {
    printf("\n");
    for (int i = 0; i < length; i++) {
      printf("%d: %s \n", i + 1, menuOptions[i]);
    }
    printf(">: ");
    int pick;
    int check = scanf("%d", &pick);

    while (check != 1 || pick < 0) {
      printf("Enter a valid option\n");
      /*clear buffer*/
      while (getchar() != '\n') {
        continue;
      }
      printf(">: ");
      check = scanf("%d", &pick);
    }

    switch (pick) {
      case 1:
        angle_a= getDegree();
        angle_b = getDegree();
        angle_c = getDegree();
        
        matrices(degreeToRad(angle_a), degreeToRad(angle_b), degreeToRad(angle_c));
        break;

      case 2:

        break;

      case 3:
        /*implement render.c*/
        createScreen();
        break;

      case 4:
        printf("Exiting...\n");
        return 0;
        break;
      default:
        printf("\nEnter a valid option\n");
        break;
    }
  }
  return 0;
}

float degreeToRad(float degree) { return degree * pi / 180; }

int getDegree() {
  int angle;
  printf("Enter angle: ");
  scanf("%d", &angle);
  return angle;
}