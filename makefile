CC := g++ -std=c++11
EXECUTABLE := utaxi.out

BUILD_DIR := build

INTERFACE_ADDTIONAL_OBJECTS :=  ${BUILD_DIR}/database.o ${BUILD_DIR}/myserver.o ${BUILD_DIR}/html_maker.o ${BUILD_DIR}/handlers.o ${BUILD_DIR}/server_lists.o
DATABASE_OBJECTS := ${BUILD_DIR}/general.o ${BUILD_DIR}/data_reader.o ${BUILD_DIR}/location.o ${BUILD_DIR}/member.o ${BUILD_DIR}/passenger.o ${BUILD_DIR}/driver.o ${BUILD_DIR}/trip.o
APHTTP_OBJECTS := ${BUILD_DIR}/response.o ${BUILD_DIR}/utilities.o ${BUILD_DIR}/route.o ${BUILD_DIR}/request.o ${BUILD_DIR}/server.o ${BUILD_DIR}/template_parser.o
ALL_OBJECTS := ${BUILD_DIR}/interface.o ${BUILD_DIR}/utaxi.o ${BUILD_DIR}/main.o ${INTERFACE_ADDTIONAL_OBJECTS} ${DATABASE_OBJECTS} ${APHTTP_OBJECTS}

#------application------#
MAIN = main
DEFINES := defines.hpp
INTERFACE := code/interface
UTAXI := code/utaxi

#------backend------#
DATABASE := code/database
GENERAL := code/general
DATA_READER := code/data_reader
LOCATION := code/location
MEMBER := code/member
PASSENGER := code/passenger
DRIVER := code/driver
TRIP := code/trip

#------frontend to backend------#
HTML_MAKER := code/html_maker
HANDLERS := code/handlers
SERVER_LISTS := code/server_lists
MYSERVER = code/myserver

#------aphttp------#
RESPONSE := utils/response
UTILITIES := utils/utilities
REQUEST := utils/request
TEMPLATE_PARSER := utils/template_parser
INCLUDE = utils/include

SERVER = server/server
ROUTE = server/route


all: ${BUILD_DIR} ${EXECUTABLE}

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${EXECUTABLE}: ${ALL_OBJECTS}
	${CC} ${ALL_OBJECTS} -o ${EXECUTABLE}

${BUILD_DIR}/main.o: ${INTERFACE}.hpp ${SERVER}.hpp ${BUILD_DIR}/interface.o ${MAIN}.cpp
	${CC} -c ${MAIN}.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/interface.o: ${INTERFACE}.hpp ${INTERFACE}.cpp ${APHTTP_OBJECTS} ${INTERFACE_ADDTIONAL_OBJECTS} ${DEFINES}
	${CC} -c ${INTERFACE}.cpp -o ${BUILD_DIR}/interface.o

${BUILD_DIR}/myserver.o: ${MYSERVER}.cpp ${MYSERVER}.hpp
	${CC} -c ${MYSERVER}.cpp -o ${BUILD_DIR}/myserver.o

${BUILD_DIR}/html_maker.o: ${HTML_MAKER}.hpp ${HTML_MAKER}.cpp
	${CC} -c ${HTML_MAKER}.cpp -o ${BUILD_DIR}/html_maker.o

${BUILD_DIR}/handlers.o: ${HANDLERS}.cpp ${HANDLERS}.hpp
	${CC} -c ${HANDLERS}.cpp -o ${BUILD_DIR}/handlers.o

${BUILD_DIR}/server_lists.o: ${INTERFACE}.hpp code/server_lists.cpp
	${CC} -c code/server_lists.cpp -o ${BUILD_DIR}/server_lists.o	

${BUILD_DIR}/utaxi.o: ${UTAXI}.cpp ${UTAXI}.hpp ${DEFINES}
	${CC} -c ${UTAXI}.cpp -o ${BUILD_DIR}/utaxi.o

${BUILD_DIR}/database.o: ${DATABASE}.cpp ${DATABASE}.hpp ${DATABASE_OBJECTS} ${DEFINES}
	${CC} -c ${DATABASE}.cpp -o ${BUILD_DIR}/database.o

${BUILD_DIR}/general.o: ${LOCATION}.hpp ${GENERAL}.cpp ${GENERAL}.hpp ${DEFINES}
	${CC} -c ${GENERAL}.cpp -o ${BUILD_DIR}/general.o

${BUILD_DIR}/data_reader.o: ${DATA_READER}.cpp ${DATA_READER}.hpp ${DEFINES}
	${CC} -c ${DATA_READER}.cpp -o ${BUILD_DIR}/data_reader.o

${BUILD_DIR}/location.o: ${GENERAL}.hpp ${LOCATION}.cpp ${LOCATION}.hpp ${DEFINES}
	${CC} -c ${LOCATION}.cpp -o ${BUILD_DIR}/location.o

${BUILD_DIR}/member.o: ${MEMBER}.cpp ${MEMBER}.hpp ${DEFINES}
	${CC} -c ${MEMBER}.cpp -o ${BUILD_DIR}/member.o

${BUILD_DIR}/passenger.o: ${MEMBER}.hpp ${PASSENGER}.cpp ${PASSENGER}.hpp ${DEFINES}
	${CC} -c ${PASSENGER}.cpp -o ${BUILD_DIR}/passenger.o

${BUILD_DIR}/driver.o: ${MEMBER}.hpp ${DRIVER}.cpp ${DRIVER}.hpp ${DEFINES}
	${CC} -c ${DRIVER}.cpp -o ${BUILD_DIR}/driver.o

${BUILD_DIR}/trip.o: ${TRIP}.cpp ${TRIP}.hpp ${DEFINES}
	${CC} -c ${TRIP}.cpp -o ${BUILD_DIR}/trip.o
#------------------------------------------------------------------------------------------------------------------------------------------------#

${BUILD_DIR}/response.o: ${RESPONSE}.hpp ${RESPONSE}.cpp ${INCLUDE}.hpp
	${CC} -c ${RESPONSE}.cpp -o ${BUILD_DIR}/response.o

${BUILD_DIR}/request.o: ${REQUEST}.cpp ${REQUEST}.hpp ${INCLUDE}.hpp ${UTILITIES}.hpp
	${CC} -c ${REQUEST}.cpp -o ${BUILD_DIR}/request.o

${BUILD_DIR}/utilities.o: ${UTILITIES}.cpp ${UTILITIES}.hpp
	${CC} -c ${UTILITIES}.cpp -o ${BUILD_DIR}/utilities.o

${BUILD_DIR}/server.o: ${SERVER}.cpp ${SERVER}.hpp ${ROUTE}.hpp ${UTILITIES}.hpp ${RESPONSE}.hpp ${REQUEST}.hpp ${INCLUDE}.hpp ${TEMPLATE_PARSER}.hpp ${TEMPLATE_PARSER}.cpp
	${CC} -c ${SERVER}.cpp -o ${BUILD_DIR}/server.o

${BUILD_DIR}/route.o: ${ROUTE}.cpp ${ROUTE}.hpp ${UTILITIES}.hpp ${RESPONSE}.hpp ${REQUEST}.hpp ${INCLUDE}.hpp
	${CC} -c ${ROUTE}.cpp -o ${BUILD_DIR}/route.o

${BUILD_DIR}/template_parser.o: ${TEMPLATE_PARSER}.cpp ${TEMPLATE_PARSER}.hpp ${REQUEST}.cpp ${REQUEST}.hpp ${UTILITIES}.hpp ${UTILITIES}.cpp
	${CC} -c ${TEMPLATE_PARSER}.cpp -o ${BUILD_DIR}/template_parser.o

.PHONY: clean
clean:
	rm -r ${BUILD_DIR}/*.o