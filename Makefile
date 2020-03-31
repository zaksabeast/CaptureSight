.PHONY: all clean

all:
	@$(MAKE) -C Atmosphere-libs/libstratosphere
	@$(MAKE) -C Plutonium/
	@$(MAKE) -C libcsight/
	@$(MAKE) -C CaptureSight/
	@$(MAKE) -C CaptureSight-Overlay/

clean:
	@$(MAKE) clean -C Atmosphere-libs/libstratosphere
	@$(MAKE) clean -C Plutonium/
	@$(MAKE) clean -C libcsight/
	@$(MAKE) clean -C CaptureSight/
	@$(MAKE) clean -C CaptureSight-Overlay/