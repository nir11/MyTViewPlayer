#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HandleDatabase.h" /* Include the header here, to obtain the function declaration */
#include "sqlite3.h"
#include "AccessibilityStructures.h"

int main(void)
{
	//sqlite3 *db = connectToDB();			// database connecti


	AccessibilityVideoFile newFile;
	char* path = "C:\\Users\\TzChen\\Videos\\Frozen (2013)\\Frozen.2013.720p.BluRay.x264.YIFY.mp4";

	///* newFile specification */
	newFile.path = malloc(strlen(path)+1);
	strcpy_s(newFile.path,strlen(path)+1, path);
	newFile.playRate = 1.3;
	newFile.brightness = 35;
	newFile.noiseReduction = 4;

	///* insert newFile into the DB */
	insertANewyVideoFile(newFile);
	

	AccessibilityVideoFile* currVideoFile= getFirstVideoFileFromQueue();
	while (currVideoFile != NULL)
	 {
		printf("Path: %s\n", currVideoFile->path);
		printf("Play Rate: %.2lf\n", currVideoFile->playRate);
		printf("Brightness: %.2lf\n", currVideoFile->brightness);
		printf("NoiseReduction: %.2lf\n", currVideoFile->noiseReduction);

		char* run = malloc(1);
		sprintf_s(run, 250, "start \"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe %s --rate=%.2lf\"", currVideoFile->path, currVideoFile->playRate);
		system(run);

		if (deleteFirstVideoFileFromQueue()); {
			currVideoFile = getFirstVideoFileFromQueue();
		}
	} 

	//setMyTViewOnAndOff();

	/* get the first file from the queue in the DB */
	/*getVideoFileFromDB();*/
	

	

	/*setMyTViewOnAndOff(db, "1");
	setAccessibilityMode(db, "Fixed");
	
	setUserPlayRate(db, 98);*/
}