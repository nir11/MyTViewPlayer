#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HandleDatabase.h" /* Include the header here, to obtain the function declaration */
#include "sqlite3.h"
#include "AccessibilityStructures.h"

int main(void)
{
	//sqlite3 *db = connectToDB();			// database connecti


	//AccessibilityVideoFile newFile;
	//char* path = "C:\\MyTView\\videos\\samplevide1.3gp";

	///* newFile specification */
	//newFile.path = malloc(strlen(path)+1);
	//strcpy_s(newFile.path,strlen(path)+1, path);
	//newFile.playRate = 1.3;
	//newFile.brightness = 35;
	//newFile.noiseReduction = 4;

	///* insert newFile into the DB */
	//insertANewyVideoFile(newFile);
	

	AccessibilityVideoFile* currFile=NULL;
	/* get the first file from the queue in the DB */
	getVideoFileFromDB();
	
	/*setMyTViewOnAndOff(db, "1");
	setAccessibilityMode(db, "Fixed");
	
	setUserPlayRate(db, 98);*/
}