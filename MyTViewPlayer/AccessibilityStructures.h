#pragma once

typedef struct AccessibilityVideoFile {
	char* path;
	double playRate;
	double brightness;
	double noiseReduction;
} AccessibilityVideoFile;

typedef struct UserConfiguration {
	char *accessibilityMode;
	double userPlayRate;
	double userBrightness;
	double userNoiseReduction;
} UserConfiguration;

