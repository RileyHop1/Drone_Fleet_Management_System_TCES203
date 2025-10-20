#include <stdio.h>

#define MAX_NAME_LEN   50
#define MAX_FLEET_SIZE 100

int   ids[MAX_FLEET_SIZE];
char  myModels[MAX_FLEET_SIZE][MAX_NAME_LEN + 1]; 
float myBatteries[MAX_FLEET_SIZE];
float myPositions[MAX_FLEET_SIZE][2];            
int   count = 0;

void addDrone(void){
    if (count >= MAX_FLEET_SIZE) { puts("Fleet full."); return; }

    int   id;
    float bat, x, y;

    printf("ID (>0): ");
    if (scanf("%d", &id) != 1 || id <= 0) { puts("Invalid ID."); return; }

    printf("Model (<=%d chars): ", MAX_NAME_LEN);
    if (scanf(" %50[^\n]", myModels[count]) != 1) { puts("Invalid name."); return; }



