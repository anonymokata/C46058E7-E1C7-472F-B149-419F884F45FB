all:
	$(MAKE) -C source all

check:
	$(MAKE) -C source && $(MAKE) check -C source

clean:
	$(MAKE) clean -C source

