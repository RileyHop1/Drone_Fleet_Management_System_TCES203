// TCES 203 Project: Drone Fleet Management System
// Name: Jinal Thummar 
// Variation 1A: Basic Console Menu
// Variation 2A: Enhanced Search 

#include <string.h>
#include <ctype.h>

#define MAX_FLEET 100
#define MAX_NAME_LEN 50

int ids[MAX_FLEET];
char models[MAX_FLEET][MAX_NAME_LEN];
float batteries[MAX_FLEET];
float positions[MAX_FLEET][2];
int count = 0;

//Convert into lowerCase
void toLowerStr(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = (char)tolower(s[i]);
    }
}

void addDrone(void) {
    if (count >= MAX_FLEET) {
        printf("Fleet full!\n");
        return;
    }

    int id;
    float bat, x, y;
    char name[MAX_NAME_LEN];

    printf("Enter Drone ID (>0): ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter Model Name (max %d chars): ", MAX_NAME_LEN - 1);
    scanf(" %[^\n]", name);

    printf("Enter Battery Level (0-100): ");
    if (scanf("%f", &bat) != 1 || bat < 0 || bat > 100) {
        printf("Invalid battery level.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter Position (x y): ");
    if (scanf("%f %f", &x, &y) != 2) {
        printf("Invalid position.\n");
        while (getchar() != '\n');
        return;
    }

    ids[count] = id;
    strcpy(models[count], name);
    batteries[count] = bat;
    positions[count][0] = x;
    positions[count][1] = y;
    count++;

    printf("✅ Drone added successfully!\n");
}

void displayDrones(void) {
    if (count == 0) {
        printf("No drones available.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-6s %-6s\n", "ID", "Model", "Battery", "X", "Y");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10.1f %-6.1f %-6.1f\n",
               ids[i], models[i], batteries[i],
               positions[i][0], positions[i][1]);
    }
}

void searchDroneByID(int id) {
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            printf("\nDrone Found:\n");
            printf("ID: %d\nModel: %s\nBattery: %.1f%%\nPosition: (%.1f, %.1f)\n",
                   ids[i], models[i], batteries[i],
                   positions[i][0], positions[i][1]);
            return;
        }
    }
    printf("Drone not found.\n");
}

void searchDroneByModel(char *model) {
    char lowerModel[MAX_NAME_LEN];
    strcpy(lowerModel, model);
    toLowerStr(lowerModel);

    int found = 0;
    for (int i = 0; i < count; i++) {
        char temp[MAX_NAME_LEN];
        strcpy(temp, models[i]);
        toLowerStr(temp);
        if (strcmp(temp, lowerModel) == 0) {
            printf("\nDrone Found:\n");
            printf("ID: %d\nModel: %s\nBattery: %.1f%%\nPosition: (%.1f, %.1f)\n",
                   ids[i], models[i], batteries[i],
                   positions[i][0], positions[i][1]);
            found = 1;
        }
    }
    if (!found)
        printf("Drone not found.\n");
}

void calculateAverageBattery(void) {
    if (count == 0) {
        printf("No drones available.\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += batteries[i];
    }
    printf("Average Battery Level: %.2f%%\n", sum / count);
}

int main(void) {
    int choice;

    while (1) {
        printf("\n===== Drone Fleet Management =====\n");
        printf("1. Add Drone\n");
        printf("2. Display All Drones\n");
        printf("3. Search Drone by ID\n");
        printf("4. Search Drone by Model (case-insensitive)\n");
        printf("5. Show Average Battery\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addDrone(); break;
            case 2: displayDrones(); break;
            case 3: {
                int id;
                printf("Enter Drone ID: ");
                scanf("%d", &id);
                searchDroneByID(id);
                break;
            }
            case 4: {
                char model[MAX_NAME_LEN];
                printf("Enter Model Name: ");
                scanf(" %[^\n]", model);
                searchDroneByModel(model);
                break;
            }
            case 5: calculateAverageBattery(); break;
            case 6: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
