#ifndef HANDLE_DATABASE_   
#define HANDLE_DATABASE_

#include "AccessibilityStructures.h"
#include <stdbool.h>
#include "sqlite3.h"



/*
Following C code segment shows how to connect to an existing database.
If the database does not exist, then it will be created and finally a database object will be returned.
*/

int insertANewyVideoFile(AccessibilityVideoFile newFile);

static int callbackForInsert(void *NotUsed, int argc, char **argv, char **azColName);

AccessibilityVideoFile* getFirstVideoFileFromQueue();

bool deleteFirstVideoFileFromQueue();

static int callback(void *data, int argc, char **argv, char **azColName);


int setMyTViewOnAndOff();

void setAccessibilityMode(char *accessibilityMode);

void setUserPlayRate(float userPlayRate);

void setUserBrightness(int userBrightness);

void setUserNoiseReduction(int userNoiseReduction);



bool checkIfVideoAccessibilityIsOn();

bool checkIfExist();

void updateUserConfiguration(UserConfiguration userConfiguration);


void setUserConfigurationAsDefault();

void resetPlaylist();

UserConfiguration* getUserConfiguration();

AccessibilityVideoFile* getNextFile();




#endif