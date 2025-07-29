CXX = g++

PKG_CFLAGS = $(shell pkg-config --cflags sdl2)
PKG_LDFLAGS = $(shell pkg-config --libs sdl2)

GUI_DIR = gui
SERIAL_DIR = serial
COMMON_DIR = ../common

CXXFLAGS = -std=c++20 -g -Wformat -Wall -Wextra -I$(GUI_DIR) -I$(SERIAL_DIR) -I$(COMMON_DIR) $(PKG_CFLAGS)
CFLAGS = $(CXXFLAGS)
LDFLAGS = -lstdc++ $(PKG_CFLAGS)
LINUX_GL_LIBS = -lGL
LIBS = $(LINUX_GL_LIBS) -ldl `sdl2-config --libs`


BUILD_DIR = ../build/app
GUI_SRC_DIR = gui
SERIAL_SRC_DIR = serial
COMMON_SRC_DIR = $(COMMON_DIR)
SRC_DIR = .
BIN := $(BUILD_DIR)/CORFD

GUI_SRCS = $(wildcard $(GUI_SRC_DIR)/*.cpp)
COMMON_SRCS = $(wildcard $(COMMON_SRC_DIR)/*.cpp)
SERIAL_SRCS = $(wildcard $(SERIAL_SRC_DIR)/*.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(GUI_SRCS) $(COMMON_SRCS) #$(SERIAL_SRCS)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)
	@echo "Completed Build: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LIBS) -c $< -o $@

$(BUILD_DIR)/%.o: $(GUI_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LIBS) -c $< -o $@

$(BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LIBS) -c $< -o $@

# $(BUILD_DIR)/%.o: $(SERIAL_SRC_DIR)/%.cpp
# 	@mkdir -p $(dir $@)
# 	$(CXX) $(CXXFLAGS) $(LIBS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR)

