# auto generated - do not edit

default: all

all:\
	add_gen div_gen dotprod_gen mag_gen mult_gen nega_gen norm_gen \
	sub_gen 

add_gen:\
	ld add_gen.ld add_gen.o 
	./ld add_gen add_gen.o 
add_gen.o:\
	cc add_gen.c 
	./cc add_gen.c
cc: conf-cc conf-cctype conf-cflags 
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
div_gen:\
	ld div_gen.ld div_gen.o 
	./ld div_gen div_gen.o 
div_gen.o:\
	cc div_gen.c 
	./cc div_gen.c
dotprod_gen:\
	ld dotprod_gen.ld dotprod_gen.o 
	./ld dotprod_gen dotprod_gen.o 
dotprod_gen.o:\
	cc dotprod_gen.c 
	./cc dotprod_gen.c
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
clean: 
	rm -f add_gen add_gen.o conf-cctype conf-systype div_gen div_gen.o \
	dotprod_gen dotprod_gen.o mag_gen mag_gen.o mult_gen mult_gen.o \
	nega_gen nega_gen.o norm_gen norm_gen.o sub_gen sub_gen.o 

regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile

