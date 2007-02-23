default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_sysinfo sd_altivec-flags sd_sse-flags sd_sse2-flags sd_sse3-flags
sysdeps_clean:  sd_sysinfo_clean sd_altivec-flags_clean sd_sse-flags_clean sd_sse2-flags_clean sd_sse3-flags_clean

sd_sysinfo:
	@(cd modules/sysinfo && ./run)
sd_sysinfo_clean:
	@(cd modules/sysinfo && ./clean)

sd_altivec-flags:
	@(cd modules/altivec-flags && ./run)
sd_altivec-flags_clean:
	@(cd modules/altivec-flags && ./clean)

sd_sse-flags:
	@(cd modules/sse-flags && ./run)
sd_sse-flags_clean:
	@(cd modules/sse-flags && ./clean)

sd_sse2-flags:
	@(cd modules/sse2-flags && ./run)
sd_sse2-flags_clean:
	@(cd modules/sse2-flags && ./clean)

sd_sse3-flags:
	@(cd modules/sse3-flags && ./run)
sd_sse3-flags_clean:
	@(cd modules/sse3-flags && ./clean)

regen:
	./gen-makefile > Makefile.tmp
	mv Makefile.tmp Makefile
