SYSC_INSTALL_PATH=/usr/local/systemc-2.3.4
SYSC_INCLUDE_PATH=${SYSC_INSTALL_PATH}/include
SYSC_LIBRARY_PATH=${SYSC_INSTALL_PATH}/lib-linux64

CC=g++
CPPFLAGS=-I. -I${SYSC_INCLUDE_PATH}
LDFLAGS=-L. -L${SYSC_LIBRARY_PATH} -Wl,-rpath=/usr/local/systemc-2.3.4/lib-linux64 -lsystemc -lm
SRCS=hello.cpp
EXE=hello

all:
	${CC} ${CPPFLAGS} ${LDFLAGS} -o ${EXE} ${SRCS}
	./${EXE}

clean:
	rm -rf ${EXE}

