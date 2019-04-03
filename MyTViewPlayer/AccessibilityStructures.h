#pragma once

typedef struct AccessibilityFile {
	char* path;
	float playRate;
	int brightness;
	int noiseReduction;
} AccessibilityFile;

typedef struct UserConfiguration {
	char *accessibilityMode;
	float userPlayRate;
	int userbrightness;
	int usernoiseReduction;
} UserConfiguration;
#pragma once
#pragma once
