#include<stdio.h>
//function for first day of year
int getFDay(int year){
	int day = (year*365 + ((year-1) / 4 ) - ((year-1) / 100 ) + ((year-1) / 400)) % 7;
	return day;
}
int main(){
	char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	int dayInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int weekday = 0;
	int year;
	// input year
	printf("Please enter year : ");
	scanf("%d",&year);
	printf("\n\n******************* Calendar for %d *******************\n\n",year);
	//checking leap Year
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		dayInMonth[1] = 29 ;
	}
	//set first day
	weekday = getFDay(year);
	//loop for printing name 
	for(int i = 0; i<12 ; i++){
			printf("\n\n------------------------ %s ------------------------\n",months[i]);
			printf("\n    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n\n");
			
			
			int totalDays = dayInMonth[i];
			
			// loop for printing space
			for(int scount = 1 ; scount <= weekday ; scount++){
				printf("       ");
			}
			//loop for printing day ....
			for(int j = 1 ; j <= totalDays ; j++ ){
				printf("%7d",j);
				weekday++;
				
				if(weekday > 6){
					weekday = 0;
					printf("\n");
				}
			}
		}
	printf("\n\n");
	return 0;
}
