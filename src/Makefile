CC=g++
CPPFLAGS=$(shell wx-config --cxxflags --libs) -DOPENHAMMER_VERSION

build: main.o
	@echo "Building"
	$(CC) -o openhammer main.o
	
clean:
	@echo "Cleaning up"
	rm *.o openhammer
