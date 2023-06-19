#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define TS_BUF_LENGTH 30

//define my options
#define LOG_TIME 0x01 //0b00000001
#define LOG_DATE 0x02 //0b00000010
#define LOG_USER 0x04 //0b00000100
#define LOG_COUNT 0x08//0b00001000
#define LOG_ALL 0xFF  //0b11111111
#define LOG_FULLTIME 0x03 //0b00000011

char* getlogin(){
	return "hello C developer -> Volodymyr Malynovskyi";
}

void logmsg(FILE* fp, char* message, uint8_t options){
	static uint64_t logcount = 0;
	
	time_t time_val;
	char timestamp[TS_BUF_LENGTH];
	char datestamp[TS_BUF_LENGTH];
	struct tm* tm_info;

	time_val = time(NULL);
	tm_info = localtime(&time_val);

	strftime(datestamp, TS_BUF_LENGTH, "%F (%a)", tm_info);
	strftime(timestamp, TS_BUF_LENGTH, "%H:%M:%S", tm_info);
	
	if(options & LOG_COUNT){
		fprintf(fp, "%lli, ", ++logcount);
	}
	if(options & LOG_DATE){
		fprintf(fp, "%s, ", datestamp);
	}
	if(options & LOG_TIME){
		fprintf(fp, "%s, ", timestamp);
	}
	if(options & LOG_USER){
		fprintf(fp, "%s, ", getlogin());
	}
	fprintf(fp, "%s\n", message);
}

int main(){
	logmsg(stdout, "Things are running fine.", 0);
	logmsg(stdout, "Hmmm...maybe not. What's this?", LOG_USER |\
				LOG_TIME | LOG_DATE);
	logmsg(stdout, "The wheels are coming off!", LOG_USER | \
				LOG_TIME | LOG_DATE | LOG_COUNT);
	logmsg(stdout, "AAAAARGH.", LOG_COUNT);
	logmsg(stdout, "PRIVEYT!", LOG_ALL);
	logmsg(stdout, "DATE TIME NOW", LOG_FULLTIME);
}







