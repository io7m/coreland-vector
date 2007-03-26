# auto generated - do not edit

default: all

all: sysdeps.out UNIT_TESTS/t_add1 UNIT_TESTS/t_add2 \
	UNIT_TESTS/t_addsc1 UNIT_TESTS/t_addsc2 UNIT_TESTS/t_assign \
	UNIT_TESTS/t_div1 UNIT_TESTS/t_div2 UNIT_TESTS/t_divsc1 \
	UNIT_TESTS/t_divsc2 UNIT_TESTS/t_dotprod UNIT_TESTS/t_mag1 \
	UNIT_TESTS/t_mult1 UNIT_TESTS/t_mult2 UNIT_TESTS/t_multsc1 \
	UNIT_TESTS/t_multsc2 UNIT_TESTS/t_nega1 UNIT_TESTS/t_nega2 \
	UNIT_TESTS/t_norm1 UNIT_TESTS/t_norm2 UNIT_TESTS/t_sub1 \
	UNIT_TESTS/t_sub2 UNIT_TESTS/t_subsc1 UNIT_TESTS/t_subsc2 \
	UNIT_TESTS/t_util.a UNIT_TESTS/t_xprod UNIT_TESTS/t_zero ctxt/ctxt.a \
	deinstaller inst-check inst-copy inst-dir inst-link installer \
	instchk vector-conf vector.a 

sysdeps: sysdeps.out
sysdeps.out:
	SYSDEPS/sysdep-header sysdeps.out
	(cd SYSDEPS && make)
sysdeps_clean:
	(cd SYSDEPS && make clean)
	rm -f sysdeps.out

UNIT_TESTS/t_add1:\
	cc-link UNIT_TESTS/t_add1.ld UNIT_TESTS/t_add1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_add1 UNIT_TESTS/t_add1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_add1.o:\
	cc-compile UNIT_TESTS/t_add1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_add_data.c 
	./cc-compile UNIT_TESTS/t_add1.c
UNIT_TESTS/t_add2:\
	cc-link UNIT_TESTS/t_add2.ld UNIT_TESTS/t_add2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_add2 UNIT_TESTS/t_add2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_add2.o:\
	cc-compile UNIT_TESTS/t_add2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_add_data.c 
	./cc-compile UNIT_TESTS/t_add2.c
UNIT_TESTS/t_add_data.o:\
	cc-compile UNIT_TESTS/t_add_data.c 
	./cc-compile UNIT_TESTS/t_add_data.c
UNIT_TESTS/t_addsc1:\
	cc-link UNIT_TESTS/t_addsc1.ld UNIT_TESTS/t_addsc1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_addsc1 UNIT_TESTS/t_addsc1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_addsc1.o:\
	cc-compile UNIT_TESTS/t_addsc1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_addsc_data.c 
	./cc-compile UNIT_TESTS/t_addsc1.c
UNIT_TESTS/t_addsc2:\
	cc-link UNIT_TESTS/t_addsc2.ld UNIT_TESTS/t_addsc2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_addsc2 UNIT_TESTS/t_addsc2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_addsc2.o:\
	cc-compile UNIT_TESTS/t_addsc2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_addsc_data.c 
	./cc-compile UNIT_TESTS/t_addsc2.c
UNIT_TESTS/t_addsc_data.o:\
	cc-compile UNIT_TESTS/t_addsc_data.c 
	./cc-compile UNIT_TESTS/t_addsc_data.c
UNIT_TESTS/t_assign:\
	cc-link UNIT_TESTS/t_assign.ld UNIT_TESTS/t_assign.o \
	UNIT_TESTS/t_util.o vector.a 
	./cc-link UNIT_TESTS/t_assign UNIT_TESTS/t_assign.o \
	UNIT_TESTS/t_util.o vector.a 
UNIT_TESTS/t_assign.o:\
	cc-compile UNIT_TESTS/t_assign.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_assign_data.c 
	./cc-compile UNIT_TESTS/t_assign.c
UNIT_TESTS/t_assign_data.o:\
	cc-compile UNIT_TESTS/t_assign_data.c 
	./cc-compile UNIT_TESTS/t_assign_data.c
UNIT_TESTS/t_div1:\
	cc-link UNIT_TESTS/t_div1.ld UNIT_TESTS/t_div1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_div1 UNIT_TESTS/t_div1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_div1.o:\
	cc-compile UNIT_TESTS/t_div1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_div_data.c 
	./cc-compile UNIT_TESTS/t_div1.c
UNIT_TESTS/t_div2:\
	cc-link UNIT_TESTS/t_div2.ld UNIT_TESTS/t_div2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_div2 UNIT_TESTS/t_div2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_div2.o:\
	cc-compile UNIT_TESTS/t_div2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_div_data.c 
	./cc-compile UNIT_TESTS/t_div2.c
UNIT_TESTS/t_div_data.o:\
	cc-compile UNIT_TESTS/t_div_data.c 
	./cc-compile UNIT_TESTS/t_div_data.c
UNIT_TESTS/t_divsc1:\
	cc-link UNIT_TESTS/t_divsc1.ld UNIT_TESTS/t_divsc1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_divsc1 UNIT_TESTS/t_divsc1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_divsc1.o:\
	cc-compile UNIT_TESTS/t_divsc1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_divsc_data.c 
	./cc-compile UNIT_TESTS/t_divsc1.c
UNIT_TESTS/t_divsc2:\
	cc-link UNIT_TESTS/t_divsc2.ld UNIT_TESTS/t_divsc2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_divsc2 UNIT_TESTS/t_divsc2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_divsc2.o:\
	cc-compile UNIT_TESTS/t_divsc2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_divsc_data.c 
	./cc-compile UNIT_TESTS/t_divsc2.c
UNIT_TESTS/t_divsc_data.o:\
	cc-compile UNIT_TESTS/t_divsc_data.c 
	./cc-compile UNIT_TESTS/t_divsc_data.c
UNIT_TESTS/t_dotp_data.o:\
	cc-compile UNIT_TESTS/t_dotp_data.c 
	./cc-compile UNIT_TESTS/t_dotp_data.c
UNIT_TESTS/t_dotprod:\
	cc-link UNIT_TESTS/t_dotprod.ld UNIT_TESTS/t_dotprod.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_dotprod UNIT_TESTS/t_dotprod.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_dotprod.o:\
	cc-compile UNIT_TESTS/t_dotprod.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_dotp_data.c 
	./cc-compile UNIT_TESTS/t_dotprod.c
UNIT_TESTS/t_mag1:\
	cc-link UNIT_TESTS/t_mag1.ld UNIT_TESTS/t_mag1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_mag1 UNIT_TESTS/t_mag1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_mag1.o:\
	cc-compile UNIT_TESTS/t_mag1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_mag_data.c 
	./cc-compile UNIT_TESTS/t_mag1.c
UNIT_TESTS/t_mag_data.o:\
	cc-compile UNIT_TESTS/t_mag_data.c 
	./cc-compile UNIT_TESTS/t_mag_data.c
UNIT_TESTS/t_mult1:\
	cc-link UNIT_TESTS/t_mult1.ld UNIT_TESTS/t_mult1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_mult1 UNIT_TESTS/t_mult1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_mult1.o:\
	cc-compile UNIT_TESTS/t_mult1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_mult_data.c 
	./cc-compile UNIT_TESTS/t_mult1.c
UNIT_TESTS/t_mult2:\
	cc-link UNIT_TESTS/t_mult2.ld UNIT_TESTS/t_mult2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_mult2 UNIT_TESTS/t_mult2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_mult2.o:\
	cc-compile UNIT_TESTS/t_mult2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_mult_data.c 
	./cc-compile UNIT_TESTS/t_mult2.c
UNIT_TESTS/t_mult_data.o:\
	cc-compile UNIT_TESTS/t_mult_data.c 
	./cc-compile UNIT_TESTS/t_mult_data.c
UNIT_TESTS/t_multsc1:\
	cc-link UNIT_TESTS/t_multsc1.ld UNIT_TESTS/t_multsc1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_multsc1 UNIT_TESTS/t_multsc1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_multsc1.o:\
	cc-compile UNIT_TESTS/t_multsc1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_multsc_data.c 
	./cc-compile UNIT_TESTS/t_multsc1.c
UNIT_TESTS/t_multsc2:\
	cc-link UNIT_TESTS/t_multsc2.ld UNIT_TESTS/t_multsc2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_multsc2 UNIT_TESTS/t_multsc2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_multsc2.o:\
	cc-compile UNIT_TESTS/t_multsc2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_multsc_data.c 
	./cc-compile UNIT_TESTS/t_multsc2.c
UNIT_TESTS/t_multsc_data.o:\
	cc-compile UNIT_TESTS/t_multsc_data.c 
	./cc-compile UNIT_TESTS/t_multsc_data.c
UNIT_TESTS/t_nega1:\
	cc-link UNIT_TESTS/t_nega1.ld UNIT_TESTS/t_nega1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_nega1 UNIT_TESTS/t_nega1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_nega1.o:\
	cc-compile UNIT_TESTS/t_nega1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_nega_data.c 
	./cc-compile UNIT_TESTS/t_nega1.c
UNIT_TESTS/t_nega2:\
	cc-link UNIT_TESTS/t_nega2.ld UNIT_TESTS/t_nega2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_nega2 UNIT_TESTS/t_nega2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_nega2.o:\
	cc-compile UNIT_TESTS/t_nega2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_nega_data.c 
	./cc-compile UNIT_TESTS/t_nega2.c
UNIT_TESTS/t_nega_data.o:\
	cc-compile UNIT_TESTS/t_nega_data.c 
	./cc-compile UNIT_TESTS/t_nega_data.c
UNIT_TESTS/t_norm1:\
	cc-link UNIT_TESTS/t_norm1.ld UNIT_TESTS/t_norm1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_norm1 UNIT_TESTS/t_norm1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_norm1.o:\
	cc-compile UNIT_TESTS/t_norm1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_norm_data.c 
	./cc-compile UNIT_TESTS/t_norm1.c
UNIT_TESTS/t_norm2:\
	cc-link UNIT_TESTS/t_norm2.ld UNIT_TESTS/t_norm2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_norm2 UNIT_TESTS/t_norm2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_norm2.o:\
	cc-compile UNIT_TESTS/t_norm2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_norm_data.c 
	./cc-compile UNIT_TESTS/t_norm2.c
UNIT_TESTS/t_norm_data.o:\
	cc-compile UNIT_TESTS/t_norm_data.c 
	./cc-compile UNIT_TESTS/t_norm_data.c
UNIT_TESTS/t_sub1:\
	cc-link UNIT_TESTS/t_sub1.ld UNIT_TESTS/t_sub1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_sub1 UNIT_TESTS/t_sub1.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_sub1.o:\
	cc-compile UNIT_TESTS/t_sub1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_sub_data.c 
	./cc-compile UNIT_TESTS/t_sub1.c
UNIT_TESTS/t_sub2:\
	cc-link UNIT_TESTS/t_sub2.ld UNIT_TESTS/t_sub2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_sub2 UNIT_TESTS/t_sub2.o UNIT_TESTS/t_util.a \
	vector.a 
UNIT_TESTS/t_sub2.o:\
	cc-compile UNIT_TESTS/t_sub2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_sub_data.c 
	./cc-compile UNIT_TESTS/t_sub2.c
UNIT_TESTS/t_sub_data.o:\
	cc-compile UNIT_TESTS/t_sub_data.c 
	./cc-compile UNIT_TESTS/t_sub_data.c
UNIT_TESTS/t_subsc1:\
	cc-link UNIT_TESTS/t_subsc1.ld UNIT_TESTS/t_subsc1.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_subsc1 UNIT_TESTS/t_subsc1.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_subsc1.o:\
	cc-compile UNIT_TESTS/t_subsc1.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_subsc_data.c 
	./cc-compile UNIT_TESTS/t_subsc1.c
UNIT_TESTS/t_subsc2:\
	cc-link UNIT_TESTS/t_subsc2.ld UNIT_TESTS/t_subsc2.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_subsc2 UNIT_TESTS/t_subsc2.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_subsc2.o:\
	cc-compile UNIT_TESTS/t_subsc2.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_subsc_data.c 
	./cc-compile UNIT_TESTS/t_subsc2.c
UNIT_TESTS/t_subsc_data.o:\
	cc-compile UNIT_TESTS/t_subsc_data.c 
	./cc-compile UNIT_TESTS/t_subsc_data.c
UNIT_TESTS/t_util.a:\
	cc-slib UNIT_TESTS/t_util.sld UNIT_TESTS/t_util.o 
	./cc-slib UNIT_TESTS/t_util UNIT_TESTS/t_util.o 
UNIT_TESTS/t_util.o:\
	cc-compile UNIT_TESTS/t_util.c UNIT_TESTS/t_util.h 
	./cc-compile UNIT_TESTS/t_util.c
UNIT_TESTS/t_xprod:\
	cc-link UNIT_TESTS/t_xprod.ld UNIT_TESTS/t_xprod.o \
	UNIT_TESTS/t_util.a vector.a 
	./cc-link UNIT_TESTS/t_xprod UNIT_TESTS/t_xprod.o \
	UNIT_TESTS/t_util.a vector.a 
UNIT_TESTS/t_xprod.o:\
	cc-compile UNIT_TESTS/t_xprod.c vector.h UNIT_TESTS/t_util.h 
	./cc-compile UNIT_TESTS/t_xprod.c
UNIT_TESTS/t_zero:\
	cc-link UNIT_TESTS/t_zero.ld UNIT_TESTS/t_zero.o \
	UNIT_TESTS/t_util.o vector.a 
	./cc-link UNIT_TESTS/t_zero UNIT_TESTS/t_zero.o UNIT_TESTS/t_util.o \
	vector.a 
UNIT_TESTS/t_zero.o:\
	cc-compile UNIT_TESTS/t_zero.c vector.h UNIT_TESTS/t_util.h \
	UNIT_TESTS/t_zero_data.c 
	./cc-compile UNIT_TESTS/t_zero.c
UNIT_TESTS/t_zero_data.o:\
	cc-compile UNIT_TESTS/t_zero_data.c 
	./cc-compile UNIT_TESTS/t_zero_data.c
cc-compile: conf-cc conf-cctype conf-cflags sysdeps.out flags-sse \
	flags-sse2 flags-altivec 
cc-link: conf-ld sysdeps.out libs-math 
cc-slib: conf-systype 
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-sosuffix:\
	mk-sosuffix 
	./mk-sosuffix > conf-sosuffix
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
ctxt/bindir.c: mk-ctxt conf-bindir
	rm -f ctxt/bindir.c
	./mk-ctxt ctxt_bindir < conf-bindir > ctxt/bindir.c

ctxt/bindir.o:\
	cc-compile ctxt/bindir.c 
	./cc-compile ctxt/bindir.c
ctxt/ctxt.a:\
	cc-slib ctxt/ctxt.sld ctxt/bindir.o ctxt/dlibdir.o \
	ctxt/flags_altivec.o ctxt/flags_sse.o ctxt/flags_sse2.o \
	ctxt/flags_sse3.o ctxt/incdir.o ctxt/repos.o ctxt/slibdir.o \
	ctxt/version.o 
	./cc-slib ctxt/ctxt ctxt/bindir.o ctxt/dlibdir.o \
	ctxt/flags_altivec.o ctxt/flags_sse.o ctxt/flags_sse2.o \
	ctxt/flags_sse3.o ctxt/incdir.o ctxt/repos.o ctxt/slibdir.o \
	ctxt/version.o 
ctxt/dlibdir.c: mk-ctxt conf-dlibdir
	rm -f ctxt/dlibdir.c
	./mk-ctxt ctxt_dlibdir < conf-dlibdir > ctxt/dlibdir.c

ctxt/dlibdir.o:\
	cc-compile ctxt/dlibdir.c 
	./cc-compile ctxt/dlibdir.c
ctxt/flags_altivec.c: mk-ctxt flags-altivec
	rm -f ctxt/flags_altivec.c
	./mk-ctxt ctxt_flags_altivec < flags-altivec > ctxt/flags_altivec.c

ctxt/flags_altivec.o:\
	cc-compile ctxt/flags_altivec.c 
	./cc-compile ctxt/flags_altivec.c
ctxt/flags_sse.c: mk-ctxt flags-sse
	rm -f ctxt/flags_sse.c
	./mk-ctxt ctxt_flags_sse < flags-sse > ctxt/flags_sse.c

ctxt/flags_sse.o:\
	cc-compile ctxt/flags_sse.c 
	./cc-compile ctxt/flags_sse.c
ctxt/flags_sse2.c: mk-ctxt flags-sse2
	rm -f ctxt/flags_sse2.c
	./mk-ctxt ctxt_flags_sse2 < flags-sse2 > ctxt/flags_sse2.c

ctxt/flags_sse2.o:\
	cc-compile ctxt/flags_sse2.c 
	./cc-compile ctxt/flags_sse2.c
ctxt/flags_sse3.c: mk-ctxt flags-sse3
	rm -f ctxt/flags_sse3.c
	./mk-ctxt ctxt_flags_sse3 < flags-sse3 > ctxt/flags_sse3.c

ctxt/flags_sse3.o:\
	cc-compile ctxt/flags_sse3.c 
	./cc-compile ctxt/flags_sse3.c
ctxt/incdir.c: mk-ctxt conf-incdir
	rm -f ctxt/incdir.c
	./mk-ctxt ctxt_incdir < conf-incdir > ctxt/incdir.c

ctxt/incdir.o:\
	cc-compile ctxt/incdir.c 
	./cc-compile ctxt/incdir.c
ctxt/repos.c: mk-ctxt conf-repos
	rm -f ctxt/repos.c
	./mk-ctxt ctxt_repos < conf-repos > ctxt/repos.c

ctxt/repos.o:\
	cc-compile ctxt/repos.c 
	./cc-compile ctxt/repos.c
ctxt/slibdir.c: mk-ctxt conf-slibdir
	rm -f ctxt/slibdir.c
	./mk-ctxt ctxt_slibdir < conf-slibdir > ctxt/slibdir.c

ctxt/slibdir.o:\
	cc-compile ctxt/slibdir.c 
	./cc-compile ctxt/slibdir.c
ctxt/version.c: mk-ctxt VERSION
	rm -f ctxt/version.c
	./mk-ctxt ctxt_version < VERSION > ctxt/version.c

ctxt/version.o:\
	cc-compile ctxt/version.c 
	./cc-compile ctxt/version.c
deinstaller:\
	cc-link deinstaller.ld deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link deinstaller deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
deinstaller.o:\
	cc-compile deinstaller.c install.h 
	./cc-compile deinstaller.c
inst-check:\
	cc-link inst-check.ld inst-check.o install_error.o 
	./cc-link inst-check inst-check.o install_error.o 
inst-check.o:\
	cc-compile inst-check.c install.h 
	./cc-compile inst-check.c
inst-copy:\
	cc-link inst-copy.ld inst-copy.o install_error.o 
	./cc-link inst-copy inst-copy.o install_error.o 
inst-copy.o:\
	cc-compile inst-copy.c install.h 
	./cc-compile inst-copy.c
inst-dir:\
	cc-link inst-dir.ld inst-dir.o install_error.o 
	./cc-link inst-dir inst-dir.o install_error.o 
inst-dir.o:\
	cc-compile inst-dir.c install.h 
	./cc-compile inst-dir.c
inst-link:\
	cc-link inst-link.ld inst-link.o install_error.o 
	./cc-link inst-link inst-link.o install_error.o 
inst-link.o:\
	cc-compile inst-link.c install.h 
	./cc-compile inst-link.c
install_core.o:\
	cc-compile install_core.c install.h 
	./cc-compile install_core.c
install_error.o:\
	cc-compile install_error.c install.h 
	./cc-compile install_error.c
installer:\
	cc-link installer.ld installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
installer.o:\
	cc-compile installer.c install.h 
	./cc-compile installer.c
instchk:\
	cc-link instchk.ld instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link instchk instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
instchk.o:\
	cc-compile instchk.c install.h 
	./cc-compile instchk.c
insthier.o:\
	cc-compile insthier.c ctxt.h install.h 
	./cc-compile insthier.c
mk-cctype: conf-cc conf-systype 
mk-ctxt.o:\
	cc-compile mk-ctxt.c
	./cc-compile mk-ctxt.c
mk-ctxt:\
	cc-link mk-ctxt.o mk-ctxt.ld
	./cc-link mk-ctxt mk-ctxt.o
mk-sosuffix: conf-systype 
mk-systype: conf-cc 
vec_add.o:\
	cc-compile vec_add.c vec_add.h vec_simd.h 
	./cc-compile vec_add.c
vec_addsc.o:\
	cc-compile vec_addsc.c vec_addsc.h vec_simd.h vec_types.h 
	./cc-compile vec_addsc.c
vec_angle.o:\
	cc-compile vec_angle.c vec_dotp.h vec_mag.h vec_angle.h 
	./cc-compile vec_angle.c
vec_anglen.o:\
	cc-compile vec_anglen.c vec_dotp.h vec_anglen.h 
	./cc-compile vec_anglen.c
vec_assi.o:\
	cc-compile vec_assi.c vec_assi.h vec_simd.h 
	./cc-compile vec_assi.c
vec_degree.o:\
	cc-compile vec_degree.c vec_angle.h vec_degree.h 
	./cc-compile vec_degree.c
vec_degreen.o:\
	cc-compile vec_degreen.c vec_angle.h vec_degreen.h 
	./cc-compile vec_degreen.c
vec_dist.o:\
	cc-compile vec_dist.c vec_dist.h 
	./cc-compile vec_dist.c
vec_div.o:\
	cc-compile vec_div.c vec_div.h vec_simd.h 
	./cc-compile vec_div.c
vec_divsc.o:\
	cc-compile vec_divsc.c vec_divsc.h vec_simd.h vec_types.h 
	./cc-compile vec_divsc.c
vec_dotp.o:\
	cc-compile vec_dotp.c vec_dotp.h vec_types.h vec_simd.h 
	./cc-compile vec_dotp.c
vec_mag.o:\
	cc-compile vec_mag.c vec_mag.h vec_dotp.h vec_simd.h 
	./cc-compile vec_mag.c
vec_mult.o:\
	cc-compile vec_mult.c vec_mult.h vec_simd.h 
	./cc-compile vec_mult.c
vec_multsc.o:\
	cc-compile vec_multsc.c vec_multsc.h vec_simd.h vec_types.h 
	./cc-compile vec_multsc.c
vec_nega.o:\
	cc-compile vec_nega.c vec_nega.h vec_simd.h vec_types.h 
	./cc-compile vec_nega.c
vec_norm.o:\
	cc-compile vec_norm.c vec_dotp.h vec_norm.h vec_multsc.h vec_simd.h \
	vec_types.h 
	./cc-compile vec_norm.c
vec_simd.o:\
	cc-compile vec_simd.c vec_simd.h 
	./cc-compile vec_simd.c
vec_sub.o:\
	cc-compile vec_sub.c vec_sub.h vec_simd.h 
	./cc-compile vec_sub.c
vec_subsc.o:\
	cc-compile vec_subsc.c vec_subsc.h vec_simd.h vec_types.h 
	./cc-compile vec_subsc.c
vec_xprod.o:\
	cc-compile vec_xprod.c vec_xprod.h 
	./cc-compile vec_xprod.c
vec_zero.o:\
	cc-compile vec_zero.c vec_zero.h vec_simd.h 
	./cc-compile vec_zero.c
vector-conf:\
	cc-link vector-conf.ld vector-conf.o ctxt/ctxt.a 
	./cc-link vector-conf vector-conf.o ctxt/ctxt.a 
vector-conf.o:\
	cc-compile vector-conf.c ctxt.h vec_simd.h 
	./cc-compile vector-conf.c
vector.a:\
	cc-slib vector.sld vec_add.o vec_addsc.o vec_angle.o vec_anglen.o \
	vec_assi.o vec_degree.o vec_degreen.o vec_dist.o vec_div.o \
	vec_divsc.o vec_dotp.o vec_mag.o vec_mult.o vec_multsc.o vec_nega.o \
	vec_norm.o vec_simd.o vec_sub.o vec_subsc.o vec_xprod.o vec_zero.o 
	./cc-slib vector vec_add.o vec_addsc.o vec_angle.o vec_anglen.o \
	vec_assi.o vec_degree.o vec_degreen.o vec_dist.o vec_div.o \
	vec_divsc.o vec_dotp.o vec_mag.o vec_mult.o vec_multsc.o vec_nega.o \
	vec_norm.o vec_simd.o vec_sub.o vec_subsc.o vec_xprod.o vec_zero.o 
clean: sysdeps_clean tests_clean 
	rm -f UNIT_TESTS/t_add1 UNIT_TESTS/t_add1.o UNIT_TESTS/t_add2 \
	UNIT_TESTS/t_add2.o UNIT_TESTS/t_add_data.o UNIT_TESTS/t_addsc1 \
	UNIT_TESTS/t_addsc1.o UNIT_TESTS/t_addsc2 UNIT_TESTS/t_addsc2.o \
	UNIT_TESTS/t_addsc_data.o UNIT_TESTS/t_assign UNIT_TESTS/t_assign.o \
	UNIT_TESTS/t_assign_data.o UNIT_TESTS/t_div1 UNIT_TESTS/t_div1.o \
	UNIT_TESTS/t_div2 UNIT_TESTS/t_div2.o UNIT_TESTS/t_div_data.o \
	UNIT_TESTS/t_divsc1 UNIT_TESTS/t_divsc1.o UNIT_TESTS/t_divsc2 \
	UNIT_TESTS/t_divsc2.o UNIT_TESTS/t_divsc_data.o \
	UNIT_TESTS/t_dotp_data.o UNIT_TESTS/t_dotprod UNIT_TESTS/t_dotprod.o \
	UNIT_TESTS/t_mag1 UNIT_TESTS/t_mag1.o UNIT_TESTS/t_mag_data.o \
	UNIT_TESTS/t_mult1 UNIT_TESTS/t_mult1.o UNIT_TESTS/t_mult2 \
	UNIT_TESTS/t_mult2.o UNIT_TESTS/t_mult_data.o UNIT_TESTS/t_multsc1 \
	UNIT_TESTS/t_multsc1.o UNIT_TESTS/t_multsc2 UNIT_TESTS/t_multsc2.o \
	UNIT_TESTS/t_multsc_data.o UNIT_TESTS/t_nega1 UNIT_TESTS/t_nega1.o \
	UNIT_TESTS/t_nega2 UNIT_TESTS/t_nega2.o UNIT_TESTS/t_nega_data.o \
	UNIT_TESTS/t_norm1 UNIT_TESTS/t_norm1.o UNIT_TESTS/t_norm2 \
	UNIT_TESTS/t_norm2.o UNIT_TESTS/t_norm_data.o UNIT_TESTS/t_sub1 \
	UNIT_TESTS/t_sub1.o UNIT_TESTS/t_sub2 UNIT_TESTS/t_sub2.o \
	UNIT_TESTS/t_sub_data.o UNIT_TESTS/t_subsc1 UNIT_TESTS/t_subsc1.o \
	UNIT_TESTS/t_subsc2 UNIT_TESTS/t_subsc2.o UNIT_TESTS/t_subsc_data.o \
	UNIT_TESTS/t_util.a UNIT_TESTS/t_util.o UNIT_TESTS/t_xprod \
	UNIT_TESTS/t_xprod.o UNIT_TESTS/t_zero 
	rm -f UNIT_TESTS/t_zero.o UNIT_TESTS/t_zero_data.o conf-cctype \
	conf-systype ctxt/bindir.c ctxt/bindir.o ctxt/ctxt.a ctxt/dlibdir.c \
	ctxt/dlibdir.o ctxt/flags_altivec.c ctxt/flags_altivec.o \
	ctxt/flags_sse.c ctxt/flags_sse.o ctxt/flags_sse2.c \
	ctxt/flags_sse2.o ctxt/flags_sse3.c ctxt/flags_sse3.o ctxt/incdir.c \
	ctxt/incdir.o ctxt/repos.c ctxt/repos.o ctxt/slibdir.c \
	ctxt/slibdir.o ctxt/version.c ctxt/version.o deinstaller \
	deinstaller.o inst-check inst-check.o inst-copy inst-copy.o inst-dir \
	inst-dir.o inst-link inst-link.o install_core.o install_error.o \
	installer installer.o instchk instchk.o insthier.o mk-ctxt.o \
	vec_add.o vec_addsc.o vec_angle.o vec_anglen.o vec_assi.o \
	vec_degree.o vec_degreen.o vec_dist.o vec_div.o vec_divsc.o \
	vec_dotp.o vec_mag.o vec_mult.o vec_multsc.o vec_nega.o vec_norm.o \
	vec_simd.o vec_sub.o vec_subsc.o vec_xprod.o vec_zero.o 
	rm -f vector-conf vector-conf.o vector.a 

deinstall: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller
deinstall-dryrun: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller dryrun
install: installer inst-check inst-copy inst-dir inst-link postinstall
	./installer
	./postinstall

install-dryrun: installer inst-check inst-copy inst-dir inst-link
	./installer dryrun
install-check: instchk inst-check
	./instchk
tests:
	(cd UNIT_TESTS && make tests)
tests_clean:
	(cd UNIT_TESTS && make clean)
regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile

