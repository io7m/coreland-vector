# auto generated - do not edit

default: all

all:\
abs_gen add_gen addsc_gen assi_gen div_gen divsc_gen dotprod_gen frand.a \
mag_gen mult_gen multsc_gen nega_gen norm_gen sub_gen subsc_gen xprod_gen 

abs_gen:\
cc-link abs_gen.ld abs_gen.o frand.a 
	./cc-link abs_gen abs_gen.o frand.a 

abs_gen.o:\
cc-compile abs_gen.c frand.h 
	./cc-compile abs_gen.c

add_gen:\
cc-link add_gen.ld add_gen.o frand.a 
	./cc-link add_gen add_gen.o frand.a 

add_gen.o:\
cc-compile add_gen.c frand.h 
	./cc-compile add_gen.c

addsc_gen:\
cc-link addsc_gen.ld addsc_gen.o frand.a 
	./cc-link addsc_gen addsc_gen.o frand.a 

addsc_gen.o:\
cc-compile addsc_gen.c frand.h 
	./cc-compile addsc_gen.c

assi_gen:\
cc-link assi_gen.ld assi_gen.o frand.a 
	./cc-link assi_gen assi_gen.o frand.a 

assi_gen.o:\
cc-compile assi_gen.c frand.h 
	./cc-compile assi_gen.c

cc-compile:\
conf-cc conf-cctype conf-systype 

cc-link:\
conf-ld conf-ldtype conf-systype 

cc-slib:\
conf-systype 

conf-cctype:\
conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype.tmp && mv conf-cctype.tmp conf-cctype

conf-ldtype:\
conf-systype conf-ld conf-cctype mk-ldtype 
	./mk-ldtype > conf-ldtype.tmp && mv conf-ldtype.tmp conf-ldtype

conf-systype:\
mk-systype 
	./mk-systype > conf-systype.tmp && mv conf-systype.tmp conf-systype

div_gen:\
cc-link div_gen.ld div_gen.o frand.a 
	./cc-link div_gen div_gen.o frand.a 

div_gen.o:\
cc-compile div_gen.c frand.h 
	./cc-compile div_gen.c

divsc_gen:\
cc-link divsc_gen.ld divsc_gen.o frand.a 
	./cc-link divsc_gen divsc_gen.o frand.a 

divsc_gen.o:\
cc-compile divsc_gen.c frand.h 
	./cc-compile divsc_gen.c

dotprod_gen:\
cc-link dotprod_gen.ld dotprod_gen.o 
	./cc-link dotprod_gen dotprod_gen.o 

dotprod_gen.o:\
cc-compile dotprod_gen.c 
	./cc-compile dotprod_gen.c

frand.a:\
cc-slib frand.sld frand.o 
	./cc-slib frand frand.o 

frand.o:\
cc-compile frand.c frand.h 
	./cc-compile frand.c

mag_gen:\
cc-link mag_gen.ld mag_gen.lff mag_gen.o 
	./cc-link mag_gen mag_gen.o 

mag_gen.lff:\
libs-sysmath 

mag_gen.o:\
cc-compile mag_gen.c 
	./cc-compile mag_gen.c

mk-cctype:\
conf-cc conf-systype 

mk-ctxt:\
mk-mk-ctxt 
	./mk-mk-ctxt

mk-ldtype:\
conf-cctype conf-systype 

mk-mk-ctxt:\
conf-cc 

mk-systype:\
conf-cc 

mult_gen:\
cc-link mult_gen.ld mult_gen.o frand.a 
	./cc-link mult_gen mult_gen.o frand.a 

mult_gen.o:\
cc-compile mult_gen.c frand.h 
	./cc-compile mult_gen.c

multsc_gen:\
cc-link multsc_gen.ld multsc_gen.o frand.a 
	./cc-link multsc_gen multsc_gen.o frand.a 

multsc_gen.o:\
cc-compile multsc_gen.c frand.h 
	./cc-compile multsc_gen.c

nega_gen:\
cc-link nega_gen.ld nega_gen.o frand.a 
	./cc-link nega_gen nega_gen.o frand.a 

nega_gen.o:\
cc-compile nega_gen.c frand.h 
	./cc-compile nega_gen.c

norm_gen:\
cc-link norm_gen.ld norm_gen.lff norm_gen.o frand.a 
	./cc-link norm_gen norm_gen.o frand.a 

norm_gen.lff:\
libs-sysmath 

norm_gen.o:\
cc-compile norm_gen.c frand.h 
	./cc-compile norm_gen.c

sub_gen:\
cc-link sub_gen.ld sub_gen.o frand.a 
	./cc-link sub_gen sub_gen.o frand.a 

sub_gen.o:\
cc-compile sub_gen.c frand.h 
	./cc-compile sub_gen.c

subsc_gen:\
cc-link subsc_gen.ld subsc_gen.o frand.a 
	./cc-link subsc_gen subsc_gen.o frand.a 

subsc_gen.o:\
cc-compile subsc_gen.c frand.h 
	./cc-compile subsc_gen.c

xprod_gen:\
cc-link xprod_gen.ld xprod_gen.o 
	./cc-link xprod_gen xprod_gen.o 

xprod_gen.o:\
cc-compile xprod_gen.c 
	./cc-compile xprod_gen.c

clean-all: obj_clean 
clean: obj_clean
obj_clean: 
	rm -f abs_gen abs_gen.o add_gen add_gen.o addsc_gen addsc_gen.o \
	assi_gen assi_gen.o conf-cctype conf-ldtype conf-systype div_gen \
	div_gen.o divsc_gen divsc_gen.o dotprod_gen dotprod_gen.o frand.a \
	frand.o mag_gen mag_gen.o mult_gen mult_gen.o multsc_gen \
	multsc_gen.o nega_gen nega_gen.o norm_gen norm_gen.o sub_gen \
	sub_gen.o subsc_gen subsc_gen.o xprod_gen xprod_gen.o 

regen:
	cpj-genmk > Makefile.tmp && mv Makefile.tmp Makefile

