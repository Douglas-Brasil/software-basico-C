#include <stdio.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	time_t t;
	struct tm *data;
	
	t = time (NULL);
	data = localtime(&t);
	
	printf("%d horas \n%d minutos \n%d segundos", data -> tm_hour, data -> tm_min, data -> tm_sec);
	return 0;
	
}
