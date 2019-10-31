all : one

	#run "make one" in terminal
one: main.cpp Interfaz.cpp Interfaz.h lista_pos_LDE.cpp lista_pos_LDE.h lista_ord_array.cpp lista_ord_array.h lista_index_array.cpp lista_index_array.h algoritmos_lista_pos.cpp algoritmos_lista_pos.h
	g++ main.cpp Interfaz.cpp Interfaz.h lista_pos_LDE.cpp lista_pos_LDE.h lista_ord_array.cpp lista_ord_array.h lista_index_array.cpp lista_index_array.h algoritmos_lista_pos.cpp algoritmos_lista_pos.h -o start
	./start
two: main.cpp Interfaz.cpp Interfaz.h lista_pos_LSE.cpp lista_pos_LSE.h lista_ord_LSE.cpp lista_ord_LSE.h lista_index_LSE.cpp lista_index_LSE.h algoritmos_lista_pos.cpp algoritmos_lista_pos.h
	g++ main.cpp Interfaz.cpp Interfaz.h lista_pos_LSE.cpp lista_pos_LSE.h lista_ord_LSE.cpp lista_ord_LSE.h lista_index_LSE.cpp lista_index_LSE.h algoritmos_lista_pos.cpp algoritmos_lista_pos.h -o start
	./start

three: main.cpp Interfaz.cpp lista_pos_Arreglo.cpp lista_ord_array.cpp lista_index_array.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp
	g++ main.cpp Interfaz.cpp lista_pos_Arreglo.cpp lista_ord_array.cpp lista_index_array.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp -o start 
	./start
