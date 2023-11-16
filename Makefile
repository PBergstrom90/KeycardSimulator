PROG = main.exe
SRC = main.c fileio.c listcard.c adminmenu.c safeinput.c addcard.c cardaccess.c remotedoor.c scancard.c
CFLAGS = -g -Wall -Wextra -Wundef -pedantic -Werror
LIBS = 
all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

clean: 
	rm -f $(PROG)

.PHONY: all clean