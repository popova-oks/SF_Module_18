SRC = src/main.cpp src/user.cpp src/message.cpp
TARGET = main
LIB = MyLib
PREFIX = ./build

all: $(TARGET)

$(TARGET): $(SRC) lib
	g++ -o $(PREFIX)/$(TARGET) $(SRC) -L$(PREFIX) -l$(LIB)

lib: user.o message.o
	ar rc $(PREFIX)/lib$(LIB).a $(PREFIX)/user.o $(PREFIX)/message.o

user.o: src/user.cpp
	g++ -o $(PREFIX)/user.o src/user.cpp -c

message.o: src/message.cpp
	g++ -o $(PREFIX)/message.o src/message.cpp -c

clean:
	rm -rf $(PREFIX)/*.o $(PREFIX)/*.a $(PREFIX)/$(TARGET)

install: $(TARGET)
	install $(PREFIX)/$(TARGET) ./

uninstall:
	rm -rf $(TARGET)
