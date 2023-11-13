PROG = main.exe
SRC = main.c safeinput.c adminmenu.c addcard.c cardaccess.c remotedoor.c listcard.c scancard.c fileio.c
CFLAGS = -g
LIBS = 
all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

clean: 
	rm -f $(PROG)

.PHONY: all clean