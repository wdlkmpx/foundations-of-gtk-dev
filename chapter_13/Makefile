CC = cc

CFLAGS_S = -Wall -g -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
CFLAGS_D = -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_DEPRECATED -DGTK_DISABLE_SINGLE_INCLUDES
CFLAGS_2 = $(CFLAGS_S) `pkg-config --cflags --libs gtk+-2.0 libglade-2.0` $(CFLAGS_D)
CFLAGS_3 = $(CFLAGS_S) `pkg-config --cflags --libs gtk+-3.0`

CFLAGS = -export-dynamic -lm $(CFLAGS_2)

all: 
	$(MAKE) browser calculator ping calendar hangman

browser: browser.c navigation.c
	$(CC) $(CFLAGS) $@.c navigation.c -o $@

calculator: calculator.c
	$(CC) $(CFLAGS) $@.c -o $@

ping: ping.c
	$(CC) $(CFLAGS) $@.c -o $@

calendar: calendar.c
	$(CC) $(CFLAGS) $@.c -o $@

hangman: hangman.c
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -f browser calculator ping calendar hangman
