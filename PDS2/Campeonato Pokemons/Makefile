CC=g++
CFLAGS=-std=c++11 -Wall
TARGET =main

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET} : ${BUILD_DIR}/main.o ${BUILD_DIR}/Campeonato.o ${BUILD_DIR}/Treinador.o ${BUILD_DIR}/Pokemon.o ${BUILD_DIR}/PokemonEletrico.o ${BUILD_DIR}/PokemonAquatico.o ${BUILD_DIR}/PokemonExplosivo.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/Pokemon.o : ${INCLUDE_DIR}/Pokemon.hpp ${SRC_DIR}/Pokemon.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Pokemon.cpp -o ${BUILD_DIR}/Pokemon.o

${BUILD_DIR}/PokemonEletrico.o : ${INCLUDE_DIR}/PokemonEletrico.hpp ${INCLUDE_DIR}/Pokemon.hpp ${SRC_DIR}/PokemonEletrico.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/PokemonEletrico.cpp -o ${BUILD_DIR}/PokemonEletrico.o

${BUILD_DIR}/PokemonAquatico.o : ${INCLUDE_DIR}/PokemonAquatico.hpp ${INCLUDE_DIR}/Pokemon.hpp ${SRC_DIR}/PokemonAquatico.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/PokemonAquatico.cpp -o ${BUILD_DIR}/PokemonAquatico.o

${BUILD_DIR}/PokemonExplosivo.o : ${INCLUDE_DIR}/PokemonExplosivo.hpp ${INCLUDE_DIR}/Pokemon.hpp ${SRC_DIR}/PokemonExplosivo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/PokemonExplosivo.cpp -o ${BUILD_DIR}/PokemonExplosivo.o

${BUILD_DIR}/Treinador.o : ${INCLUDE_DIR}/Treinador.hpp ${INCLUDE_DIR}/PokemonEletrico.hpp ${INCLUDE_DIR}/PokemonAquatico.hpp ${INCLUDE_DIR}/PokemonExplosivo.hpp ${SRC_DIR}/Treinador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Treinador.cpp -o ${BUILD_DIR}/Treinador.o

${BUILD_DIR}/Campeonato.o : ${INCLUDE_DIR}/Campeonato.hpp ${INCLUDE_DIR}/Treinador.hpp ${SRC_DIR}/Campeonato.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Campeonato.cpp -o ${BUILD_DIR}/Campeonato.o

${BUILD_DIR}/main.o : ${INCLUDE_DIR}/avaliacao_basica_pokemon.hpp ${INCLUDE_DIR}/Campeonato.hpp ${SRC_DIR}/main.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o


clean:
	rm -f ${BUILD_DIR}/*