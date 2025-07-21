
NUM_JOBS = $(shell nproc)

.PHONY: all gui firmware clean

BUILD_DIR = build

all: 
	@echo "Running with $(NUM_JOBS) threads"
	@$(MAKE) -C gui -j$(NUM_JOBS)
	@$(MAKE) -C firmware -j$(NUM_JOBS)

gui:
	$(MAKE) -C gui

firmware:
	$(MAKE) -C firmware

run:
	$(MAKE) -C gui run

clean:
	$(MAKE) -C gui clean
	$(MAKE) -C firmware clean
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build artifacts"
