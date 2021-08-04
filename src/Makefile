CXXFLAGS=$(shell wx-config --cxxflags) -DOPENHAMMER_VERSION="std::string(\"v0.0.1a\")"
CXXLIBS=$(shell wx-config --libs)

build: main.o
	@echo "Building"
	$(CXX) $(CXXFLAGS) -o openhammer main.o $(CXXLIBS)
	
clean:
	@echo "Cleaning up"
	rm *.o openhammer
