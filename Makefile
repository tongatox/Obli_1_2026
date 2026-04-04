
# Directorio para guardar los binarios
DIR = bin/

# Objetos necesarios para compilar
OBJS = $(DIR)Main.o $(DIR)Lector.o $(DIR)Prestamo.o $(DIR)Material.o \
	   $(DIR)Libro.o $(DIR)Revista.o $(DIR)DtMaterial.o $(DIR)DtLibro.o \
	   $(DIR)DtRevista.o $(DIR)DtFecha.o


# Creación del directorio bin
all: crear_directorio $(DIR)Main

crear_directorio:
	mkdir -p $(DIR)

$(DIR)Main: $(OBJS)
	g++ -Wall -o $(DIR)Main $(OBJS)

$(DIR)Main.o: Main.cpp
	g++ -Wall -c Main.cpp -o $(DIR)Main.o

$(DIR)Lector.o: Lector.cpp
	g++ -Wall -c Lector.cpp -o $(DIR)Lector.o

$(DIR)Prestamo.o: Prestamo.cpp
	g++ -Wall -c Prestamo.cpp -o $(DIR)Prestamo.o

$(DIR)Material.o: Material.cpp
	g++ -Wall -c Material.cpp -o $(DIR)Material.o

$(DIR)Libro.o: Libro.cpp
	g++ -Wall -c Libro.cpp -o $(DIR)Libro.o

$(DIR)Revista.o: Revista.cpp
	g++ -Wall -c Revista.cpp -o $(DIR)Revista.o

$(DIR)DtMaterial.o: DtMaterial.cpp
	g++ -Wall -c DtMaterial.cpp -o $(DIR)DtMaterial.o

$(DIR)DtLibro.o: DtLibro.cpp
	g++ -Wall -c DtLibro.cpp -o $(DIR)DtLibro.o

$(DIR)DtRevista.o: DtRevista.cpp
	g++ -Wall -c DtRevista.cpp -o $(DIR)DtRevista.o

$(DIR)DtFecha.o: DtFecha.cpp
	g++ -Wall -c DtFecha.cpp -o $(DIR)DtFecha.o

clean:
	rm -rf $(DIR)
	
run: all
	./$(DIR)main