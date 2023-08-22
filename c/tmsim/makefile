OFILES=tmsim.o tm.o tdos.o player.o text.o
HFILES=        tm.h tdos.h player.h text.h

tmsim:  $(OFILES)
	gcc -o tmsim $(OFILES) 

clean:
	rm $(OFILES)
        
$(OFILES):  $(HFILES)

