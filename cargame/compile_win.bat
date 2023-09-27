g++ -c ./main.cpp -o ./bin/main.o
g++ -c ./libs/cursor.cpp -o ./bin/cursor.o
g++ ./bin/main.o ./bin/cursor.o -o ./cargame