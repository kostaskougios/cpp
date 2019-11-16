CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		hello.o gpio/Led.o gpio/DHT.o gpio/DHTMeasurement.o

LIBS =		-lwiringPi

TARGET =	hello

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
