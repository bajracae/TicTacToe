CC = g++
exe_file = make
$(exe_file): tictactoe.o helper_function.o
	$(CC) tictactoe.o helper_function.o -o $(exe_file)
tictactoe.o: tictactoe.cpp
	$(CC) -c tictactoe.cpp
helper_function.o: helper_function.cpp
	$(CC) -c helper_function.cpp
clean:
	rm -f *.out *.o $(exe_file)
