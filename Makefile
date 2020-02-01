.PHONY: all clean

all:
	@$(MAKE) -C Atmosphere-libs/
	@$(MAKE) -C Plutonium/
	@$(MAKE) -C libcapturesight/
	@$(MAKE) -C CaptureSight/

clean:
	@$(MAKE) clean -C Atmosphere-libs/
	@$(MAKE) clean -C Plutonium/
	@$(MAKE) clean -C libcapturesight/
	@$(MAKE) clean -C CaptureSight/