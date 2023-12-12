CC=g++
CFLAGS=-std=c++11 -Wall
TARGET =vpl_execution

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
ENTIDADES_DIR = ./entidades


all: ${TARGET}

${TARGET} : ${BUILD_DIR}/main.o  ${BUILD_DIR}/Personagem.o ${BUILD_DIR}/Heroi.o ${BUILD_DIR}/Vilao.o 
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}

${BUILD_DIR}/main.o : ${SRC_DIR}/main.cpp ${INCLUDE_DIR}/Heroi.hpp ${INCLUDE_DIR}/Vilao.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Vilao.o : ${SRC_DIR}/${ENTIDADES_DIR}/Vilao.cpp ${INCLUDE_DIR}/Vilao.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/${ENTIDADES_DIR}/Vilao.cpp -o ${BUILD_DIR}/Vilao.o

${BUILD_DIR}/Heroi.o : ${SRC_DIR}/${ENTIDADES_DIR}/Heroi.cpp ${INCLUDE_DIR}/Heroi.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/${ENTIDADES_DIR}/Heroi.cpp -o ${BUILD_DIR}/Heroi.o

${BUILD_DIR}/Personagem.o : ${SRC_DIR}/${ENTIDADES_DIR}/Personagem.cpp ${INCLUDE_DIR}/Personagem.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/${ENTIDADES_DIR}/Personagem.cpp -o ${BUILD_DIR}/Personagem.o

clear :
	rm -f ${BUILD_DIR}/*