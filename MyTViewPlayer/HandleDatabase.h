#ifndef HANDLE_DATABASE_   
#define HANDLE_DATABASE_

#include "AccessibilityStructures.h"
#include <stdbool.h>
#include "sqlite3.h"



/*
Following C code segment shows how to connect to an existing database.
If the database does not exist, then it will be created and finally a database object will be returned.
*/
sqlite3* connectToDB();

void insertANewyVideoFile(sqlite3 *db, AccessibilityVideoFile newFile);

static int callbackForInsert(void *NotUsed, int argc, char **argv, char **azColName);

void selectVideoFileFromDB(sqlite3 *db);

static int callbackForSelect(void *data, int argc, char **argv, char **azColName);


bool checkIfVideoAccessibilityIsOn();

bool checkIfExist();

void updateUserConfiguration(UserConfiguration userConfiguration);

void setAccessibilityMode(char *accessibilityMode);

void setUserPlayRate(float userPlayRate);

void setUserBrightness(int userBrightness);

void setUserNoiseReduction(int userNoiseReduction);

void setUserConfigurationAsDefault();

void resetPlaylist();

UserConfiguration getUserConfiguration();

AccessibilityVideoFile getNextFile();




#endif