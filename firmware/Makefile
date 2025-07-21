
BOARD = arduino:avr:nano
PORT = #

BUILD_DIR = ../build/firmware
SRC_DIR = src
BIN := $(BUILD_DIR)/CORFD

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE = -Iinclude


build:
	# arduino-cli compile --fqbn $(BOARD) . --build-path $(BUILD_DIR)

upload: build
	# arduino-cli upload -p $(PORT) --fqbn $(BOARD) --input-dir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

