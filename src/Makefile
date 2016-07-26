CXX = g++-5 -g
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = cc3k 
OBJECTS = ConcreteDoor.o ConcreteBridgeOld.o ConcreteWallH.o ConcreteWallV.o ConcreteCell.o main.o Character.o ConcreteBA.o ConcreteBD.o ConcreteBridge.o ConcreteChamber.o ConcreteDragon.o ConcreteDwarf.o ConcreteElf.o ConcreteGoblin.o ConcreteGoldStashGuarded.o ConcreteGoldStashNormal.o ConcreteHuman.o ConcreteMerchant.o ConcreteOrc.o ConcretePH.o ConcretePhoenix.o ConcreteRH.o ConcreteStairway.o ConcreteTroll.o ConcreteVampire.o ConcreteWA.o ConcreteWD.o ConcreteWerewolf.o Enemy.o Floor.o Game.o Generator.o GoldStash.o Item.o Layout.o Observer.o Player.o PotAT.o PotDE.o PotHP.o Potion.o RandGen.o Subject.o TextDisplay.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
