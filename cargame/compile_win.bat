g++ -c ./main.cpp -o ./bin/main.o
g++ -c ./libs/cursor.cpp -o ./bin/cursor.o
g++ -c ./libs/game.cpp -o ./bin/game.o
g++ -c ./libs/road.cpp -o ./bin/road.o
g++ ./bin/main.o ./bin/cursor.o ./bin/game.o ./bin/road.o -o ./cargame