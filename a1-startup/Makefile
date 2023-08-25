
##
 # startup code provided by Paul Miller for COSC1114 - Operating Systems
 # Principles
 ##

# provide make targets here to build the two programs 

cxx = g++
flags = -Wall -Werror -std=c++20
LDFLAGS = -lpthread

all: copier mtcopier

copier: copier_files/main.o copier_files/reader.o copier_files/writer.o
	$(cxx) $(flags) -o copier copier_files/main.o copier_files/reader.o copier_files/writer.o $(LDFLAGS)

copier_files/main.o: copier_files/main.cpp copier_files/reader.h copier_files/writer.h 
	$(cxx) $(flags) -c copier_files/main.cpp $(LDFLAGS)

copier_files/reader.o: copier_files/reader.cpp copier_files/reader.h
	$(cxx) $(flags) -c copier_files/reader.cpp $(LDFLAGS)

copier_files/writer.o: copier_files/writer.cpp copier_files/writer.h
	$(cxx) $(flags) -c single/writer.cpp -o single/writer.o $(LDFLAGS)

mtcopier: mtcopier_files/main.o mtcopier_files/reader.o mtcopier_files/writer.o
	$(cxx) $(flags) -o mtcopier mtcopier_files/main.o mtcopier_files/reader.o mtcopier_files/writer.o $(LDFLAGS)

mtcopier_files/main.o: mtcopier_files/main.cpp mtcopier_files/reader.h mtcopier_files/writer.h 
	$(cxx) $(flags) -c mtcopier_files/main.cpp $(LDFLAGS)

mtcopier_files/reader.o: mtcopier_files/reader.cpp mtcopier_files/reader.h 
	$(cxx) $(flags) -c mtcopier_files/reader.cpp $(LDFLAGS)

mtcopier_files/writer.o: mtcopier_files/writer.cpp mtcopier_files/writer.h
	$(cxx) $(flags) -c multi/writer.cpp -o multi/writer.o $(LDFLAGS)

clean:
	rm -f *.o copier
	rm -f *.o mtcopier