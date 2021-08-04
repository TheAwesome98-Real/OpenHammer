CPP=g++
CPPFLAGS=$(shell wx-config --cxxflags --libs) -DOPENHAMMER_VERSION="std::string(\"v0.0.1a\")"

build: main.o
	@echo "Building"
	$(CPP) $(CPPFLAGS) -o openhammer main.o
	
clean:
	@echo "Cleaning up"
	rm *.o openhammer
