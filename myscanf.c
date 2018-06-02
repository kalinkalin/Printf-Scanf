#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void myscanf(char* a,...);
void print_int(int printed);
int myatoi(char* readed, int base);
void print_string(char* printed);
void allocate_string(char* adres,char* readed);


void myscanf(char* a, ...){
      char temp_int;
      int* int_adres;
      char* int_buffer = malloc(1024);
      char temp_char;
      char** string_adres = malloc(1024);
      char* string_buffer = malloc(1024);
      int i = 0;
      void *pointer = &a;

      pointer += sizeof(a);

      int size = 0;

      while(a[size] != '\0'){

        if(a[size] == '%'){

          switch (a[size+1]){
            case 'd':
              read(0,int_buffer,1024);
              int_adres = (int*)(*((int**)pointer));
              *int_adres = myatoi(int_buffer,10);
              pointer += sizeof(int*);
              break;

            case 's':
              read(0,(*(char**)pointer),1024);
              pointer += sizeof(*(char**)pointer);
              break;

            case 'x':
              read(0,int_buffer,1024);
              int_adres = (int*)(*((int*)pointer));
              *int_adres = myatoi(int_buffer,16);
              pointer += sizeof(int*);
              break;

            case 'b':
              read(0,int_buffer,1024);
              int_adres = (int*)(*((int*)pointer));
              *int_adres = myatoi(int_buffer,2);
              pointer += sizeof(int*);
              break;

          }
        }
        size++;
      }
}

int myatoi(char readed[], int base){

  int n = 0;
  int i = 0;

	while (readed[i] != '\0' && (readed[i] >= '0' && readed[i] <= '9') || (readed[i] >= 'a' && readed[i] <= 'f')) {

    if(readed[i] >= 'a' && readed[i] <= 'f') {
      n = n*base + (readed[i] - 'a' + 10);
    }

    else {
      n = n*base + (readed[i] - '0');
    }

    i += 1;
	}

	return n;
}

int main(){
  char* h = malloc(1024);
  int k;
  myscanf("%s %d",h,&k);
  printf("%s %d",h,k);
}
