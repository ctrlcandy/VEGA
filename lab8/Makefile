CC=g++ # указываем компилятор
LDFLAGS= # флаги линковщика
CFLAGS=-c -MD # флаги компилятора
SOURCES= # список исходников
OBJECTS=$(SOURCES:.cpp=.o)
TARGET= # имя бинарника

all: $(TARGET)
    
$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp 
	$(CC) $(CFLAGS) $< 

include $(wildcard   *.d)

.PHONY: clean
clean:
	rm -rf *.o *.d $(TARGET)
