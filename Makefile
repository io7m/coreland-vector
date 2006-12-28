# auto generated - do not edit

default: all

all:\
	UNIT_TESTS/t_add1 UNIT_TESTS/t_add2 UNIT_TESTS/t_assign \
	UNIT_TESTS/t_div1 UNIT_TESTS/t_div2 UNIT_TESTS/t_dotprod \
	UNIT_TESTS/t_mag1 UNIT_TESTS/t_mult1 UNIT_TESTS/t_mult2 \
	UNIT_TESTS/t_nega1 UNIT_TESTS/t_nega2 UNIT_TESTS/t_norm1 \
	UNIT_TESTS/t_norm2 UNIT_TESTS/t_sub1 UNIT_TESTS/t_sub2 \
	UNIT_TESTS/t_util.a UNIT_TESTS/t_zero vector.a 

UNIT_TESTS/t_add1:\
	ld UNIT_TESTS/t_add1.ld UNIT_TESTS/t_add1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_add1 UNIT_TESTS/t_add1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_add1.o:\
	cc UNIT_TESTS/t_add1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_add1.c
UNIT_TESTS/t_add2:\
	ld UNIT_TESTS/t_add2.ld UNIT_TESTS/t_add2.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_add2 UNIT_TESTS/t_add2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_add2.o:\
	cc UNIT_TESTS/t_add2.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_add2.c
UNIT_TESTS/t_assign:\
	ld UNIT_TESTS/t_assign.ld UNIT_TESTS/t_assign.o vector.a 
	./ld UNIT_TESTS/t_assign UNIT_TESTS/t_assign.o vector.a 
UNIT_TESTS/t_assign.o:\
	cc UNIT_TESTS/t_assign.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_assign.c
UNIT_TESTS/t_div1:\
	ld UNIT_TESTS/t_div1.ld UNIT_TESTS/t_div1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_div1 UNIT_TESTS/t_div1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_div1.o:\
	cc UNIT_TESTS/t_div1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_div1.c
UNIT_TESTS/t_div2:\
	ld UNIT_TESTS/t_div2.ld UNIT_TESTS/t_div2.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_div2 UNIT_TESTS/t_div2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_div2.o:\
	cc UNIT_TESTS/t_div2.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_div2.c
UNIT_TESTS/t_dotprod:\
	ld UNIT_TESTS/t_dotprod.ld UNIT_TESTS/t_dotprod.o \
	UNIT_TESTS/t_util.a vector.a 
	./ld UNIT_TESTS/t_dotprod UNIT_TESTS/t_dotprod.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_dotprod.o:\
	cc UNIT_TESTS/t_dotprod.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_dotprod.c
UNIT_TESTS/t_mag1:\
	ld UNIT_TESTS/t_mag1.ld UNIT_TESTS/t_mag1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_mag1 UNIT_TESTS/t_mag1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_mag1.o:\
	cc UNIT_TESTS/t_mag1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_mag1.c
UNIT_TESTS/t_mult1:\
	ld UNIT_TESTS/t_mult1.ld UNIT_TESTS/t_mult1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_mult1 UNIT_TESTS/t_mult1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_mult1.o:\
	cc UNIT_TESTS/t_mult1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_mult1.c
UNIT_TESTS/t_mult2:\
	ld UNIT_TESTS/t_mult2.ld UNIT_TESTS/t_mult2.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_mult2 UNIT_TESTS/t_mult2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_mult2.o:\
	cc UNIT_TESTS/t_mult2.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_mult2.c
UNIT_TESTS/t_nega1:\
	ld UNIT_TESTS/t_nega1.ld UNIT_TESTS/t_nega1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_nega1 UNIT_TESTS/t_nega1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_nega1.o:\
	cc UNIT_TESTS/t_nega1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_nega1.c
UNIT_TESTS/t_nega2:\
	ld UNIT_TESTS/t_nega2.ld UNIT_TESTS/t_nega2.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_nega2 UNIT_TESTS/t_nega2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_nega2.o:\
	cc UNIT_TESTS/t_nega2.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_nega2.c
UNIT_TESTS/t_norm1:\
	ld UNIT_TESTS/t_norm1.ld UNIT_TESTS/t_norm1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_norm1 UNIT_TESTS/t_norm1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_norm1.o:\
	cc UNIT_TESTS/t_norm1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_norm1.c
UNIT_TESTS/t_norm2:\
	ld UNIT_TESTS/t_norm2.ld UNIT_TESTS/t_norm2.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_norm2 UNIT_TESTS/t_norm2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_norm2.o:\
	cc UNIT_TESTS/t_norm2.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_norm2.c
UNIT_TESTS/t_sub1:\
	ld UNIT_TESTS/t_sub1.ld UNIT_TESTS/t_sub1.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_sub1 UNIT_TESTS/t_sub1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_sub1.o:\
	cc UNIT_TESTS/t_sub1.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_sub1.c
UNIT_TESTS/t_sub2:\
	ld UNIT_TESTS/t_sub2.ld UNIT_TESTS/t_sub2.o UNIT_TESTS/t_util.a \
	vector.a 
	./ld UNIT_TESTS/t_sub2 UNIT_TESTS/t_sub2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_sub2.o:\
	cc UNIT_TESTS/t_sub2.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_sub2.c
UNIT_TESTS/t_util.a:\
	mk-slib UNIT_TESTS/t_util.sld UNIT_TESTS/t_util.o 
	./mk-slib UNIT_TESTS/t_util UNIT_TESTS/t_util.o 
UNIT_TESTS/t_util.o:\
	cc UNIT_TESTS/t_util.c UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_util.c
UNIT_TESTS/t_zero:\
	ld UNIT_TESTS/t_zero.ld UNIT_TESTS/t_zero.o vector.a 
	./ld UNIT_TESTS/t_zero UNIT_TESTS/t_zero.o vector.a 
UNIT_TESTS/t_zero.o:\
	cc UNIT_TESTS/t_zero.c vector.h UNIT_TESTS/t_util.h 
	./cc UNIT_TESTS/t_zero.c
cc: conf-cc conf-cctype conf-cflags 
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
ld: conf-ld libs-sysmath 
mk-cctype: conf-cc conf-systype 
mk-slib: conf-systype 
vec_add.o:\
	cc vec_add.c vector.h vec_add.h 
	./cc vec_add.c
vec_assi.o:\
	cc vec_assi.c vector.h vec_assi.h 
	./cc vec_assi.c
vec_dist.o:\
	cc vec_dist.c vector.h 
	./cc vec_dist.c
vec_div.o:\
	cc vec_div.c vector.h vec_div.h 
	./cc vec_div.c
vec_dotp.o:\
	cc vec_dotp.c vector.h vec_dotp.h 
	./cc vec_dotp.c
vec_mag.o:\
	cc vec_mag.c vector.h 
	./cc vec_mag.c
vec_mult.o:\
	cc vec_mult.c vector.h vec_mult.h 
	./cc vec_mult.c
vec_nega.o:\
	cc vec_nega.c vector.h vec_nega.h 
	./cc vec_nega.c
vec_norm.o:\
	cc vec_norm.c vector.h 
	./cc vec_norm.c
vec_sub.o:\
	cc vec_sub.c vector.h vec_sub.h 
	./cc vec_sub.c
vec_xprod.o:\
	cc vec_xprod.c vector.h vec_xprod.h 
	./cc vec_xprod.c
vec_zero.o:\
	cc vec_zero.c vector.h vec_zero.h 
	./cc vec_zero.c
vector.a:\
	mk-slib vector.sld vec_add.o vec_assi.o vec_dist.o vec_div.o \
	vec_dotp.o vec_mag.o vec_mult.o vec_nega.o vec_norm.o vec_sub.o \
	vec_xprod.o vec_zero.o 
	./mk-slib vector vec_add.o vec_assi.o vec_dist.o vec_div.o \
	vec_dotp.o vec_mag.o vec_mult.o vec_nega.o vec_norm.o vec_sub.o \
	vec_xprod.o vec_zero.o 
clean: tests_clean 
	rm -f UNIT_TESTS/t_add1 UNIT_TESTS/t_add1.o UNIT_TESTS/t_add2 \
	UNIT_TESTS/t_add2.o UNIT_TESTS/t_assign UNIT_TESTS/t_assign.o \
	UNIT_TESTS/t_div1 UNIT_TESTS/t_div1.o UNIT_TESTS/t_div2 \
	UNIT_TESTS/t_div2.o UNIT_TESTS/t_dotprod UNIT_TESTS/t_dotprod.o \
	UNIT_TESTS/t_mag1 UNIT_TESTS/t_mag1.o UNIT_TESTS/t_mult1 \
	UNIT_TESTS/t_mult1.o UNIT_TESTS/t_mult2 UNIT_TESTS/t_mult2.o \
	UNIT_TESTS/t_nega1 UNIT_TESTS/t_nega1.o UNIT_TESTS/t_nega2 \
	UNIT_TESTS/t_nega2.o UNIT_TESTS/t_norm1 UNIT_TESTS/t_norm1.o \
	UNIT_TESTS/t_norm2 UNIT_TESTS/t_norm2.o UNIT_TESTS/t_sub1 \
	UNIT_TESTS/t_sub1.o UNIT_TESTS/t_sub2 UNIT_TESTS/t_sub2.o \
	UNIT_TESTS/t_util.a UNIT_TESTS/t_util.o UNIT_TESTS/t_zero \
	UNIT_TESTS/t_zero.o vec_add.o vec_assi.o vec_dist.o vec_div.o \
	vec_dotp.o vec_mag.o vec_mult.o vec_nega.o vec_norm.o vec_sub.o \
	vec_xprod.o vec_zero.o vector.a 

tests:
	(cd UNIT_TESTS && make tests)
tests_clean:
	(cd UNIT_TESTS && make clean)
regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile

