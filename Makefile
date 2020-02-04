.PHONY: all clean

all:
	@$(MAKE) -C Atmosphere-libs/
	@$(MAKE) -C Plutonium/
	@$(MAKE) -C libtesla/
	@$(MAKE) -C libcsight/
	@$(MAKE) -C CaptureSight/
	@$(MAKE) -C CaptureSight-Overlay/

clean:
	@$(MAKE) clean -C Atmosphere-libs/
	@$(MAKE) clean -C Plutonium/
	@$(MAKE) clean -C libtesla/
	@$(MAKE) clean -C libcsight/
	@$(MAKE) clean -C CaptureSight/
	@$(MAKE) clean -C CaptureSight-Overlay/