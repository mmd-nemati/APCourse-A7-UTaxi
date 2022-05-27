CC := g++ -std=c++11
EXECUTABLE := utaxi.out

UTAXI_ADDTIONAL_OBJECTS :=  database.o input_control.o output_control.o
DATABASE_OBJECTS := general.o data_reader.o location.o member.o passenger.o driver.o trip.o

DEFINES := defines.hpp
UTAXI := code/utaxi
DATABASE := code/database
GENERAL := code/general
DATA_READER := code/data_reader
LOCATION := code/location

MEMBER := code/member
PASSENGER := code/passenger
DRIVER := code/driver

TRIP := code/trip

INPUT_CONTROL := code/input_control
OUTPUT_CONTROL := code/output_control

all: ${EXECUTABLE}

${EXECUTABLE}: main.o
	${CC} *.o -o ${EXECUTABLE}

main.o: main.cpp utaxi.o
	${CC} -c main.cpp -o main.o

utaxi.o: ${UTAXI}.cpp ${UTAXI}.hpp ${UTAXI_ADDTIONAL_OBJECTS} ${DEFINES}
	${CC} -c ${UTAXI}.cpp -o utaxi.o

database.o: ${DATABASE}.cpp ${DATABASE}.hpp ${DATABASE_OBJECTS} ${DEFINES}
	${CC} -c ${DATABASE}.cpp -o database.o

general.o: ${LOCATION}.hpp ${GENERAL}.cpp ${GENERAL}.hpp ${DEFINES}
	${CC} -c ${GENERAL}.cpp -o general.o

data_reader.o: ${DATA_READER}.cpp ${DATA_READER}.hpp ${DEFINES}
	${CC} -c ${DATA_READER}.cpp -o data_reader.o

location.o: ${GENERAL}.hpp ${LOCATION}.cpp ${LOCATION}.hpp ${DEFINES}
	${CC} -c ${LOCATION}.cpp -o location.o

member.o: ${MEMBER}.cpp ${MEMBER}.hpp ${DEFINES}
	${CC} -c ${MEMBER}.cpp -o member.o

passenger.o: ${MEMBER}.hpp ${PASSENGER}.cpp ${PASSENGER}.hpp ${DEFINES}
	${CC} -c ${PASSENGER}.cpp -o passenger.o

driver.o: ${MEMBER}.hpp ${DRIVER}.cpp ${DRIVER}.hpp ${DEFINES}
	${CC} -c ${DRIVER}.cpp -o driver.o

trip.o: ${TRIP}.cpp ${TRIP}.hpp ${DEFINES}
	${CC} -c ${TRIP}.cpp -o trip.o

input_control.o: ${INPUT_CONTROL}.cpp ${INPUT_CONTROL}.hpp ${DEFINES}
	${CC} -c ${INPUT_CONTROL}.cpp -o input_control.o

output_control.o: ${OUTPUT_CONTROL}.cpp ${INPUT_CONTROL}.hpp ${DEFINES}
	${CC} -c ${OUTPUT_CONTROL}.cpp -o output_control.o

.PHONY: clean
clean:
	rm -r *.o