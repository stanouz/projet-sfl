EXECS_NAME = bin/exec 

#Object Files

##Main files
OBJ_FILES += obj/main.o obj/Game.o  

##Entity
OBJ_FILES += obj/EntityWithoutHP.o obj/EntityWithHP.o obj/Player.o 
OBJ_FILES += obj/Enemy.o obj/UniqueID.o obj/NPC.o obj/Animal.o
##Layers
OBJ_FILES += obj/MapLayer.o obj/CollisionLayer.o obj/SpawnsLayer.o

##Map
OBJ_FILES += obj/Map.o obj/Tileset.o obj/tmxParsing.o 

##Boxes
OBJ_FILES += obj/Box.o obj/SpawnPoint.o

##Managers 
OBJ_FILES += obj/AssetManager.o obj/StateManager.o

##Txt Mode 
OBJ_FILES += obj/StateSplashScreenTxt.o obj/StateMenuTxt.o obj/StateGameTxt.o 
OBJ_FILES += obj/winTxt.o
##SFML Mode
OBJ_FILES += obj/StateSplashScreenSFML.o obj/StateMenuSFML.o obj/StateGameSFML.o  
OBJ_FILES += obj/StatePauseSFML.o obj/StateGameOverSFML.o

## Finite State Machine 
OBJ_FILES += obj/StateBehavior.o obj/EnemyStates.o obj/StateMachine.o obj/AnimalStates.o



#Compilers options
CC = g++
CFLAGS = -Wall -ggdb -std=c++14

INCLUDE_SFML = -I./extern/SFML/include 
LIBS_SFML = -Lextern/SFML/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

COMPILATIONOBJ = $(CC) $(CFLAGS) -c $< -o $@ 

FSM = src/Core/Entity/FiniteStateMachine



all: $(EXECS_NAME)

bin/exec : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML)

#Objects
##Main files
obj/main.o: src/main.cpp src/Core/Game.h
	$(COMPILATIONOBJ)

obj/Game.o : src/Core/Game.cpp src/Core/Game.h src/Core/StateManager/StateManager.h src/txt/StateSplashScreenTxt.h src/SFML/StateSplashScreenSFML.h src/Core/Map/tmxParsing.h src/Core/Map/Map.h src/Core/Entity/Player.h src/Core/Entity/Enemy.h src/Core/Entity/NPC.h src/Core/Entity/Animal.h src/SFML/AssetManager.h src/txt/winTxt.h  
	$(COMPILATIONOBJ)

##Entity

obj/EntityWithoutHP.o : src/Core/Entity/EntityWithoutHP.cpp src/Core/Entity/EntityWithoutHP.h src/Core/Entity/UniqueID.h src/Core/Map/Layers/CollisionLayer.h
	$(COMPILATIONOBJ)

obj/EntityWithHP.o : src/Core/Entity/EntityWithHP.cpp  src/Core/Entity/EntityWithHP.h src/Core/Entity/EntityWithoutHP.h 
	$(COMPILATIONOBJ)

obj/Player.o : src/Core/Entity/Player.cpp src/Core/Entity/Player.h src/Core/Entity/EntityWithHP.h src/Core/Entity/Enemy.h
	$(COMPILATIONOBJ)

obj/Enemy.o : src/Core/Entity/Enemy.cpp  src/Core/Entity/Enemy.h src/Core/Entity/EntityWithHP.h $(FSM)/StateMachine.h $(FSM)/EnemyStates.h
	$(COMPILATIONOBJ)

obj/UniqueID.o : src/Core/Entity/UniqueID.cpp src/Core/Entity/UniqueID.h
	$(COMPILATIONOBJ)

obj/NPC.o : src/Core/Entity/NPC.cpp src/Core/Entity/NPC.h src/Core/Entity/EntityWithoutHP.h  src/Core/Entity/Player.h
	$(COMPILATIONOBJ)

obj/Animal.o : src/Core/Entity/Animal.cpp src/Core/Entity/Animal.h src/Core/Entity/EntityWithoutHP.h $(FSM)/StateMachine.h $(FSM)/AnimalStates.h
	$(COMPILATIONOBJ)

##Layers

obj/MapLayer.o : src/Core/Map/Layers/MapLayer.cpp src/Core/Map/Layers/MapLayer.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/CollisionLayer.o : src/Core/Map/Layers/CollisionLayer.cpp src/Core/Map/Layers/CollisionLayer.h src/Core/Map/Box.h
	$(COMPILATIONOBJ)

obj/SpawnsLayer.o : src/Core/Map/Layers/SpawnsLayer.cpp src/Core/Map/Layers/SpawnsLayer.h src/Core/Map/SpawnPoint.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

##Map
obj/Map.o : src/Core/Map/Map.cpp src/Core/Map/Map.h src/Core/Map/Tileset.h src/Core/Map/tmxParsing.h src/Core/Map/Box.h src/Core/Map/Layers/CollisionLayer.h src/Core/Map/Layers/MapLayer.h
	$(COMPILATIONOBJ)

obj/Tileset.o : src/Core/Map/Tileset.cpp src/Core/Map/Tileset.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/tmxParsing.o: src/Core/Map/tmxParsing.cpp src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

##Boxes
obj/Box.o : src/Core/Map/Box.cpp src/Core/Map/Box.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/SpawnPoint.o : src/Core/Map/SpawnPoint.cpp src/Core/Map/SpawnPoint.h src/Core/Map/Box.h
	$(COMPILATIONOBJ)

##Managers 
obj/AssetManager.o : src/SFML/AssetManager.cpp src/SFML/AssetManager.h 
	$(COMPILATIONOBJ)

obj/StateManager.o : src/Core/StateManager/StateManager.cpp src/Core/StateManager/State.h
	$(COMPILATIONOBJ)

##Txt Mode 
obj/StateSplashScreenTxt.o : src/txt/StateSplashScreenTxt.cpp src/Core/Game.h src/Core/StateManager/State.h src/txt/StateMenuTxt.h
	$(COMPILATIONOBJ)

obj/StateMenuTxt.o : src/txt/StateMenuTxt.cpp src/txt/StateMenuTxt.h src/Core/Game.h src/Core/StateManager/State.h src/txt/StateGameTxt.h
	$(COMPILATIONOBJ)

obj/StateGameTxt.o : src/txt/StateGameTxt.cpp src/txt/winTxt.h src/txt/StateMenuTxt.h src/Core/Game.h src/Core/StateManager/State.h
	$(COMPILATIONOBJ)

obj/winTxt.o : src/txt/winTxt.cpp src/txt/winTxt.h
	$(COMPILATIONOBJ)

##SFML Mode
obj/StateSplashScreenSFML.o : src/SFML/StateSplashScreenSFML.cpp src/Core/Game.h src/Core/StateManager/State.h src/SFML/StateMenuSFML.h
	$(COMPILATIONOBJ)

obj/StateMenuSFML.o : src/SFML/StateMenuSFML.cpp src/Core/Game.h src/Core/StateManager/State.h src/SFML/StateGameSFML.h
	$(COMPILATIONOBJ)

obj/StateGameSFML.o : src/SFML/StateGameSFML.cpp src/SFML/StateGameSFML.h src/Core/Game.h src/Core/StateManager/State.h src/SFML/StateGameOverSFML.h src/SFML/StatePauseSFML.h
	$(COMPILATIONOBJ)

obj/StatePauseSFML.o : src/SFML/StatePauseSFML.cpp src/SFML/StatePauseSFML.h src/Core/Game.h src/Core/StateManager/State.h 
	$(COMPILATIONOBJ)

obj/StateGameOverSFML.o : src/SFML/StateGameOverSFML.cpp src/SFML/StateGameOverSFML.h src/Core/Game.h src/Core/StateManager/State.h src/SFML/StateGameSFML.h 
	$(COMPILATIONOBJ)


##Finite State Machine
obj/StateBehavior.o : $(FSM)/StateBehavior.cpp  $(FSM)/StateBehavior.h src/Core/Entity/Player.h src/Core/Map/Layers/CollisionLayer.h
	$(COMPILATIONOBJ)

obj/EnemyStates.o : $(FSM)/EnemyStates.cpp $(FSM)/EnemyStates.h src/Core/Entity/Enemy.h $(FSM)/StateBehavior.h
	$(COMPILATIONOBJ)

obj/StateMachine.o : $(FSM)/StateMachine.cpp $(FSM)/StateMachine.h $(FSM)/StateBehavior.h src/Core/Entity/Player.h  
	$(COMPILATIONOBJ)

obj/AnimalStates.o : $(FSM)/AnimalStates.cpp $(FSM)/AnimalStates.h src/Core/Entity/Animal.h $(FSM)/StateBehavior.h
	$(COMPILATIONOBJ)


#Others
clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy

valgrind : all
	valgrind --leak-check=yes bin/exec 0 > log.txt 2>&1

