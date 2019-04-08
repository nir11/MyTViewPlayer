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

void getVideoFileFromDB(sqlite3 *db);

static int callback(void *data, int argc, char **argv, char **azColName);

void setMyTViewOnAndOff(sqlite3 *db, char* mode);

void setAccessibilityMode(sqlite3 *db, char *accessibilityMode);

void setUserPlayRate(sqlite3 *db, float userPlayRate);

void setUserBrightness(sqlite3 *db, int userBrightness);

void setUserNoiseReduction(sqlite3 *db, int userNoiseReduction);



bool checkIfVideoAccessibilityIsOn();

bool checkIfExist();

void updateUserConfiguration(UserConfiguration userConfiguration);


void setUserConfigurationAsDefault();

void resetPlaylist();

UserConfiguration getUserConfiguration();

AccessibilityVideoFile getNextFile();




#endif