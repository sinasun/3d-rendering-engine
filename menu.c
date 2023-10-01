#include "menu.h"

/*print the menu option*/
const float pi = 3.14159265358979323846;
int angle_a, angle_b, angle_c;

int menu()
{
    char *menuOptions[] = {"Add object", "Add lighting", "Render screen", "Exit"};
    int menuLength = sizeof(menuOptions) / sizeof(menuOptions[0]);

    while (1)
    {
        printf("\n");
        for (int i = 0; i < menuLength; i++)
        {
            printf("%d: %s \n", i + 1, menuOptions[i]);
        }
		
		int pick = getInteger(">: ", 1, menuLength);

        switch (pick)
        {
        case 1:
			angle_a = getInteger("Enter degree: ", 0, 360);
            angle_b = getInteger("Enter degree: ", 0, 360);
            angle_c = getInteger("Enter degree: ", 0, 360);
			float objectMatrix[3][3];
            matrices(degreeToRad(angle_a), degreeToRad(angle_b), degreeToRad(angle_c), objectMatrix);
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

int getInteger(char* prompt, int min, int max)
{
    int number;
    printf("%s", prompt);
    while (scanf("%d", &number) != 1 && number >= min && number <= max)
    {
        printf("Enter a valid option\n");
        while (getchar() != '\n')
        {
            continue;
        }
        printf("%s", prompt);
    }
	return number;
}
