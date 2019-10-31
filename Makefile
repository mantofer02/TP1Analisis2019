all : one

	#run "make one" in terminal
one: main.cpp Interfaz.cpp lista_pos_LDE.cpp lista_ord_array.cpp lista_index_array.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp
	g++ main.cpp Interfaz.cpp lista_pos_LDE.cpp lista_ord_array.cpp lista_index_array.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp -o start
	./start
two: main.cpp Interfaz.cpp lista_pos_LSE.cpp lista_ord_LSE.cpp lista_index_LSE.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp
	g++ main.cpp Interfaz.cpp lista_pos_LSE.cpp lista_ord_LSE.cpp lista_index_LSE.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp -o start
	./start

three: main.cpp Interfaz.cpp lista_pos_Arreglo.cpp lista_ord_array.cpp lista_index_array.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp
	g++ main.cpp Interfaz.cpp lista_pos_Arreglo.cpp lista_ord_array.cpp lista_index_array.cpp algoritmos_lista_pos.cpp algoritmos_lista_index.cpp algoritmos_lista_ord.cpp -o start 
	./start
