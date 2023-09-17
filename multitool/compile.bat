g++ -c ./main.cpp -o ./bin/main.o
g++ -c ./calculator.cpp -o ./bin/calculator.o
g++ ./bin/main.o ./bin/calculator.o -o ./bin/program