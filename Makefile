# target #
TARPATH = /usr/include/
SRCPATH = source/

# obj #
HEARDER	= satomic.h

# phony #
.phony:	install clean

install:
	cp $(SRCPATH)$(HEARDER) $(TARPATH) 

clean:
	rm -f $(TARPATH)$(HEARDER)
