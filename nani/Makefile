.PHONY: all release clean clean-release

all:
	$(MAKE) -f ${CURDIR}/../Makefile.ntscu
	$(MAKE) -f ${CURDIR}/../Makefile.v100.pal
	$(MAKE) -f ${CURDIR}/../Makefile.v200.pal
	$(MAKE) -f ${CURDIR}/../Makefile.ntscj

release:
	$(MAKE) -f ${CURDIR}/../Makefile.ntscu release
	$(MAKE) -f ${CURDIR}/../Makefile.v100.pal release
	$(MAKE) -f ${CURDIR}/../Makefile.v200.pal release
	$(MAKE) -f ${CURDIR}/../Makefile.ntscj release

clean:
	$(MAKE) -f ${CURDIR}/../Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/../Makefile.v100.pal clean
	$(MAKE) -f ${CURDIR}/../Makefile.v200.pal clean
	$(MAKE) -f ${CURDIR}/../Makefile.ntscj clean
	rm -f *.bin *.elf

clean-release:
	$(MAKE) -f ${CURDIR}/../Makefile.ntscu clean-release
	$(MAKE) -f ${CURDIR}/../Makefile.v100.pal clean-release
	$(MAKE) -f ${CURDIR}/../Makefile.v200.pal clean-release
	$(MAKE) -f ${CURDIR}/../Makefile.ntscj clean-release
