EXES = directories files files2 iochannels memprofile timeouts timers
CC = cc

CFLAGS_S = -Wall -g -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
CFLAGS_D = -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_DEPRECATED -DGTK_DISABLE_SINGLE_INCLUDES
CFLAGS_2 = $(CFLAGS_S) `pkg-config --cflags --libs gtk+-2.0` $(CFLAGS_D)
CFLAGS_3 = $(CFLAGS_S) `pkg-config --cflags --libs gtk+-3.0`

CFLAGS = $(CFLAGS_2)

GMODULE = `pkg-config --cflags --libs gmodule-2.0`

all: 
	$(MAKE) $(EXES);
	$(MAKE) modules

modules: modules.c modules-plugin.c
	$(CC) -shared modules-plugin.c -o plugin.so $(CFLAGS) 
	sudo mv plugin.so /usr/lib
	$(CC) $(GMODULE) $(CFLAGS) $@.c -o $@

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(EXES) modules
