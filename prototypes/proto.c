#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses/ncurses.h>
#include <time.h>

WINDOW * new_win(char *name, int height, int width, int start_y, int start_x);

void progress_bar(int val, int width, char *temp);
void update_tra_prog(WINDOW * win, int height, int width, int val);
void wait(int duration);
void print_dial(char *name, char *content);
void print_conv(WINDOW * win, int id, int ev_w, char* path);

int str_len(char *str);
int get_random(int max);

char* read_file(const char* path);

int main(int ac, char **av)
{
	/* initializes ncurses, set up the memory  */
	initscr();

	/* generate random seed */
	srand(time(NULL));

	/* get terminal size */
	int y_max;
	int x_max;
	getmaxyx(stdscr, y_max, x_max);

	/* set responsive window sizes */
	int tra_h = 10;
	int tra_w = x_max;
	int inv_h = y_max - tra_h;
	int inv_w = 35;
	int ev_h = y_max - tra_h;
	int ev_w = x_max - inv_w - 1;

	/* create window and store into windows pointers */
	WINDOW * win_tra = new_win(" Travel ", tra_h, tra_w, 0, 0);
	/*WINDOW * win_inv =*/ new_win(" Inventory ", inv_h, inv_w, tra_h, 0);
	WINDOW * win_env = new_win(" Events ", ev_h, ev_w, tra_h, inv_w + 1);

	/* trip pourcentage */
	int temp = 0;
	int len = 100;

	/* main loop */
	while(temp < len)
	{
		update_tra_prog(win_tra, tra_h, tra_w - 10, temp);
		wait(150000);
		
		if(temp == 25)
		{
			/*TEST EVENT*/
			print_conv(win_env, 0, ev_w, "./proto_dial/0.dial");
			getch();
			print_conv(win_env, 1, ev_w, "./proto_dial/1.dial");
			getch();

		}
		else if(temp == 26 || temp == 0)
		{
			wclear(win_env);
			box(win_env, 0, 0);
			wrefresh(win_env);
		}
		else if(temp == 99)
			print_conv(win_env, 2, ev_w, "./proto_dial/2.dial");
		
		temp++;
	}

	/* end */
	getchar();
	
	/* deallocates memory and ends ncurses  */
	endwin();

	return 0;
}

void print_conv(WINDOW * win, int id, int ev_w, char* path)
{
	char* raw = read_file(path);
	int fp = 0;
	int ch = 2;
	int line = 2;

	wclear(win);

	while(raw[fp] != '\0')
	{
		if(raw[fp] == '/' && raw[fp + 1] == '/')
		{
			while(raw[fp] != '\n')
				fp++;
			fp++;
		}
		else
		{

			if(raw[fp] == '\n' || raw[fp] == '%' || ch == ev_w - 1 || raw[fp] == '[' ||raw[fp - 1] == ']')
			{			
				line++;
				ch = 2;
			}

			if(raw[fp] == ']')
			{
				
			}

			mvwprintw(win, line, ch++, "%c", raw[fp]);
			fp++;
		}
	}
	
	box(win, 0, 0);
	wrefresh(win);
}

char* read_file(const char* path)
{
	FILE* fp;
	char* to_return;
	char temp;
	int i = 0;
	size_t len = 1;

	to_return = malloc(len * sizeof(char));

	fp = fopen(path, "r");

	if(fp)
	{
		do
		{
			to_return = realloc(to_return, ++len * sizeof(char));
			temp = fgetc(fp);
			to_return[i] = temp;
			i++;
		}
		while(temp != EOF);
		to_return = realloc(to_return, ++len * sizeof(char));
		to_return[i] = '\0';
	}

	return to_return;	
}

WINDOW * new_win(char *name, int height, int width, int start_y, int start_x)
{
	WINDOW * win = newwin(height, width, start_y, start_x);
	refresh();

	box(win, 0, 0);
	mvwprintw(win, 0, (width / 2) - str_len(name) / 2, name);
	wrefresh(win);

	return win;
}

void update_tra_prog(WINDOW * win, int height, int width, int val)
{
	char *temp;
	/*int center_h = height / 2 - 1;*/
	int center_w = width / 2 - ((width - 10) / 2);
	int prct = 764 * val / 100;

	/* allocate the bar array */
	temp = malloc((width + 3) * sizeof(int));

	/* make the bar */
	progress_bar(val, width, temp);
	
	mvwprintw(win, 3, 5, "San Fransisco");
	mvwprintw(win, 3, width - 4, "Flagstaff");
	mvwprintw(win, 4, width / 2, "Trip at %d%%", val);
	mvwprintw(win, 5, center_w, temp);
	mvwprintw(win, 6, 5, "%d miles", prct);
	mvwprintw(win, 6, width - 4, "764 miles");
	free(temp);
	wrefresh(win);
}

void progress_bar(int val, int width, char *temp)
{
	/* loops variables */
	int i = 0;

	while(i < width)
	{
		if(i == 0)
			temp[i] = '[';
		else if(i < val)
			temp[i] = '=';
		else if(i == width - 1)
			temp[i] = ']';
		else
			temp[i] = ' ';
		i++;
	}
}

int str_len(char *str)
{
	int i = 0;

	while(str[i])
		i++;

	return i;
}

/* wait in milliseconds */
void wait(int duration)
{
	fflush(stdout);
	usleep(duration);
}

int get_random(int max)
{
	return rand() % max;
}
