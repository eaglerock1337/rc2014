# standard gcc (or similar compiler) files
OFILES=tmsim.o tm.o tdos.o player.o text.o
CFILES=tmsim.c tm.c tdos.c player.c text.c
HFILES=        tm.h tdos.h player.h text.h
# z88dk/sdcc compiler files for rc2014
ZFILES=tmsim.ihx tmsim_BSS.bin tmsim_CODE.bin

build:  $(OFILES)
	gcc -o tmsim $(OFILES) 

rcbuild: $(OFILES)
	docker run -v ${PWD}:/src/ -it z88dk/z88dk zcc +rc2014 -subtype=cpm -clib=new -SO3 -create-app -DRC -o tmsim $(CFILES)
	sudo chown $(USERNAME):$(USERNAME) tmsim*
	mv tmsim.bin tmsim.com

clean:
	rm $(OFILES)

rcclean:
	rm $(ZFILES)

fullclean:
	rm $(OFILES) $(ZFILES) tmsim tmsim.com

$(OFILES):  $(HFILES)

