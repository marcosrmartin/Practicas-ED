CC = g++ -g

OBJ = obj
BIN = bin
SRC = src
INC = include

all:	$(OBJ)/codificar.o	$(OBJ)/imagenES.o	$(OBJ)/imagen.o	$(BIN)/Zoom	$(BIN)/Ocultar	$(BIN)/Revelar	$(BIN)/A_gris	$(BIN)/Contraste	$(BIN)/Icono	$(BIN)/Umbralizar	

$(OBJ)/imagenES.o:	$(SRC)/imagenES.cpp	$(INC)/imagenES.h
	$(CC) -c -o $(OBJ)/imagenES.o -I$(INC) $(SRC)/imagenES.cpp
	
$(OBJ)/imagen.o:	$(SRC)/imagen.cpp	$(INC)/imagen.h	$(INC)/imagenES.h
	$(CC) -c -o $(OBJ)/imagen.o -I$(INC) $(SRC)/imagen.cpp
	
$(OBJ)/codificar.o:	$(SRC)/codificar.cpp	$(INC)/imagenES.h	$(INC)/imagen.h	$(INC)/codificar.h
	$(CC) -c -o $(OBJ)/codificar.o -I$(INC) $(SRC)/codificar.cpp 
	
	
	
$(OBJ)/ocultar.o:	$(SRC)/ocultar.cpp	$(INC)/codificar.h
	$(CC) -c -o $(OBJ)/ocultar.o -I$(INC) $(SRC)/ocultar.cpp
	
$(BIN)/Ocultar:	$(OBJ)/ocultar.o	$(OBJ)/codificar.o
	$(CC) -o $(BIN)/Ocultar $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	
	
	
$(OBJ)/revelar.o:	$(SRC)/revelar.cpp	$(INC)/codificar.h
	$(CC) -c -o $(OBJ)/revelar.o -I$(INC) $(SRC)/revelar.cpp
	
$(BIN)/Revelar:	$(OBJ)/revelar.o	$(OBJ)/codificar.o
	$(CC) -o $(BIN)/Revelar $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	
	
	
$(OBJ)/zoom.o:	$(SRC)/zoom.cpp	$(INC)/imagen.h
	$(CC) -c -o $(OBJ)/zoom.o -I$(INC) $(SRC)/zoom.cpp
	
$(BIN)/Zoom:	$(OBJ)/zoom.o	$(OBJ)/imagen.o	$(OBJ)/imagenES.o
	$(CC) -o $(BIN)/Zoom $(OBJ)/zoom.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	
	
	
$(OBJ)/igris.o:	$(SRC)/igris.cpp	$(INC)/imagen.h
	$(CC) -c -o $(OBJ)/igris.o -I$(INC) $(SRC)/igris.cpp
	
$(BIN)/A_gris:	$(OBJ)/igris.o	$(OBJ)/imagen.o	$(OBJ)/imagenES.o 
	$(CC) -o $(BIN)/A_gris $(OBJ)/igris.o $(OBJ)/imagen.o $(OBJ)/imagenES.o 
	
	

$(OBJ)/umbralizar.o:	$(SRC)/umbralizar.cpp	$(INC)/imagen.h
	$(CC) -c -o $(OBJ)/umbralizar.o -I$(INC) $(SRC)/umbralizar.cpp
	
$(BIN)/Umbralizar:	$(OBJ)/umbralizar.o	$(OBJ)/imagen.o
	$(CC) -o $(BIN)/Umbralizar $(OBJ)/umbralizar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	


$(OBJ)/contraste.o:	$(SRC)/contraste.cpp	$(INC)/imagen.h
	$(CC) -c -o $(OBJ)/contraste.o -I$(INC) $(SRC)/contraste.cpp
	
$(BIN)/Contraste:	$(OBJ)/contraste.o	$(OBJ)/imagen.o
	$(CC) -o $(BIN)/Contraste $(OBJ)/contraste.o $(OBJ)/imagen.o $(OBJ)/imagenES.o



$(OBJ)/icono.o:	$(SRC)/icono.cpp	$(INC)/imagen.h
	$(CC) -c -o $(OBJ)/icono.o -I$(INC) $(SRC)/icono.cpp
	
$(BIN)/Icono:	$(OBJ)/icono.o	$(OBJ)/imagen.o
	$(CC) -o $(BIN)/Icono $(OBJ)/icono.o $(OBJ)/imagen.o $(OBJ)/imagenES.o



clean:
	echo "Limpieza de archivos objeto..."
	rm $(OBJ)/*.o
	
mrproper:	clean
	rm $(BIN)/*
