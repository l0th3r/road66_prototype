#ifndef PROTO
#define PROTO

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

#endif