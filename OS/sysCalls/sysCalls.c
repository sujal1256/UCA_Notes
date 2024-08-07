// Standard library for I/O operations
#include <stdio.h>

#include <string.h>

// Used to work with file descriptors have function
// close and open to return file descriptor
#include <fcntl.h>

// Used to control the behaviour of a file descriptor returned from open function
#include <unistd.h>

int open_file(char file[]){
	// opens the file and returns a file descriptor as a status of the file
	// O_RDONLY stands for read-only mode of the file
	int fd = open(file, O_RDONLY);

	// fd is -1 if there is some error reading the file
	if(fd == -1){
		perror("Error in opening the file");
	}
	// close(fd);	
	return fd;
}
void read_file(char file[]){     
	
	int fd = open_file(file);
	if(fd == -1) return;

	// Stores the content of the file in this char 	
	char buffer[1000];
	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);

	if(bytesRead == -1){
		perror("read");
		return;
	}
	// printf("%ld",bytesRead);
	buffer[bytesRead] = '\0';
	printf("Read %zd bytes: %s\n", bytesRead, buffer);
	close(fd);
	// printf("%d",fcntl(fd, F_GETFD));
    }
void create_file(){
	int fd = open("newFile.txt",O_WRONLY +, 0644);
	if(fd == -1){
		perror("There is an error in creating a file");
		return;
	}
	char content[100] = "Hello";
	//printf("Enter the content: ");
	// 99 will limit the content to size 99
	//scanf("%s",content);
	//getline(&content, &size, stdin);
	content[strlen(content)] = '\0';

	ssize_t bytesWritten = write(fd, content, strlen(content));
	if(bytesWritten == -1) {
		perror("Error in writing the file");
		close(fd);
		return;
	}

	printf("\nnewFile.txt is now written\n%s\n",content);
	//read_file("newFile.txt");
	close(fd);


}
int main(){
	create_file();
	return 0;
}
