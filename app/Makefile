CXX = g++

PKG_CFLAGS = $(shell pkg-config --cflags sdl2)
PKG_LDFLAGS = $(shell pkg-config --libs sdl2)

GUI_DIR = gui

CXXFLAGS = -std=c++20 -g -Wformat -Wall -Wextra -I$(GUI_DIR) $(PKG_CFLAGS)
CFLAGS = $(CXXFLAGS)
LDFLAGS = -lstdc++ $(PKG_CFLAGS)
LINUX_GL_LIBS = -lGL
LIBS = $(LINUX_GL_LIBS) -ldl `sdl2-config --libs`


BUILD_DIR = ../build/app
GUI_SRC_DIR = gui
SRC_DIR = .
BIN := $(BUILD_DIR)/CORFD

GUI_SRCS = $(wildcard $(GUI_SRC_DIR)/*.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(GUI_SRCS)
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

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR)

