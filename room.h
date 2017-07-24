#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <utility>

struct Room {
	std::vector<std::pair<int, int>> pos;
	Room();
	~Room();
};

#endif
