#include <stdio.h>
//#include "HandleDatabase.h" /* Include the header here, to obtain the function declaration */
#include "sqlite3.h"
#include "AccessibilityStructures.h"

int main(void)
{
	sqlite3 *db = connectToDB();			// database connection
	AccessibilityVideoFile newFile;

	/* newFile specification */
	newFile.path = malloc(sizeof("C:\MyTView\videos\samplevide1.3gp"));
	strcpy(newFile.path, "C:\MyTView\videos\samplevide1.3gp");
	newFile.playRate = 1.3;
	newFile.brightness = 85;
	newFile.noiseReduction = 90;

	/* insert newFile into the DB */
	//insertANewyVideoFile(db, newFile);
	

	AccessibilityVideoFile currFile;
	/* get the first file from the queue in the DB */
	selectVideoFileFromDB(db);


}