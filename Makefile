TARGET = test.exe
OBJS = main.o  system.o 
CC = g++
#CFLAGS = -c -Wall -g -std=c++11
#LFLAGS = -Wall -g
CFLAGS = -c -Wall -O3 -DNDEBUG -std=c++11
LFLAGS = -Wall  -O3 -DNDEBUG

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS)  $(OBJS) -o $(TARGET)

particle.o: particle.cpp particle.h

system.o: system.cpp system.h
	$(CC) $(CFLAGS) system.cpp


main.o: main.cpp  system.h 
	$(CC) $(CFLAGS) main.cpp


.PHONY: clean
clean:
	rm -f  $(OBJS) $(TARGET) 

.PHONY: cleanObject
cleanObject:
	rm -f  $(OBJS)

