#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HandleDatabase.h" /* Include the header here, to obtain the function declaration */
#include "sqlite3.h"
#include "AccessibilityStructures.h"

int main(void)
{
	sqlite3 *db = connectToDB();			// database connection
	AccessibilityVideoFile newFile;
	char path[] = "C:\\MyTView\\videos\\samplevide1.3gp";

	/* newFile specification */
	newFile.path = malloc(strlen(path)+1);
	strcpy_s(newFile.path,strlen(path)+1, path);
	printf(newFile.path); //check
	newFile.playRate = (float)1.3;
	newFile.brightness = 85;
	newFile.noiseReduction = 90;

	/* insert newFile into the DB */
	//insertANewyVideoFile(db, newFile);
	

	AccessibilityVideoFile* currFile=NULL;
	/* get the first file from the queue in the DB */
	//selectVideoFileFromDB(db);
	
	setMyTViewOnAndOff(db, "1");
	setAccessibilityMode(db, "Fixed");
	
	setUserPlayRate(db, 98);
}