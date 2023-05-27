# A makefile to compile and run a single C++ file without any custom headers.
# Useful for (e.g.) competitive programming, throwing together a quick demo,
# etc.

FILE_NAME=solution
SOURCE_NAME=$(FILE_NAME).cpp

$(FILE_NAME): $(SOURCE_NAME)
	$(CXX) -o "$@" "$^"

run: $(FILE_NAME)
	./$(FILE_NAME)

clean:
	$(RM) $(FILE_NAME)

.PHONY: run clean
