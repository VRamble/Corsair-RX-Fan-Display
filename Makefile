
NUM_JOBS = $(shell nproc)

.PHONY: all app firmware clean

BUILD_DIR = build

INCLUDE_PATHS = -I./app/gui -I.app/serial -I./common -I./lib/external

CXXFLAGS = -std=c++20 -g -Wformat -Wall -Wextra $(INCLUDE_PATHS) 

all: 
	@echo "Running with $(NUM_JOBS) threads"
	@$(MAKE) -C app -j$(NUM_JOBS) CXXFLAGS="$(CXXFLAGS)"
	@$(MAKE) -C firmware -j$(NUM_JOBS) CXXFLAGS="$(CXXFLAGS)"

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
