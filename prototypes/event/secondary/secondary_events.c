#include <ncurses.h>

#include "../../proto.h"


void after_event_clear(WINDOW * win_ev, WINDOW * win_me)
{
    wclear(win_me);
    box(win_me, 0, 0);
    mvwprintw(win_me, 0, 2, " Choice ");
 
    wclear(win_ev);
    box(win_ev, 0, 0);
    mvwprintw(win_ev, 0, 2, " Event ");

    wrefresh(win_me);
    wrefresh(win_ev);
}

void intro(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/", "/", "/", "/", "/");

        switch(current)
		{
			case 0:
                current= -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void outro(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 1;

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/", "/", "/", "/", "/");

        switch(current)
		{
			case 1:
                current= -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void secondary_event_1(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "Hitchhiker";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/1", char0, char1, char2, char3);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
				temp = choice(win_me, "I'm sorry but it is not on my way.", "Yeah, come in! I'll drive you there", "Start up the engine and leave.", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 2;
			break;
            case 2:
                current = -1;
                wait_input(win_me);
			break;
            case 3:
				temp = choice(win_me, "Alright, come in mate!", "Sorry, I have no time to waste.", "/", "/");
                if(temp == 0)
                    current = 5;
                if(temp == 1)
                    current = 2;
			break;
            case 4:
                char0 = "Robbert";
                current = -1;
                wait_input(win_me);
			break;
            case 5:
                current = 4;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void secondary_event_4(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "Dwarf";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/4", char0, char1, char2, char3);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
				temp = choice(win_me, "What the fuck?", "Trick!", "Treat!", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 5;
			break;
            case 2:
                current = -1;
                wait_input(win_me);
			break;
            case 3:
				temp = choice(win_me, "Kill him.", "Trick.", "Treat.", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 5;
			break;
            case 4:
                char0 = "Curtis";
                temp = choice(win_me, "Okay... We will find a candy shop if you want.", "Sorry, man. I don't have candy!", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 5;
			break;
            case 5:
                temp = choice(win_me, "Grab your gun and kill him.", "Go back to the bus and leave.", "Okay... again, trick!", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 10;
                if(temp == 2)
                    current = 7;
			break;
            case 6:
                current = -1;
                wait_input(win_me);
			break;
            case 7:
                temp = choice(win_me, "Hold on! I know an amazing candy shop in the next city!", "Grab your gun and kill him.", "/", "/");
                if(temp == 0)
                    current = 8;
                if(temp == 1)
                    current = 6;
			break;
            case 8:
                char0 = "Curtis";
                current= -1;
                /* GET CURTIS IN UR BUS */
                wait_input(win_me);
			break;
            case 9:
                char0 = "Curtis";
                current= -1;
                /* GET CURTIS IN UR BUS */
                wait_input(win_me);
			break;
            case 10:
                current= -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}