OFILES=tmsim.o tm.o tdos.o player.o text.o
CFILES=tmsim.c tm.c tdos.c player.c text.c
HFILES=        tm.h tdos.h player.h text.h

tmsim:  $(OFILES)
	gcc -o tmsim $(OFILES) 

rcbuild: $(OFILES)
	docker run -v ${PWD}:/src/ -it z88dk/z88dk zcc +rc2014 -subtype=cpm -clib=new -SO3 -create-app -o tmsim -DRC $(CFILES)

clean:
	rm $(OFILES)

fullclean:
	rm $(OFILES) tmsim:

$(OFILES):  $(HFILES)

