#include <stdio.h>
#include <unistd.h>



int print_bar(int val)
{
    for(int i=0;i<=30;i++) {
        if (i <= val) {
            printf("♥");
        } else {
            printf(" ");
        }
    } 
}

void get_person_life(char *name, int to_use)
{
    	int i = 0;
	
	printf("\n");
	printf("%s : \n", name);
	while (i <= to_use)
	{
		if (i != 0) printf("\r[");
		else if (i == 0) printf("[");
		print_bar(i);
    		printf("]");
		fflush(stdout);
		usleep(50000);
		i++;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	char names[2][7] = {
		"Lucas",
		"Cosmo",
	};

	int a = 0;
	int value = 15;
	
	while (a < 2)
	{
		get_person_life(names[a], value);
		value = 6;
		a++;
	}

	return 0;
}
