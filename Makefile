.PHONY: clean exec mproper
.SUFFIXES:

LIBS = -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window
INCLUDES = -I include/Decorator/ include/Singleton/ include/Strategy/ include/Factory/
STD = -std=c++0x
EXE = Stickman_Project

all: exec clean

exec: main.o AUpgrade.o BlockGround1.o BlockGround2.o BlockGround3.o Cape.o ConcreteFactory.o GameManager.o LevelOne.o LevelTwo.o AFactory.o Menu.o Player.o Shoes.o
	g++ $^ $(INCLUDE) $(LIBS) -o $(EXE)

# MAIN

main.o:
	g++ -c src/main.cpp $(STD) -o $@

# DECORATOR

AUpgrade.o: 
	g++ -c src/Decorator/AUpgrade.cpp $(STD) -o $@

Cape.o: 
	g++ -c src/Decorator/Cape.cpp $(STD) -o $@

Player.o:
	g++ -c src/Decorator/Player.cpp $(STD) -o $@

Shoes.o:
	g++ -c src/Decorator/Shoes.cpp $(STD) -o $@

# FACTORY

BlockGround1.o: 
	g++ -c src/Factory/BlockGround1.cpp $(STD) -o $@

BlockGround2.o: 
	g++ -c src/Factory/BlockGround2.cpp $(STD) -o $@

BlockGround3.o: 
	g++ -c src/Factory/BlockGround3.cpp $(STD) -o $@

ConcreteFactory.o: 
	g++ -c src/Factory/ConcreteFactory.cpp $(STD) -o $@

AFactory.o:
	g++ -c src/Factory/AFactory.cpp $(STD) -o $@

# SINGLETON

GameManager.o: 
	g++ -c src/Singleton/GameManager.cpp $(STD) -o $@

Menu.o: 
	g++ -c src/Singleton/Menu.cpp $(STD) -o $@

# STRATEGY

LevelOne.o: 
	g++ -c src/Strategy/LevelOne.cpp $(STD) -o $@

LevelTwo.o: 
	g++ -c src/Strategy/LevelTwo.cpp $(STD) -o $@
	
clean:
	rm -fr *.o

mproper:
	rm -fr $(EXE)
