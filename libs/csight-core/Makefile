.PHONY:	all release clean docs lint test

CARGO	:=  cargo +nightly
CARGO_FLAGS	:=  -Z build-std=core,alloc --target aarch64-none-elf.json

all: lint test release

release:
	@$(CARGO) build $(CARGO_FLAGS) --release

lint:
	@$(CARGO) clippy $(CARGO_FLAGS)

test:
	@$(CARGO) test

docs:
	@$(CARGO) doc $(CARGO_FLAGS) --open

clean:
	@cargo clean
