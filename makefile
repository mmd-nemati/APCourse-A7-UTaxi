CC := g++ -std=c++11
EXECUTABLE := utaxi.out

OBJECTS := data_reader.o location.o

DEFINES := defines.hpp
UTAXI := code/utaxi
DATA_READER := code/data_reader
LOCATION := code/location

all: ${EXECUTABLE}

${EXECUTABLE}: main.o
	${CC} *.o -o ${EXECUTABLE}

main.o: main.cpp utaxi.o
	${CC} -c main.cpp -o main.o

utaxi.o: ${UTAXI}.cpp ${UTAXI}.hpp ${DEFINES} ${OBJECTS}
	${CC} -c ${UTAXI}.cpp -o utaxi.o

data_reader.o: ${DATA_READER}.cpp ${DATA_READER}.hpp ${DEFINES}
	${CC} -c ${DATA_READER}.cpp -o data_reader.o

location.o: ${LOCATION}.cpp ${LOCATION}.hpp ${DEFINES}
	${CC} -c ${LOCATION}.cpp -o location.o
