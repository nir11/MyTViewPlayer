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

typedef int(*sqlite3_callback)(
	void*,    /* Data provided in the 4th argument of sqlite3_exec() */
	int,      /* The number of columns in row */
	char**,   /* An array of strings representing fields in the row */
	char**    /* An array of strings representing column names */
	);