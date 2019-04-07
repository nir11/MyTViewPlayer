
#include <stdio.h>
#include "HandleDatabase.h"
#include <stdbool.h>
#include "AccessibilityStructures.h"


/*להשתמש בקוד מ:
https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
*/

/*
Following C code segment shows how to connect to an existing database "MyTViewDB.db".
If the database does not exist, then it will be created and finally a database object will be returned.
*/
sqlite3* connectToDB() {
	sqlite3 *db;			// database connection
	char *zErrMsg = 0;		// pointer to an error string
	int rc;					// return code

	/*
	 * open SQLite database file test.db
	 * use ":memory:" to use an in-memory database
	 */
	rc = sqlite3_open("MyTViewDB.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	//sqlite3_close(db);
	return db;
}

void insertANewyVideoFile(sqlite3 *db, AccessibilityVideoFile newFile) {
	
	char *zErrMsg = 0;
	int rc;
	char *sql;

	/* Open database */
	rc = sqlite3_open("MyTViewDB.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}


	/* Create SQL statement */
	/*צריכים למצוא דרך לשרשר צ'אר ואינט בשורה התחתונה*/
	/*sql = "INSERT INTO AccessibilityVideoFiles (path,play_rate,brightness,noise_reduction) "  \
		"VALUES (newFile.path, newFile.playRate, newFile.brightness, newFile.noiseReduction);";*/

	/* Create SQL statement */
	sql = "INSERT INTO AccessibilityVideoFiles (path,play_rate,brightness,noise_reduction) "  \
		"VALUES ('C:\\MyTView\\videos\\samplevide1.3gp', 1.3, 85, 90);";


	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callbackForInsert, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

static int callbackForInsert(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void selectVideoFileFromDB(sqlite3 *db) {

	AccessibilityVideoFile currFile;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "Callback function called";

	/* Open database */
	rc = sqlite3_open("MyTViewDB.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "SELECT * from AccessibilityVideoFiles LIMIT 1";


	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callbackForSelect, (void*)data, &zErrMsg);
	
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
		/*currFile.path = malloc(sizeof(data[1]));
		strcpy(currFile.path, data[1]);
		currFile.playRate = data[2];
		currFile.brightness = data[3];
		currFile.noiseReduction = data[4];
		printf("Path: %s\nPlay Rate: %f\nBrightness: %d\nnNoise Reduction: %d", currFile.path, currFile.playRate, currFile.brightness, currFile.noiseReduction);*/

	}
	sqlite3_close(db);
}

static int callbackForSelect(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}




bool checkIfVideoAccessibilityIsOn(){}

bool checkIfExist(){}

void updateUserConfiguration(UserConfiguration userConfiguration) {}

void setAccessibilityMode(char *accessibilityMode) {}

void setUserPlayRate(float userPlayRate) {}

void setUserBrightness(int userBrightness) {}

void setUserNoiseReduction(int userNoiseReduction) {}

void setUserConfigurationAsDefault() {}

void resetPlaylist() {}

UserConfiguration getUserConfiguration() {}

AccessibilityVideoFile getNextFile() {}



