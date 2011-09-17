TARGET = meshi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	g++ -o $@ -c $<

$(TARGET): $(OBJS)
	g++ -o $@ $^

clean:
	rm -f $(TARGET) *.o
