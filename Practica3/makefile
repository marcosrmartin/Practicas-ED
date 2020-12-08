CC = g++ -g

OBJ = obj
BIN = bin
SRC = src
INC = include

all:	$(OBJ)/pila_max.o	$(BIN)/pila_max

$(OBJ)/pila_max.o:	$(SRC)/usopilas_max.cpp $(SRC)/pila_max_cola.cpp $(SRC)/pila_max_vd.cpp $(INC)/pila_max.h
	$(CC) -c -o $(OBJ)/pila_max.o -I$(INC) -I$(SRC) $(SRC)/usopilas_max.cpp

	
$(BIN)/pila_max:	$(OBJ)/pila_max.o	
	$(CC) -o $(BIN)/pila_max $(OBJ)/pila_max.o
	
doxy:
	doxygen Doxy-file
	
clean:
	echo "Limpieza de archivos objeto..."
	rm $(OBJ)/*.o
	
mrproper:	clean
	rm $(BIN)/*
