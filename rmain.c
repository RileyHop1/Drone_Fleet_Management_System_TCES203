#include <stdio.h>

#define MAX_NAME_LEN 50
#define MAX_FLEET_SIZE 100
#define MAX_BATTERY 100.0f
#define MINIMUM_BATTERY 0.0f

int myIds[MAX_FLEET_SIZE];
int myNumberOfDrones = 0;

char myModels[][MAX_NAME_LEN];

float myBatteries[];
float myPositions[][2];

/**Checks if an ID is valid for input*/
int checkId(const int theID) {
    
    //Return false if ID is negative
    if ( 0 > theID) return 0;
    
    //Return false if ID already exsists
    for (int i = 0; i < MAX_FLEET_SIZE;i++ ) {

       if ( myIds[i] == theID) return 0;
    }
    
    return 1;
}
/**Checks if a name is valid. */
int checkName(const char theName[]) {
    if (sizeof(theName) > sizeof(char) * MAX_NAME_LEN) return 0;
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
    char name[MAX_NAME_LEN];
    float batteryLevel = 0.0f;

    float pos[2];
    
    while(1) {
        printf("Please input a positive ID for the drone in the formate (N): ");
        
        if (scanf("%d", &tempID) == 1 
            && checkId(tempID)) break;

	    printf("ERROR: not a valid ID please try again\n");
    }

    while(1) {
        printf("Please input a name for your drone in the formate(Name): ");
        
        if (scanf("%s", name) == 1 
            && checkName(name) ) break;

        printf("ERROR: not a valid name please try again\n");
        
    }
    
    while(1) {
        printf("Please input what battery level your drone is at, btween 0.0 and 100.0(f.f): ");
        
        if (scanf("%f", &batteryLevel) == 1 
            && checkBattery(batteryLevel) ) break;

        printf("ERROR: not a valid battery level please try again\n");
        
    }
   //TODO: Update this to take a float 
    while(1) {
        int correctInput = 0;

        printf("Please input the x-coord for your drone(D.D): ");
        
        if (scanf("%f", &pos[0]) == 1) correctInput++;

        printf("Please input the y-coord for your drone(D.D): ");

        if (scanf("%f", &pos[1]) == 1) correctInput++;
        if (correctInput == 2) break;

        printf("ERROR: incorrect input, please try again\n");
        
    }
    myNumberOfDrones++;


}
/**This function displays all drones. */
void displayDrone() {

}
int main(void) {

	return 0;
}
