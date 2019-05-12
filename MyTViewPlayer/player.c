#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AccessibilityStructures.h"
#include "sqlite3.h"

static int counter = 1;

void Play(AccessibilityVideoFile* videoFile) {

	/*printf("Path: %s\n", videoFile->path);
	printf("Play Rate: %.2lf\n", videoFile->playRate);
	printf("Brightness: %.2lf\n", videoFile->brightness);
	printf("NoiseReduction: %.2lf\n", videoFile->noiseReduction);*/

	printf("Playing file number: %d\n", counter);
	counter++;
	char* vlcPath = "C:\\Program Files (x86)\\VideoLAN\VLC\\vlc.exe";
	char* run = sqlite3_mprintf("start \"%s %s --rate=%.2lf\"", vlcPath, videoFile->path, videoFile->playRate);
	printf("%s\n\n", run);

	system(run);
}


void Pause() {

}


void Reset() {


}