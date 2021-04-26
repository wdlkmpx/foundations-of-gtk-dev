CC = cc

CFLAGS_S = -Wall -g -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
CFLAGS_D = -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_DEPRECATED -DGTK_DISABLE_SINGLE_INCLUDES
CFLAGS_2 = $(CFLAGS_S) `pkg-config --cflags --libs gtk+-2.0` $(CFLAGS_D)
CFLAGS_3 = $(CFLAGS_S) `pkg-config --cflags --libs gtk+-3.0`

CFLAGS = $(CFLAGS_2)


all: 
	$(MAKE) ipaddresstest marqueetest

marqueetest: mymarquee.c marqueetest.c mymarquee.h
	$(CC) $(CFLAGS) $@.c mymarquee.c -o $@

ipaddresstest: myipaddress.c ipaddresstest.c myipaddress.h
	$(CC) -lm $(CFLAGS) $@.c myipaddress.c -o $@

myiface:
	make all

clean:
	rm -f marqueetest ipaddresstest
