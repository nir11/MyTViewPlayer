#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HandleDatabase.h" /* Include the header here, to obtain the function declaration */
#include "sqlite3.h"
#include "AccessibilityStructures.h"

int main(void)
{
	//sqlite3 *db = connectToDB();			// database connecti


	/*AccessibilityVideoFile newFile;
	//char* path = "C:\\Users\\TzChen\\Videos\\Frozen (2013)\\Frozen.2013.720p.BluRay.x264.YIFY.mp4";
	char* path = "C:\\MyTView\\videos\\Videos\\earth.mp4";
	// newFile specification 
	newFile.path = malloc(strlen(path)+1);
	strcpy_s(newFile.path,strlen(path)+1, path);
	newFile.playRate = 1.3;
	newFile.brightness = 35;
	newFile.noiseReduction = 4;

	// insert newFile into the DB 
	if (!insertANewyVideoFile(newFile))
	{
		printf("Couldn't store file\n");
		free(newFile.path);
		exit(0);
	}
	free(newFile.path);
	*/
	


	


	AccessibilityVideoFile* currVideoFile;
	while (1)
	{
		currVideoFile = getFirstVideoFileFromQueue();
		if (currVideoFile != NULL)
		{
			Play(currVideoFile);
			//deleteFirstVideoFileFromQueue();
		}
		else
		{
			printf("Buffering..\n");
			exit(0);
		}
	} 

	//setMyTViewOnAndOff();

	/* get the first file from the queue in the DB */
	/*getVideoFileFromDB();*/
	

	

	/*setMyTViewOnAndOff(db, "1");
	setAccessibilityMode(db, "Fixed");
	
	setUserPlayRate(db, 98);*/
}