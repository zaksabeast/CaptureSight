.PHONY: all clean

all:
	@$(MAKE) -C Atmosphere-libs/
	@$(MAKE) -C Plutonium/
	@$(MAKE) -C CaptureSight/

clean:
	@$(MAKE) clean -C Atmosphere-libs/
	@$(MAKE) clean -C Plutonium/
	@$(MAKE) clean -C CaptureSight/