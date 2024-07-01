#include "buffers.h"
#include <termios.h>
#include <unistd.h>

static struct termios stored_settings;

void set_keypress(void);
void reset_keypress(void);
int wait_keypress();
void set_pause_in_microseconds(int microseconds);
