# auto generated - do not edit

default: all

all:\
	add_gen addsc_gen div_gen divsc_gen dotprod_gen frand.a mag_gen \
	mult_gen multsc_gen nega_gen norm_gen sub_gen subsc_gen xprod_gen 

add_gen:\
	ld add_gen.ld add_gen.o frand.a 
	./ld add_gen add_gen.o frand.a 
add_gen.o:\
	cc add_gen.c frand.h 
	./cc add_gen.c
addsc_gen:\
	ld addsc_gen.ld addsc_gen.o frand.a 
	./ld addsc_gen addsc_gen.o frand.a 
addsc_gen.o:\
	cc addsc_gen.c frand.h 
	./cc addsc_gen.c
cc: conf-cc conf-cctype conf-cflags 
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
div_gen:\
	ld div_gen.ld div_gen.o frand.a 
	./ld div_gen div_gen.o frand.a 
div_gen.o:\
	cc div_gen.c frand.h 
	./cc div_gen.c
divsc_gen:\
	ld divsc_gen.ld divsc_gen.o frand.a 
	./ld divsc_gen divsc_gen.o frand.a 
divsc_gen.o:\
	cc divsc_gen.c frand.h 
	./cc divsc_gen.c
dotprod_gen:\
	ld dotprod_gen.ld dotprod_gen.o 
	./ld dotprod_gen dotprod_gen.o 
dotprod_gen.o:\
	cc dotprod_gen.c 
	./cc dotprod_gen.c
frand.a:\
	mk-slib frand.sld frand.o 
	./mk-slib frand frand.o 
frand.o:\
	cc frand.c frand.h 
	./cc frand.c
ld: conf-ld 
mag_gen:\
	ld mag_gen.ld mag_gen.lff mag_gen.o 
	./ld mag_gen mag_gen.o 
mag_gen.lff: libs-sysmath 
mag_gen.o:\
	cc mag_gen.c 
	./cc mag_gen.c
mk-cctype: conf-cc conf-systype 
mk-slib: conf-systype 
mult_gen:\
	ld mult_gen.ld mult_gen.o 
	./ld mult_gen mult_gen.o 
mult_gen.o:\
	cc mult_gen.c 
	./cc mult_gen.c
multsc_gen:\
	ld multsc_gen.ld multsc_gen.o 
	./ld multsc_gen multsc_gen.o 
multsc_gen.o:\
	cc multsc_gen.c 
	./cc multsc_gen.c
nega_gen:\
	ld nega_gen.ld nega_gen.o 
	./ld nega_gen nega_gen.o 
nega_gen.o:\
	cc nega_gen.c 
	./cc nega_gen.c
norm_gen:\
	ld norm_gen.ld norm_gen.lff norm_gen.o 
	./ld norm_gen norm_gen.o 
norm_gen.lff: libs-sysmath 
norm_gen.o:\
	cc norm_gen.c 
	./cc norm_gen.c
sub_gen:\
	ld sub_gen.ld sub_gen.o 
	./ld sub_gen sub_gen.o 
sub_gen.o:\
	cc sub_gen.c 
	./cc sub_gen.c
subsc_gen:\
	ld subsc_gen.ld subsc_gen.o 
	./ld subsc_gen subsc_gen.o 
subsc_gen.o:\
	cc subsc_gen.c 
	./cc subsc_gen.c
xprod_gen:\
	ld xprod_gen.ld xprod_gen.o 
	./ld xprod_gen xprod_gen.o 
xprod_gen.o:\
	cc xprod_gen.c 
	./cc xprod_gen.c
clean: 
	rm -f add_gen add_gen.o addsc_gen addsc_gen.o conf-cctype \
	conf-systype div_gen div_gen.o divsc_gen divsc_gen.o dotprod_gen \
	dotprod_gen.o frand.a frand.o mag_gen mag_gen.o mult_gen mult_gen.o \
	multsc_gen multsc_gen.o nega_gen nega_gen.o norm_gen norm_gen.o \
	sub_gen sub_gen.o subsc_gen subsc_gen.o xprod_gen xprod_gen.o 

regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile

