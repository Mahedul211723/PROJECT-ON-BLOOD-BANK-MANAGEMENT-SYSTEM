#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DONORS 100
#define MAX_RECEIVERS 100
#define MAX_NAME_LENGTH 50
#define MAX_BLOOD_GROUP_LENGTH 5
#define MAX_LOCATION_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_DATE_LENGTH 15
#define MAX_DISCIPLINE_LENGTH 50
#define MAX_STUDENT_ID_LENGTH 15
#define FILENAME "blood_donation_data.txt"


void login() {
    char username[20];
    char password[20];

    printf("User - Login\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Fixed username and password for simplicity
    char correctUsername[] = "admin";
    char correctPassword[] = "password";

    if (strcmp(username, correctUsername) != 0 || strcmp(password, correctPassword) != 0) {
        printf("Invalid username or password. Exiting...\n\n");
        printf("\n\nplease login again and input correct information\n");
        login();
    } else {
        printf("Login successful!\n");
    }
}
// Function to add a new donor to the database
void addDonor(int donorIds[], char donorNames[][MAX_NAME_LENGTH], char donorBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char donorLocations[][MAX_LOCATION_LENGTH], char donorPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char donationDates[][MAX_DATE_LENGTH], char donorDisciplines[][MAX_DISCIPLINE_LENGTH], char donorStudentIds[][MAX_STUDENT_ID_LENGTH], int *numDonors) {
    printf("Enter donor details:\n");
    printf("ID: %d\n", *numDonors + 1);
    donorIds[*numDonors] = *numDonors + 1;
    printf("Name: ");
    scanf("%s", donorNames[*numDonors]);
    printf("Blood Group: ");
    scanf("%s", donorBloodGroups[*numDonors]);
    printf("Location: ");
    scanf("%s", donorLocations[*numDonors]);
    printf("Phone Number: ");
    scanf("%s", donorPhoneNumbers[*numDonors]);
    printf("Donation Date (YYYY-MM-DD): ");
    scanf("%s", donationDates[*numDonors]);
    printf("University Discipline: ");
    scanf("%s", donorDisciplines[*numDonors]);
    printf("Student ID: ");
    scanf("%s", donorStudentIds[*numDonors]);

    (*numDonors)++;
    printf("Donor added successfully.\n");
}

// Function to add a new receiver to the database
void addReceiver(int receiverIds[], char receiverNames[][MAX_NAME_LENGTH], char receiverBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char receiverLocations[][MAX_LOCATION_LENGTH], char receiverPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char receiverDisciplines[][MAX_DISCIPLINE_LENGTH], char receiverStudentIds[][MAX_STUDENT_ID_LENGTH], int *numReceivers) {
    printf("Enter receiver details:\n");
    printf("ID: %d\n", *numReceivers + 1);
    receiverIds[*numReceivers] = *numReceivers + 1;
    printf("Name: ");
    scanf("%s", receiverNames[*numReceivers]);
    printf("Blood Group: ");
    scanf("%s", receiverBloodGroups[*numReceivers]);
    printf("Location: ");
    scanf("%s", receiverLocations[*numReceivers]);
    printf("Phone Number: ");
    scanf("%s", receiverPhoneNumbers[*numReceivers]);
    printf("University Discipline: ");
    scanf("%s", receiverDisciplines[*numReceivers]);
    printf("Student ID: ");
    scanf("%s", receiverStudentIds[*numReceivers]);

    (*numReceivers)++;
    printf("Receiver added successfully.\n");
}
// Function to search the database based on various criteria
void searchDatabase(int donorIds[], char donorNames[][MAX_NAME_LENGTH], char donorBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char donorLocations[][MAX_LOCATION_LENGTH], char donorPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char donorDisciplines[][MAX_DISCIPLINE_LENGTH], char donorStudentIds[][MAX_STUDENT_ID_LENGTH], int numDonors, int receiverIds[], char receiverNames[][MAX_NAME_LENGTH], char receiverBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char receiverLocations[][MAX_LOCATION_LENGTH], char receiverPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char receiverDisciplines[][MAX_DISCIPLINE_LENGTH], char receiverStudentIds[][MAX_STUDENT_ID_LENGTH], int numReceivers) {
    int choice;
    printf("Search by:\n");
    printf("1. Donor\n2. Receiver\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("Search criteria:\n");
            printf("1. Name\n2. Blood Group\n3. Location\n4. University Discipline\n");
            int searchChoice;
            scanf("%d", &searchChoice);

            switch (searchChoice) {
                case 1: {
                    char searchName[MAX_NAME_LENGTH];
                    printf("Enter donor name to search: ");
                    scanf("%s", searchName);

                    int found = 0;
                    for (int i = 0; i < numDonors; i++) {
                        if (strcmp(donorNames[i], searchName) == 0) {
                            printf("Donor found:\n");
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", donorIds[i], donorNames[i], donorBloodGroups[i], donorLocations[i], donorPhoneNumbers[i], donorDisciplines[i], donorStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("Donor not found.\n");
                    }
                    break;
                }
                case 2: {
                    char searchBloodGroup[MAX_BLOOD_GROUP_LENGTH];
                    printf("Enter blood group to search: ");
                    scanf("%s", searchBloodGroup);

                    int found = 0;
                    printf("Donors with blood group %s:\n", searchBloodGroup);
                    for (int i = 0; i < numDonors; i++) {
                        if (strcmp(donorBloodGroups[i], searchBloodGroup) == 0) {
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", donorIds[i], donorNames[i], donorBloodGroups[i], donorLocations[i], donorPhoneNumbers[i], donorDisciplines[i], donorStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("No donors found with blood group %s.\n", searchBloodGroup);
                    }
                    break;
                }
                case 3: {
                    char searchLocation[MAX_LOCATION_LENGTH];
                    printf("Enter location to search: ");
                    scanf("%s", searchLocation);

                    int found = 0;
                    for (int i = 0; i < numDonors; i++) {
                        if (strcmp(donorLocations[i], searchLocation) == 0) {
                            printf("Donor found:\n");
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", donorIds[i], donorNames[i], donorBloodGroups[i], donorLocations[i], donorPhoneNumbers[i], donorDisciplines[i], donorStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("Donor not found.\n");
                    }
                    break;
                }
                case 4: {
                    char searchDiscipline[MAX_DISCIPLINE_LENGTH];
                    printf("Enter university discipline to search: ");
                    scanf("%s", searchDiscipline);

                    int found = 0;
                    for (int i = 0; i < numDonors; i++) {
                        if (strcmp(donorDisciplines[i], searchDiscipline) == 0) {
                            printf("Donor found:\n");
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", donorIds[i], donorNames[i], donorBloodGroups[i], donorLocations[i], donorPhoneNumbers[i], donorDisciplines[i], donorStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("Donor not found.\n");
                    }
                    break;
                }
                default:
                    printf("Invalid choice.\n");
            }
            break;
        }
        case 2: {
            printf("Search criteria for receivers:\n");
            printf("1. Name\n2. Blood Group\n3. Location\n4. University Discipline\n");
            int searchChoice;
            scanf("%d", &searchChoice);

            switch (searchChoice) {
                case 1: {
                    char searchName[MAX_NAME_LENGTH];
                    printf("Enter receiver name to search: ");
                    scanf("%s", searchName);

                    int found = 0;
                    for (int i = 0; i < numReceivers; i++) {
                        if (strcmp(receiverNames[i], searchName) == 0) {
                            printf("Receiver found:\n");
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", receiverIds[i], receiverNames[i], receiverBloodGroups[i], receiverLocations[i], receiverPhoneNumbers[i], receiverDisciplines[i], receiverStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("Receiver not found.\n");
                    }
                    break;
                }
                case 2: {
                    char searchBloodGroup[MAX_BLOOD_GROUP_LENGTH];
                    printf("Enter blood group to search: ");
                    scanf("%s", searchBloodGroup);

                    int found = 0;
                    printf("Receivers with blood group %s:\n", searchBloodGroup);
                    for (int i = 0; i < numReceivers; i++) {
                        if (strcmp(receiverBloodGroups[i], searchBloodGroup) == 0) {
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", receiverIds[i], receiverNames[i], receiverBloodGroups[i], receiverLocations[i], receiverPhoneNumbers[i], receiverDisciplines[i], receiverStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("No receivers found with blood group %s.\n", searchBloodGroup);
                    }
                    break;
                }
                case 3: {
                    char searchLocation[MAX_LOCATION_LENGTH];
                    printf("Enter location to search: ");
                    scanf("%s", searchLocation);

                    int found = 0;
                    for (int i = 0; i < numReceivers; i++) {
                        if (strcmp(receiverLocations[i], searchLocation) == 0) {
                            printf("Receiver found:\n");
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", receiverIds[i], receiverNames[i], receiverBloodGroups[i], receiverLocations[i], receiverPhoneNumbers[i], receiverDisciplines[i], receiverStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("Receiver not found.\n");
                    }
                    break;
                }
                case 4: {
                    char searchDiscipline[MAX_DISCIPLINE_LENGTH];
                    printf("Enter university discipline to search: ");
                    scanf("%s", searchDiscipline);

                    int found = 0;
                    for (int i = 0; i < numReceivers; i++) {
                        if (strcmp(receiverDisciplines[i], searchDiscipline) == 0) {
                            printf("Receiver found:\n");
                            printf("ID: %d\nName: %s\nBlood Group: %s\nLocation: %s\nPhone Number: %s\nUniversity Discipline: %s\nStudent ID: %s\n\n", receiverIds[i], receiverNames[i], receiverBloodGroups[i], receiverLocations[i], receiverPhoneNumbers[i], receiverDisciplines[i], receiverStudentIds[i]);
                            found = 1;
                        }
                    }

                    if (!found) {
                        printf("Receiver not found.\n");
                    }
                    break;
                }
                default:
                    printf("Invalid choice.\n");
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
    }

}

// Function to save data to a file
void saveData(int donorIds[], char donorNames[][MAX_NAME_LENGTH], char donorBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char donorLocations[][MAX_LOCATION_LENGTH], char donorPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char donationDates[][MAX_DATE_LENGTH], char donorDisciplines[][MAX_DISCIPLINE_LENGTH], char donorStudentIds[][MAX_STUDENT_ID_LENGTH], int numDonors, int receiverIds[], char receiverNames[][MAX_NAME_LENGTH], char receiverBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char receiverLocations[][MAX_LOCATION_LENGTH], char receiverPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char receiverDisciplines[][MAX_DISCIPLINE_LENGTH], char receiverStudentIds[][MAX_STUDENT_ID_LENGTH], int numReceivers) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("File is empty.\n");
        return;
    }

    // Write donor data to file
    fprintf(file, "Donors:\n");
    for (int i = 0; i < numDonors; i++) {
        fprintf(file, "%d %s %s %s %s %s %s %s\n", donorIds[i], donorNames[i], donorBloodGroups[i], donorLocations[i], donorPhoneNumbers[i], donationDates[i], donorDisciplines[i], donorStudentIds[i]);
    }

    // Write receiver data to file
    fprintf(file, "Receivers:\n");
    for (int i = 0; i < numReceivers; i++) {
        fprintf(file, "%d %s %s %s %s %s %s %s\n", receiverIds[i], receiverNames[i], receiverBloodGroups[i], receiverLocations[i], receiverPhoneNumbers[i], receiverDisciplines[i], receiverStudentIds[i]);
    }

    fclose(file);
    printf("Data saved successfully.\n");
}

// Function to load data from a file
void loadData(int donorIds[], char donorNames[][MAX_NAME_LENGTH], char donorBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char donorLocations[][MAX_LOCATION_LENGTH], char donorPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char donationDates[][MAX_DATE_LENGTH], char donorDisciplines[][MAX_DISCIPLINE_LENGTH], char donorStudentIds[][MAX_STUDENT_ID_LENGTH], int *numDonors, int receiverIds[], char receiverNames[][MAX_NAME_LENGTH], char receiverBloodGroups[][MAX_BLOOD_GROUP_LENGTH], char receiverLocations[][MAX_LOCATION_LENGTH], char receiverPhoneNumbers[][MAX_PHONE_NUMBER_LENGTH], char receiverDisciplines[][MAX_DISCIPLINE_LENGTH], char receiverStudentIds[][MAX_STUDENT_ID_LENGTH], int *numReceivers) {
    FILE *file = fopen("FILENAME", "r");
    if (file == NULL) {
        printf("File is empty.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "Donors:") != NULL) {
            while (fgets(line, sizeof(line), file) != NULL && strstr(line, "Receivers:") == NULL) {
                sscanf(line, "%d %s %s %s %s %s %s %s", &donorIds[*numDonors], donorNames[*numDonors], donorBloodGroups[*numDonors], donorLocations[*numDonors], donorPhoneNumbers[*numDonors], donationDates[*numDonors], donorDisciplines[*numDonors], donorStudentIds[*numDonors]);
                (*numDonors)++;
            }
        }
        else if (strstr(line, "Receivers:") != NULL) {
            while (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "%d %s %s %s %s %s %s %s", &receiverIds[*numReceivers], receiverNames[*numReceivers], receiverBloodGroups[*numReceivers], receiverLocations[*numReceivers], receiverPhoneNumbers[*numReceivers], receiverDisciplines[*numReceivers], receiverStudentIds[*numReceivers]);
                (*numReceivers)++;
            }
        }
    }

    fclose(file);
}

// Function to exit the program
void exitProgram() {
    printf("Exiting program.\n");
    exit(0);
}
int main() {
    printf("\t\t\t\t\t****BLOOD DONATION MANAGEMENT SYSTEM****\n\n");

    login();


    int donorIds[MAX_DONORS], receiverIds[MAX_RECEIVERS];
    char donorNames[MAX_DONORS][MAX_NAME_LENGTH], donorBloodGroups[MAX_DONORS][MAX_BLOOD_GROUP_LENGTH], donorLocations[MAX_DONORS][MAX_LOCATION_LENGTH], donorPhoneNumbers[MAX_DONORS][MAX_PHONE_NUMBER_LENGTH], donationDates[MAX_DONORS][MAX_DATE_LENGTH], donorDisciplines[MAX_DONORS][MAX_DISCIPLINE_LENGTH], donorStudentIds[MAX_DONORS][MAX_STUDENT_ID_LENGTH];
    char receiverNames[MAX_RECEIVERS][MAX_NAME_LENGTH], receiverBloodGroups[MAX_RECEIVERS][MAX_BLOOD_GROUP_LENGTH], receiverLocations[MAX_RECEIVERS][MAX_LOCATION_LENGTH], receiverPhoneNumbers[MAX_RECEIVERS][MAX_PHONE_NUMBER_LENGTH], receiverDisciplines[MAX_RECEIVERS][MAX_DISCIPLINE_LENGTH], receiverStudentIds[MAX_RECEIVERS][MAX_STUDENT_ID_LENGTH];
    int  numDonors = 0, numReceivers = 0;
    int choice;

    loadData(donorIds, donorNames, donorBloodGroups, donorLocations, donorPhoneNumbers, donationDates, donorDisciplines, donorStudentIds, &numDonors, receiverIds, receiverNames, receiverBloodGroups, receiverLocations, receiverPhoneNumbers, receiverDisciplines, receiverStudentIds, &numReceivers);

    do {

        printf("1. Add Donor\n");
        printf("2. Add Receiver\n");
        printf("3. Search Database\n");
        printf("4. Save Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addDonor(donorIds, donorNames, donorBloodGroups, donorLocations, donorPhoneNumbers, donationDates, donorDisciplines, donorStudentIds, &numDonors);
                break;
            case 2:
                addReceiver(receiverIds, receiverNames, receiverBloodGroups, receiverLocations, receiverPhoneNumbers, receiverDisciplines, receiverStudentIds, &numReceivers);
                break;
            case 3:
                searchDatabase(donorIds, donorNames, donorBloodGroups, donorLocations, donorPhoneNumbers, donorDisciplines, donorStudentIds, numDonors, receiverIds, receiverNames, receiverBloodGroups, receiverLocations, receiverPhoneNumbers, receiverDisciplines, receiverStudentIds, numReceivers);
                break;
            case 4:
                saveData(donorIds, donorNames, donorBloodGroups, donorLocations, donorPhoneNumbers, donationDates, donorDisciplines, donorStudentIds, numDonors, receiverIds, receiverNames, receiverBloodGroups, receiverLocations, receiverPhoneNumbers, receiverDisciplines, receiverStudentIds, numReceivers);
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


