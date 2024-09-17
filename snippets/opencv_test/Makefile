OPENCVINCLUDE=/opt/homebrew/Cellar/opencv/4.10.0_4/include/opencv4/
OPENCVLIBRARY=/opt/homebrew/Cellar/opencv/4.10.0_4/lib/
OPENCV=`pkg-config --cflags --libs opencv4`
BIN=./bin
target=main

all: $(target)

main: main.cpp
	clang++ -o $(BIN)/$@ $< `pkg-config --cflags --libs opencv4`

clean:
	rm -f main
