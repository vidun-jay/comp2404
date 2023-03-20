OBJ = Album.o AlbumArray.o Client.o Date.o Photo.o PhotoArray.o PhotoGram.o TestControl.o TestView.o main.o

a2: ${OBJ}
	g++ -o a2 ${OBJ}

Date.o: Date.cc
	g++ -c -w Date.cc

Photo.o: Photo.cc
	g++ -c -w Photo.cc

PhotoArray.o: PhotoArray.cc
	g++ -c -w PhotoArray.cc

Album.o: Album.cc
	g++ -c -w Album.cc

AlbumArray.o: AlbumArray.cc
	g++ -c -w AlbumArray.cc

PhotoGram.o: PhotoGram.cc
	g++ -c -w PhotoGram.cc

Client.o: Client.cc
	g++ -c -w Client.cc

TestControl.o: TestControl.cc
	g++ -c -w TestControl.cc

TestView.o: TestView.cc
	g++ -c -w TestView.cc

main.o: main.cc
	g++ -c -w main.cc

clean:
	rm a2 *.o