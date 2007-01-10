default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_sysinfo
sysdeps_clean:  sd_sysinfo_clean

sd_sysinfo:
	@(cd modules/sysinfo && ./run)
sd_sysinfo_clean:
	@(cd modules/sysinfo && ./clean)

regen:
	./gen-makefile > Makefile.tmp
	mv Makefile.tmp Makefile
