#include <stdio.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	time_t t;
	struct tm *data;
	t = time (NULL);
	data = localtime(&t);
	printf("Data ........: %d/%d/%d\n", data -> tm_mday, data -> tm_mon + 1, data -> tm_year + 1900);
	return 0;
	
}

