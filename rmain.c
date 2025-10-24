#include <stdio.h>

#define MAX_NAME_LEN 50
#define MAX_FLEET_SIZE 100
#define MAX_BATTERY 100.0f
#define MINIMUM_BATTERY 0.0f

int myIds[MAX_FLEET_SIZE];
int myNumberOfDrones = 0;

char myModels[MAX_FLEET_SIZE][MAX_NAME_LEN];

float myBatteries[MAX_FLEET_SIZE];
float myPositions[MAX_FLEET_SIZE][2];

/**This clears the input buffer, so there isn't left over characters in the input stream.*/
void clearBuffer(void) {
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

/**Checks if an ID is valid for input*/
int checkId(const int theID) {
    
    //Return false if ID is negative
    if ( 0 > theID) return 0;
    
    //Return false if ID already exsists
    for (int i = 0; i < myNumberOfDrones;i++ ) {

       if ( myIds[i] == theID) return 0;
    }
    
    return 1;
}

/**Checks if the input is a valid battery level. */
int checkBattery(const float theBattery) {
    if (theBattery > MAX_BATTERY || theBattery < MINIMUM_BATTERY) return 0;
    return 1;
}

/**This adds a drone to the fleet.*/
void addDrone(void) {
    
    int tempID = 0;
    float batteryLevel = 0.0f;

    float pos[2];
    
    clearBuffer();
    while(1) {
        printf("Please input a positive ID for the drone in the formate (N): ");
        
        if (scanf("%d", &tempID) == 1 
            && checkId(tempID)) break;

	    printf("ERROR: not a valid ID please try again\n");
        
        clearBuffer();
    }

    clearBuffer();
    while(1) {
        printf("Please input a name for your drone in the formate(Name): ");
        
        
        if (scanf("%49s", myModels[myNumberOfDrones]) == 1) break;

        printf("ERROR: not a valid name please try again\n");
        clearBuffer();
        
    }
    
    clearBuffer();
    while(1) {
        printf("Please input what battery level your drone is at, btween 0.0 and 100.0(f.f): ");

        if (scanf("%f", &batteryLevel) == 1 
            && checkBattery(batteryLevel) ) break;

        printf("ERROR: not a valid battery level please try again\n");
        clearBuffer();
        
    }
   
    clearBuffer();
    while(1) {
        int correctInput = 0;

        printf("Please input the x-coord for your drone(D.D): ");

        if (scanf("%f", &pos[0]) == 1) correctInput++;

        printf("Please input the y-coord for your drone(D.D): ");

        if (scanf("%f", &pos[1]) == 1) correctInput++;
        if (correctInput == 2) break;

        printf("ERROR: incorrect input, please try again\n");
        clearBuffer();
        
    }

    myIds[myNumberOfDrones] = tempID;
    myBatteries[myNumberOfDrones] = batteryLevel;
    myPositions[myNumberOfDrones][0] = pos[0];
    myPositions[myNumberOfDrones][1] = pos[1];
    myNumberOfDrones++;


}

/**This function displays all drones. */
void displayDrones() {

    if (myNumberOfDrones == 0) {

        printf("Your fleet is empty sir.\n");
        return;
    }

    printf("ID\t| Model\t| Battery\t| X-coord\t| Y-coord\t\n");
    for (int i = 0; i < myNumberOfDrones; i++) {
        printf("%d\t| %s\t| %.2f\t| %.2f\t| %.2f\t\n", 
            myIds[i],
            myModels[i],
            myBatteries[i],
            myPositions[i][0],
            myPositions[i][1]);
    }
}
int main(void) {

    int running = 1;
    //Simulation loop
    while (running) {
        int command = 0;
        printf("Please enter the assciated number with your command.\n");
        printf("1. Add a drone.\n2. Display all drones.\n3. Exit\n");

        if (scanf("%d", &command) != 1) {
            clearBuffer();
            printf("Error: incorrect command entered, please try again.\n");
            continue;
        } if (command < 1 || command > 3) {
            printf("Error: invalid command, please try again.\n");
            continue;
        }


        switch(command) {
            case 1:
                addDrone();
                break;
            case 2:
                displayDrones();
                break;
            case 3:
                printf("Shutting down.\n");
                running = 0;
                continue;
            default:
                printf("Error: Program failure"); 
                break;
        }
    }
    

	return 0;
}
