# auto generated - do not edit

default: all

all:\
	add_gen sub_gen 

add_gen:\
	ld add_gen.ld add_gen.o 
	./ld add_gen add_gen.o 
add_gen.o:\
	cc add_gen.c 
	./cc add_gen.c
cc: conf-cc conf-cctype 
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
ld: conf-ld 
mk-cctype: conf-cc conf-systype 
mk-slib: conf-systype 
sub_gen:\
	ld sub_gen.ld sub_gen.o 
	./ld sub_gen sub_gen.o 
sub_gen.o:\
	cc sub_gen.c 
	./cc sub_gen.c
clean: 
	rm -f add_gen add_gen.o sub_gen sub_gen.o 

regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile

