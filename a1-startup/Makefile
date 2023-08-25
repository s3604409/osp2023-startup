
##
 # startup code provided by Paul Miller for COSC1114 - Operating Systems
 # Principles
 ##

# provide make targets here to build the two programs 

cxx = g++
flags = -Wall -std=c++20

all: copier mtcopier

copier: copier_files/main.o copier_files/FileReader.o copier_files/FileWriter.o
	$(cxx) $(flags) -o copier copier_files/main.o copier_files/FileReader.o copier_files/FileWriter.o

copier_files/main.o: copier_files/main.cpp copier_files/FileReader.h copier_files/FileWriter.h
	$(cxx) $(flags) -c copier_files/main.cpp

copier_files/FileReader.o: copier_files/FileReader.cpp copier_files/FileReader.h
	$(cxx) $(flags) -c copier_files/FileReader.cpp

copier_files/FileWriter.o: copier_files/FileWriter.cpp copier_files/FileWriter.h
	$(cxx) $(flags) -c

mtcopier: mtcopier_files/main.o mtcopier_files/FileReader.o mtcopier_files/FileWriter.o
	$(cxx) $(flags) -o mtcopier mtcopier_files/main.o mtcopier_files/FileReader.o mtcopier_files/FileWriter.o

mtcopier_files/main.o: mtcopier_files/main.cpp mtcopier_files/FileReader.h mtcopier_files/FileWriter.h
	$(cxx) $(flags) -c mtcopier_files/main.cpp

mtcopier_files/FileReader.o: mtcopier_files/FileReader.cpp mtcopier_files/FileReader.h
	$(cxx) $(flags) -c mtcopier_files/FileReader.cpp

mtcopier_files/FileWriter.o: mtcopier_files/FileWriter.cpp mtcopier_files/FileWriter.h
	$(cxx) $(flags) -c

clean:
	rm -f *.o copier
	rm -f *.o mtcopier