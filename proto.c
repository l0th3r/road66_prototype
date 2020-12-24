#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <ncurses/ncurses.h>

#include "event/secondary/secondary_events.h"

WINDOW * new_win(char *name, int height, int width, int start_y, int start_x);

void update_tra_prog(WINDOW * win, int height, int val);
void wait(long msec);
void print_dial(char *name, char *content);
void print_conv(WINDOW * win, int id, int ev_w, char* path, char* char0, char* char1, char* char2, char* char3, char* char4, char* char5);
void str_clear(char *str);
void wait_input(WINDOW * win_men);

int str_len(char *str);
int get_random(int max);
int choice(WINDOW* win, char* choice1, char* choice2, char* choice3, char* choice4);

char progress_bar(int val);
char* read_file(const char* path);
char** init_choices(char* zero, char* one, char* two, char* three);

int main(int ac, char **av)
{
	/* initializes ncurses, set up the memory  */
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	/* generate random seed */
	srand(time(NULL));

	/* get terminal size */
	int y_max;
	int x_max;
	getmaxyx(stdscr, y_max, x_max);

	/* set responsive window sizes */
	int tra_h = 10;
	int tra_w = 35;
	int inv_h = y_max - tra_h;
	int inv_w = tra_w;
	int me_h = 10;
	int me_w = x_max - inv_w - 1;
	int ev_h = y_max - me_h;
	int ev_w = x_max - inv_w - 1;

	/* create window and store into windows pointers */
	WINDOW * win_tra = new_win(" Travel ", tra_h, tra_w, 0, 0);
	/*WINDOW * win_inv =*/ new_win(" Inventory ", inv_h, inv_w, tra_h, 0);
	WINDOW * win_env = new_win(" Events ", ev_h, ev_w, 0, tra_w + 1);
	WINDOW * win_men = new_win(" Choice ", me_h, me_w, ev_h, inv_w + 1);

	keypad(win_men, true);

	/* trip pourcentage */
	int temp = 0;
	int len = 100;

	/* main loop */
	while(temp < len)
	{
		update_tra_prog(win_tra, tra_h, temp);
		wait(150000);

		if(temp == 0)
		{
			intro(win_env, win_men, ev_w);
		}
		else if(temp == 20)
			secondary_event_3(win_env, win_men, ev_w);
		else if(temp == 33)
			secondary_event_2(win_env, win_men, ev_w);
		else if(temp == 40)
			secondary_event_1(win_env, win_men, ev_w);
		else if(temp == 50)
			secondary_event_5(win_env, win_men, ev_w);
		else if(temp == 72)
			secondary_event_4(win_env, win_men, ev_w);
		else if(temp == 80)
			secondary_event_6(win_env, win_men, ev_w);
		temp++;
	}
	
	/* deallocates memory and ends ncurses  */
	endwin();

	return 0;
}

int choice(WINDOW* win, char* choice1, char* choice2, char* choice3, char* choice4)
{
	/*int to_return = -1;*/
	int is_good = 0;
	int choice;
	int selected = 0;
	int i = 0;

	int end = 4;

	char* arr[4];

	arr[0] = choice1;
	arr[1] = choice2;
	arr[2] = choice3;
	arr[3] = choice4;

	while(is_good == 0)
	{
		i = 0;
		while(i < end)
		{
			if(i == selected)
				wattron(win, A_REVERSE);

			mvwprintw(win, i + 2, 2, "%d: %s", i + 1, arr[i]);

			if(arr[i + 1][0] == '/')
				end = i + 1;

			wattroff(win, A_REVERSE);
			mvwprintw(win, 6, 2, "^ and v arrows to navigate.");
			mvwprintw(win, 7, 2, "enter key to select.");

			wrefresh(win);
			i++;	
		}
		choice = wgetch(win);

		switch(choice)
		{
			case 259:
				if(selected > 0)
					selected--;
				else
					selected = end - 1;
				break;
			case 258:
				if(selected < end - 1)
					selected++;
				else
					selected = 0;
				break;
			default:
				break;
		}
		if(choice == 10)
			is_good = 1;
	}

	wclear(win);
	box(win, 0, 0);
	mvwprintw(win, 0, 2, " Choice ");
	wrefresh(win);

	return selected;
}

void print_conv(WINDOW * win, int id, int ev_w, char* path, char* char0, char* char1, char* char2, char* char3, char* char4, char* char5)
{
	char* raw;
	char* file_path = malloc((str_len(path) + 10) * sizeof(char));
	char* temp = malloc(10 * sizeof(char));
	char* main = "Maxence";
	char* radio = "radio";

	int fp = 0;
	int ch = 2;
	int line = 0;

	/* loop variables */
	int i;
	int j;

	/* clear box */
	wclear(win);
	start_color();
	
	init_color(COLOR_MAGENTA, 249, 249, 249);

	/* create path */
	sprintf(file_path, "%s/%d.dial%c", path, id, '\0');

	/* charge content */
	raw = read_file(file_path);

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
			/* conditions to jump a line */
			if(raw[fp - 1] == '\n' || ch == ev_w - 2
			|| raw[fp - 1] == ']' || raw[fp] == '[')
			{			
				line++;
				ch = 2;
			}

			if(raw[fp] == '[' || raw[fp] == '<')
			{
				if(raw[fp] == '[')
					line++;

				i = 0;
				j = fp + 1;

				while(raw[j] != ']' && raw[j] != '>')
					temp[i++] = raw[j++];

				temp[i] = '\0';


				if(raw[fp] == '[' && strcmp(temp, "narr") != 0)
					mvwprintw(win, line, ch++, "[");

				if(strcmp(temp, "narr") == 0)
					fp = j + 1;
				else if(strcmp(temp, "main") == 0)
				{
					init_pair(1, COLOR_CYAN, COLOR_BLACK);
					wattron(win, COLOR_PAIR(1));

					i = 0;
					while(main[i])
						mvwprintw(win, line, ch++, "%c", main[i++]);
					fp = j;
				}
				else if(strcmp(temp, "radio") == 0)
				{
					init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
					wattron(win, COLOR_PAIR(2));

					i = 0;
					while(radio[i])
						mvwprintw(win, line, ch++, "%c", radio[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char0") == 0)
				{
					i = 0;
					while(char0[i])
						mvwprintw(win, line, ch++, "%c", char0[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char1") == 0)
				{
					i = 0;
					while(char1[i])
						mvwprintw(win, line, ch++, "%c", char1[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char2") == 0)
				{
					i = 0;
					while(char2[i])
						mvwprintw(win, line, ch++, "%c", char2[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char3") == 0)
				{
					i = 0;
					while(char3[i])
						mvwprintw(win, line, ch++, "%c", char3[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char4") == 0)
				{
					i = 0;
					while(char4[i])
						mvwprintw(win, line, ch++, "%c", char4[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char5") == 0)
				{
					i = 0;
					while(char5[i])
						mvwprintw(win, line, ch++, "%c", char5[i++]);
					fp = j;
				}
				str_clear(temp);
			}
	
			if(raw[fp] == ']' || raw[fp] == '>')
			{
				wattroff(win, COLOR_PAIR(1));
				wattroff(win, COLOR_PAIR(3));
			}

			if(raw[fp] == '>' || raw[fp] == '\r')
				fp++;

			mvwprintw(win, line, ch++, "%c", raw[fp++]);

			box(win, 0, 0);
			mvwprintw(win, 0, 2, " Event ");
			wrefresh(win);
			wait(25000);
		}
	}	

	free(raw);
	free(file_path);
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

	fclose(fp);

	return to_return;	
}

WINDOW * new_win(char *name, int height, int width, int start_y, int start_x)
{
	WINDOW * win = newwin(height, width, start_y, start_x);
	refresh();

	box(win, 0, 0);
	mvwprintw(win, 0, 2, name);
	wrefresh(win);

	return win;
}

void update_tra_prog(WINDOW * win, int height, int val)
{
	char temp;
	/*int center_h = height / 2 - 1;*/
	int prct = 764 * val / 100;

	char* city_start = "San Fransisco";
	char* city_arrival = "Flagstaff";
	int distance = 764;

	/* make the bar */
	temp = progress_bar(val);

	mvwprintw(win, 2, 4, "%s to %s", city_start, city_arrival);
	mvwprintw(win, 3, 7, "=> %d miles remaining.", distance - prct - 8);

    mvwprintw(win, 5, (val % 5) + 2, "      _____________      ");
    mvwprintw(win, 6, (val % 5) + 2, "     | [][][][][]|_\\_       ");
    mvwprintw(win, 7, (val % 5) + 2, "     |               )      ");
	mvwprintw(win, 8, (val % 5) + 2, " ~~ =--(%c)------(%c)--=      ", temp, temp);

	wrefresh(win);
}

char progress_bar(int val)
{
	char to_return;

	/* loops variables */
	if(val % 2 == 0)
	{
		to_return = 'O';
	}
	else
	{
		to_return = '0';
	}

	return to_return;
}

int str_len(char *str)
{
	int i = 0;

	while(str[i])
		i++;

	return i;
}

void str_clear(char *str)
{
	int i = 0;

	while(i < str_len(str))
		str[i++] = '\0';
}

/* wait in milliseconds */
void wait(long msec)
{
	fflush(stdout);
	usleep(msec);
}

void wait_input(WINDOW * win)
{
	choice(win, "Continue", "/", "/", "/");
}

int get_random(int max)
{
	return rand() % max;
}
