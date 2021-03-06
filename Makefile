TARGET = test.exe
OBJS = main.o  system.o  particle.o distributions.o
CC = g++
#CFLAGS = -c -Wall -g -std=c++11
#LFLAGS = -Wall -g
CFLAGS = -c -Wall -O3 -DNDEBUG -std=c++11
LFLAGS = -Wall  -O3 -DNDEBUG

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS)  $(OBJS) -o $(TARGET)


distributions.o: distributions.cpp distributions.h
	$(CC) $(CFLAGS) distributions.cpp

particle.o: particle.cpp particle.h
	$(CC) $(CFLAGS) particle.cpp

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

