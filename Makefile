CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD
OBJECTS=main.o Item.o Potion.o Gold.o character.o dragon.o Drow.o dwarf.o elf.o enemy.o floor.o gameboard.o Goblin.o halfling.o human.o merchant.o orcs.o PC.o Shade.o square.o Troll.o Vampire.o 
DEPENDS=${OBJECTS:.o=.d}
EXEC=CC3K
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

clean:
	rm ${OBJECTS}${EXEC}
.PHONY: clean
