OFILES=tmsim.o tm.o tdos.o player.o text.o
CFILES=tmsim.c tm.c tdos.c player.c text.c
HFILES=        tm.h tdos.h player.h text.h
ZFILES=tmsim_BSS.bin tmsim_CODE.bin tmsim.ihx tmsim.bin

tmsim:  $(OFILES)
	gcc -o tmsim $(OFILES) 

rcbuild: $(OFILES)
	docker run -v ${PWD}:/src/ -it z88dk/z88dk zcc +rc2014 -subtype=cpm -clib=new -SO3 -create-app -DRC -o tmsim $(CFILES)
	mv tmsim.bin tmsim.com

clean:
	rm $(OFILES)

rcclean:
	rm $(ZFILES)

fullclean:
	rm $(OFILES) $(ZFILES) tmsim tmsim.com

$(OFILES):  $(HFILES)

