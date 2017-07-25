CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD
OBJECTS=main.o Item.o Potion.o Gold.o character.o dragon.o Drow.o dwarf.o elf.o Fairy.o Goblin.o Shade.o Troll.o Vampire.o PC.o halfling.o human.o merchant.o orcs.o enemy.o floor.o gameboard.o square.o 
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

clean:
	rm ${OBJECTS}${EXEC}
.PHONY: clean
