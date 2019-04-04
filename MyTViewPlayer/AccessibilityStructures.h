#pragma once

typedef struct AccessibilityVideoFile {
	char* path;
	float playRate;
	int brightness;
	int noiseReduction;
} AccessibilityVideoFile;

typedef struct UserConfiguration {
	char *accessibilityMode;
	float userPlayRate;
	int userBrightness;
	int userNoiseReduction;
} UserConfiguration;

