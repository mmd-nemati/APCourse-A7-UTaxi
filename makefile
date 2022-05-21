CC := g++ -std=c++11
EXECUTABLE := utaxi.out

OBJECTS := general.o data_reader.o location.o member.o passenger.o driver.o input_control.o

DEFINES := defines.hpp
UTAXI := code/utaxi
GENERAL := code/general
DATA_READER := code/data_reader
LOCATION := code/location

MEMBER := code/member
PASSENGER := code/passenger
DRIVER := code/driver

INPUT_CONTROL := code/input_control

all: ${EXECUTABLE}

${EXECUTABLE}: main.o
	${CC} *.o -o ${EXECUTABLE}

main.o: main.cpp utaxi.o
	${CC} -c main.cpp -o main.o

utaxi.o: ${UTAXI}.cpp ${UTAXI}.hpp ${DEFINES} ${OBJECTS}
	${CC} -c ${UTAXI}.cpp -o utaxi.o

general.o: ${GENERAL}.cpp ${GENERAL}.hpp ${DEFINES}
	${CC} -c ${GENERAL}.cpp -o general.o

data_reader.o: ${DATA_READER}.cpp ${DATA_READER}.hpp ${DEFINES}
	${CC} -c ${DATA_READER}.cpp -o data_reader.o

location.o: ${LOCATION}.cpp ${LOCATION}.hpp ${DEFINES}
	${CC} -c ${LOCATION}.cpp -o location.o

member.o: ${MEMBER}.cpp ${MEMBER}.hpp ${DEFINES}
	${CC} -c ${MEMBER}.cpp -o member.o

passenger.o: ${MEMBER}.hpp ${PASSENGER}.cpp ${PASSENGER}.hpp ${DEFINES}
	${CC} -c ${PASSENGER}.cpp -o passenger.o

driver.o: ${MEMBER}.hpp ${DRIVER}.cpp ${DRIVER}.hpp ${DEFINES}
	${CC} -c ${DRIVER}.cpp -o driver.o

input_control.o: ${INPUT_CONTROL}.cpp ${INPUT_CONTROL}.hpp ${DEFINES}
	${CC} -c ${INPUT_CONTROL}.cpp -o input_control.o

.PHONY: clean
clean:
	rm -r *.o