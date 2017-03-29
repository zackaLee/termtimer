/* Termtime.c is a c program that takes commandline arguments in the form of minutes 
and sets the countdown timer for that amount in minutes.
When the timer is up it askes you to start again
TO DO - change the time to update to digital timer after 60 seconds has been counted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int arg = argc;
	int in_time, min_time = 0;
	time_t start, end;
	double elapsed;
	char command[50];


	//input time from commandline and exit if no time is input
	if(arg == 2)
		for (int i = 0; i < arg; i++)
		{
			if(argv[1] != 0)
			in_time = atoi(argv[1]);
		}
	else if(arg < 2)
	{
		printf("Termtime needs some time!\n");
		return 1;
	}

	//take in_time and convert to minutes
	min_time = in_time * 60;		//to the minute
	if(time(&start))
	{
		printf("Timer is running\n");
		do{
			time(&end);

			elapsed = difftime(end, start);

			//output the time in seconds and continually update
			printf("Time elapsed: %3.f\r", elapsed);
		}while(elapsed < min_time);
	}
	
	//Play sound on timer end
	if(elapsed == min_time)
	{	
		//play recorded alarm sound
		printf("\a");
		strcpy(command, "aplay pew.wav");
		system(command);
		return 0;
	}
	

	
	printf("\n");

	return 0;
}
