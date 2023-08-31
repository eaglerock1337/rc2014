# standard gcc (or similar compiler) files
OFILES=tmsim.o tm.o sim.o tdos.o player.o text.o
CFILES=tmsim.c tm.c sim.c tdos.c player.c text.c
# z88dk/sdcc compiler files for rc2014
ZFILES=tmsim.ihx tmsim_BSS.bin tmsim_CODE.bin
CFLAGS= -D DEBUG

build:  $(OFILES)
	gcc -o tmsim $(OFILES) -lm

debug:  $(OFILES)
	gcc -o tmsim $(CFLAGS) $(OFILES) -lm

rcbuild:
	docker run -v ${PWD}:/src/ -it z88dk/z88dk \
		zcc +rc2014 -subtype=cpm -SO3 --math32 --math16 \
		--vt100 -create-app -DRC -o tmsim $(CFILES)
	sudo chown $(USERNAME):$(USERNAME) tmsim*
	mv tmsim.bin tmsim.com

rcdebug:
	docker run -v ${PWD}:/src/ -it z88dk/z88dk \
		zcc +rc2014 -subtype=cpm -SO3 --math32 --math16 \
		--vt100 -create-app -DRC -DDEBUG -o tmsim $(CFILES)
	sudo chown $(USERNAME):$(USERNAME) tmsim*
	mv tmsim.bin tmsim.com

clean:
	rm $(OFILES)

rcclean:
	rm $(ZFILES)

fullclean:
	rm $(OFILES) $(ZFILES)
