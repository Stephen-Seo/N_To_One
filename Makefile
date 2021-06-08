CFLAGS = -Wall -Wextra -Wpedantic
CXXFLAGS = -Wall -Wextra -Wpedantic -Ithird_party/Catch2/single_include/catch2

all: UnitTests

UnitTests: src/n_to_one.o src/tests/test_main.o src/tests/test_n_to_one.o
	$(CXX) $(CXXFLAGS) -o UnitTests $^

.PHONY:

clean:
	rm -f UnitTests
	rm -f src/*.o
	rm -f src/tests/*.o
