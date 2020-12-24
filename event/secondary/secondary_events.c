#include <ncurses/ncurses.h>

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

void secondary_event_1(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "Hitchhiker";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/1", char0, char1, char2, char3, char4, char5);

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
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/4", char0, char1, char2, char3, char4, char5);

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

void secondary_event_2(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/2", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Drive faster. ", "Break suddenly.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                current = -1;
                wait_input(win_me);
			break;
            case 2:
                current = -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void secondary_event_3(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "Trucker";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/3", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1){
                    current = -1;
                }
			break;
            case 1:
				temp = choice(win_me, "Check the body.", "Open the truck.", "/", "/");
                if(temp == 0)
                    current = 2;
                if(temp == 1)
                    current = 3;
			break;
            case 2:
                temp = choice(win_me, "Throw the keys of your bus.", "Stay still and voiceless.", "/", "/");
                if(temp == 0)
                    current = 14;
                if(temp == 1)
                    current = 5;
			break;
            case 3:
				temp = choice(win_me, "Check the body.", "Go back to the bus and keep driving.", "/", "/");
                if(temp == 0)
                    current = 2;
                if(temp == 1){
                    current = -1;
                    wait_input(win_me);
                }
			break;
            case 4:
                temp = choice(win_me, "Kill him.", "Search in the truck.", "/", "/");
                if(temp == 0)
                    current = 13;
                if(temp == 1)
                    current = 12;
			break;
            case 5:
                temp = choice(win_me, "If you had bullets, you would have killed me already!", "Punch the trucker.", "/", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 7;
			break;
            case 6:
                current = -1;
                wait_input(win_me);
			break;
            case 7:
                temp = choice(win_me, "Throw a kick in his nuts.", "Push him.", "/", "/");
                if(temp == 0)
                    current = 8;
                if(temp == 1)
                    current = 9;
			break;
            case 8:
                temp = choice(win_me, "Threaten him.", "Leave him.", "/", "/");
                if(temp == 0)
                    current = 10;
                if(temp == 1)
                    current = 11;
			break;
            case 9:
                temp = choice(win_me, "Threaten him.", "Leave him.", "/", "/");
                if(temp == 0){
                    current= -1;
                    wait_input(win_me);
                }
                if(temp == 1)
                    current = 12;
			break;
            case 10:
                temp = choice(win_me, "Now dude, YOU give me your keys!", "Finish him! FATALITY!", "/", "/");
                if(temp == 0)
                    current= 4;
                if(temp == 1)
                    current = 15;
			break;
            case 11:
                temp = choice(win_me, "Leave.", "Kill him.", "/", "/");
                if(temp == 0) {
                    current= -1;
                    wait_input(win_me);
                }
                if(temp == 1)
                    current = 13;
			break;
            case 12:
                /* - 1 Food - 1 Medical Kit  */
                current= -1;
                wait_input(win_me);
			break;
            case 13:
                temp = choice(win_me, "Leave.", "Search in the truck.", "/", "/");
                if(temp == 0){
                    current= -1;
                    wait_input(win_me);
                }
                if(temp == 1)
                    current = 12;
			break;
            case 14:
                temp = choice(win_me, "Grab your weapon and kill him.", "/", "/", "/");
                if(temp == 0)
                    current = 13;
			break;
            case 15:
                temp = choice(win_me, "Leave.", "Search in the truck.", "/", "/");
                if(temp == 0){
                    current = -1;
                    wait_input(win_me);
                }
                if(temp == 1)
                    current = 12;
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void secondary_event_5(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "The bad guy";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/5", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Stop the bus.", "Keep driving.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                temp = choice(win_me, "Stay in the bus.", "Leave the bus.", "/", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 7;
			break;
            case 2:
                current = -1;
                wait_input(win_me);
			break;
            case 3:
                temp = choice(win_me, "Stay in the bus.", "Leave the bus.", "/", "/");
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 7;
			break;
            case 4:
                temp = choice(win_me, "Stay in the bus.", "Leave the bus.", "Start the bus and drive on one of them.", "/");
                if(temp == 0)
                    current = 5;
                if(temp == 1)
                    current = 7;
                if(temp == 2)
                    current = 6;
			break;
            case 5:
                current = -1;
                wait_input(win_me);
			break;
            case 6:
                current = -1;
                wait_input(win_me);
			break;
            case 7:
                temp = choice(win_me, "Be obedient", "Refuse", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 8;
			break;
            case 8:
                temp = choice(win_me, "Give up", "Refuse one more / last(?) time", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 10;
			break;
            case 9:
                current = -1;
                wait_input(win_me);
			break;
            case 10:
                current = -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void secondary_event_6(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/6", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Go back to sleep.", "Walk a little.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                current = -1;
                wait_input(win_me);
			break;
            case 2:
                temp = choice(win_me, "Return to the bus.", "Go take a look.", "/", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 4;
			break;
            case 3:
                current = -1;
                wait_input(win_me);
			break;
            case 4:
                current = -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void secondary_event_7(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "a random passenger";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/7", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Stop the bus.", "Keep driving.", "/", "/");
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 1;
			break;
            case 1:
                /* if there is someone in the bus */
                current = -1;
                wait_input(win_me);
			break;
            case 2:
                current = -1;
                wait_input(win_me);
			break;
            case 3:
                current = -1;
                wait_input(win_me);
			break;
            case 4:
                current = -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}

void intro(WINDOW * win_ev, WINDOW * win_me, int ev_w)
{
    int current = 0;
    int temp;
    char* char0 = "Rafe";
    char* char1 = "Evelynn";
    char* char2 = "The patient";
    char* char3 = "The security guard";
    char* char4 = "Young man";
    char* char5 = "Assaillant";

    while(current >= 0)
    {
        print_conv(win_ev, current, ev_w, "event/secondary/999", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = choice(win_me, "Answer the call.", "/", "/", "/");
                if(temp == 0)
                    current = 1;
			break;
            case 1:
				temp = choice(win_me, "Leave your apartment.", "Check one last time for your stuff.", "/", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 2;
			break;
            case 2:
                temp = choice(win_me, "Leave your apartment.", "/", "/", "/");
                if(temp == 0)
                    current = 3;
			break;
            case 3:
                current = 4;
                wait_input(win_me);
			break;
            case 4:
                temp = choice(win_me, "Turn around.", "Honk.", "/", "/");
                if(temp == 0)
                    current = 5;
                if(temp == 1)
                    current = 6;
			break;
            case 5:
                current = 7;
                wait_input(win_me);
			break;
            case 6:
                current = 5;
                wait_input(win_me);
			break;
            case 7:
                temp = choice(win_me, "Try to convince your brother to drop his weapon.", "Try to convince the guard that your brother doesn't mean to hurt anybody.", "/", "/");
                if(temp == 0)
                    current = 8;
                if(temp == 1)
                    current = 9;
			break;
            case 8:
                temp = choice(win_me, "Leave the hospital by the main entrance door.", "Find another exit.", "/", "/");
                if(temp == 0)
                    current = 10;
                if(temp == 1)
                    current = 11;
			break;
            case 9:
                temp = choice(win_me, "Listen to me. He's dead and we can't stay here.", "Shut up! Is there a safe exit door?", "Listen, Evelynn. Right now, I am completely lost, just like you. But we need to get out of here.", "/");
                if(temp == 0)
                    current = 17;
                if(temp == 1)
                    current = 19;
                if(temp == 2)
                    current = 20;
			break;
            case 10:
                temp = choice(win_me, "Leave.", "Stay to help your brother.", "/", "/");
                if(temp == 0)
                    current = 14;
                if(temp == 1)
                    current = 12;
			break;
            case 11:
                temp = choice(win_me, "Stay with your brother to help him.", "Leave him.", "/", "/");
                if(temp == 0)
                    current = 12;
                if(temp == 1)
                    current = 13;
			break;
            case 12:
                current = 14;
                wait_input(win_me);
			break;
            case 13:
                current = 14;
                wait_input(win_me);
			break;
            case 14:
                current = 15;
                wait_input(win_me);
			break;
            case 15:
                current = 16;
                wait_input(win_me);
			break;
            case 16:
                temp = choice(win_me, "Drive faster.", "Stop at the light.", "/", "/");
                if(temp == 0)
                    current = 22;
                if(temp == 1)
                    current = 23;
			break;
            case 17:
                current = 18;
                wait_input(win_me);
			break;
            case 18:
                current = 15;
                wait_input(win_me);
			break;
            case 19:
                current = 21;
                wait_input(win_me);
			break;
            case 20:
                current = 21;
                wait_input(win_me);
			break;
            case 21:
                current = 15;
                wait_input(win_me);
			break;
            case 22:
                temp = choice(win_me, "Stop the bus.", "Keep driving.", "/", "/");
                if(temp == 0)
                    current = 25;
                if(temp == 1)
                    current = 26;
			break;
            case 23:
                current = 24;
                wait_input(win_me);
			break;
            case 24:
                temp = choice(win_me, "Open the door.", "Drive away.", "/", "/");
                if(temp == 0)
                    current = 27;
                if(temp == 1)
                    current = 28;
			break;
            case 25:
                current = 24;
                wait_input(win_me);
			break;
            case 26:
                current = 24;
                wait_input(win_me);
			break;
            case 27:
                char4 = "Tim";
                current = 29;
                wait_input(win_me);
			break;
            case 28:
                current = 29;
                wait_input(win_me);
			break;
            case 29:
                current = -1;
                wait_input(win_me);
			break;
        }

        after_event_clear(win_ev, win_me);
    }
}