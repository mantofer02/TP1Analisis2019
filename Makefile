all : one

	#run "make one" in terminal
one: main.cpp Interfaz.cpp Interfaz.h lista_pos_LDE.cpp lista_pos_LDE.h lista_ord_array.cpp lista_ord_array.h lista_index_array.cpp lista_index_array.h algoritmos_lista_pos.cpp algoritmos_lista_pos.h
	g++ main.cpp Interfaz.cpp Interfaz.h lista_pos_LDE.cpp lista_pos_LDE.h lista_ord_array.cpp lista_ord_array.h lista_index_array.cpp lista_index_array.h algoritmos_lista_pos.cpp algoritmos_lista_pos.h -o start
	./start
two: 
#hacer para las demas permutaciones de listas. 

three: 

