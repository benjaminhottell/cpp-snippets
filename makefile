# This makefile is not necessary to build anything. These recipes are just
# entry points for cmake (via CMakeLists.txt)
#
# I have this makefile here because I have a few custom shortcuts in my editor
# that execute makefile recipes from anywhere within the project.

BUILD_DIR=./build

TEST_EXE=$(BUILD_DIR)/cpp-snippets-tests

build $(TEST_EXE):
	mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

run: $(TEST_EXE)
	$(TEST_EXE)

test: run

clean:
	rm -rf $(BUILD_DIR)

.PHONY: build run test clean

