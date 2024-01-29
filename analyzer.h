#ifndef ANALYZER_H
#define ANALYZER_H

/* Constants*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define ALERT_THRESHOLD 90

/* Data Structures */
struct SystemData
{
	char timestamp[50];
	double cpuUsage;
	int memoryUsageMB;
	double diskSpaceUsage;
};

struct Alert
{
	char timestamp[50];
	char message[100];
};

/* Function Declarations*/
int read_data(struct SystemData data[]);
void analyze_data(struct SystemData data[], int record_count);


#endif /* ANALYZER_H */
