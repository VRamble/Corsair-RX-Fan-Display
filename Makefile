
NUM_JOBS = $(shell nproc)

.PHONY: all app firmware clean

BUILD_DIR = build

all: 
	@echo "Running with $(NUM_JOBS) threads"
	@$(MAKE) -C app -j$(NUM_JOBS)
	@$(MAKE) -C firmware -j$(NUM_JOBS)

app:
	$(MAKE) -C app

firmware:
	$(MAKE) -C firmware

run:
	$(MAKE) -C app run

clean:
	$(MAKE) -C app clean
	$(MAKE) -C firmware clean
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build artifacts"
