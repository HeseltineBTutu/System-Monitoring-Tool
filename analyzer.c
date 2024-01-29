#include "analyzer.h"

/**
 * read_data - Reads system data from the file into an array of SystemData structures.
 *
 * @data: Array of SystemData structures to store the read data.
 *
 * Return: The number of records read, or -1 in case of an error
 */
int read_data(struct SystemData data[])
{
	int count;
	
	FILE *file = fopen("system_data.txt", "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return (-1);
	}

	count = 0;
	while (fscanf(file, "Timestamp: %[^\n]\nCPU Usage: %lf\nMemory Usage: %d MB\nDisk Space: %lf\n",
              data[count].timestamp, &data[count].cpuUsage, &data[count].memoryUsageMB,
              &data[count].diskSpaceUsage) == 4)
	{
		count++;
		if (count >= MAX_RECORDS)
		{
			break;
		}
	}

	fclose(file);
	return (count);
}

/**
 * analyze_data - Analyzes system data and triggers alerts if necessary.
 *
 * @data: Array of SystemData structures containing collected data.
 * @record_count: Number of records in the data array.
 */
void analyze_data(struct SystemData data[], int record_count)
{
	int i;
	for (i = 0; i < record_count; i++)
	{
		/** Trigger an alert if CPU usage is above the threshold*/
		if (data[i].cpuUsage >= ALERT_THRESHOLD)
		{
			struct Alert alert;
			strcpy(alert.timestamp, data[i].timestamp);
			snprintf(alert.message, sizeof(alert.message), "CPU alert: Usage is above the threshold (%.2lf%%)", data[i].cpuUsage);
			printf("Alert: %s\n", alert.message);
		}
	}

}
