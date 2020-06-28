.PHONY: all clean

all:
	@$(MAKE) -C libcsight/
	@$(MAKE) -C CaptureSight-Applet/
	@$(MAKE) -C CaptureSight-Overlay/

clean:
	@$(MAKE) clean -C libcsight/
	@$(MAKE) clean -C CaptureSight-Applet/
	@$(MAKE) clean -C CaptureSight-Overlay/