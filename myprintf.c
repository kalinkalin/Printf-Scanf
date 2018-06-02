#include <unistd.h>
#include <stdlib.h>

void myprintf(char* a,...);
void print_int(int printed);
void print_hex(int printed);
void print_bin(int printed);
char* my_itoa(int printed, int base);
void print_string(char* printed);

void myprintf(char* a, ...){

      void *pointer = &a;
      int temp_int;
      char* temp_string;
      pointer += sizeof(char*);

      int size = 0;

      while(a[size] != '\0'){

        if(a[size] == '%'){

          switch (a[size+1]){
            case 'd':
              temp_int = *((int*)pointer);
              print_int(temp_int);
              pointer += sizeof(int);
              break;

            case 's':
              temp_string = *((char**)pointer);
              print_string(temp_string);
              pointer += sizeof(char*);
              break;

            case 'x':
              temp_int = *((int*)pointer);
              print_hex(temp_int);
              pointer += sizeof(int);
              break;

            case 'b':
              temp_int = *((int*)pointer);
              print_bin(temp_int);
              pointer += sizeof(int);
              break;

          }

          size++;
        }

        else{
          write(1,&a[size], sizeof(char));
        }
        size++;
      }
      close(1);
}

void print_string(char* printed){
    int i = 0;

    while(printed[i]!='\0'){
      i++;
    }

    write(1,printed,i);

}

void print_bin(int printed){
  char* to_print = my_itoa(printed,2);
  int i = 0;

  while(to_print[i]!='\0'){
    i++;
  }

  write(1,to_print,i);
}

void print_hex(int printed){
  char* to_print = my_itoa(printed, 16);
  int i = 0;

  while(to_print[i]!='\0'){
    i++;
  }

  write(1,to_print,i);
}

void print_int(int printed){
    char* to_print = my_itoa(printed, 10);
    int i = 0;

    while(to_print[i]!='\0'){
      i++;
    }

    write(1,to_print,i);
}

char * my_itoa(int printed, int base){

      int space = 1;
      char* buffer = malloc(space);
      char digits[16] = "0123456789ABCDEF";
      int i = 0;
      int rest;

      if(printed < 0){
        buffer[i]='-';
        printed = printed * (-1);
        space ++;
        i++;
        buffer = realloc(buffer,space);
      }

      int shift = printed;
      while(shift!=0){
        space++;
        shift /= base;
      }
      buffer = realloc(buffer,space-1);
      space -= 2;

      while(printed != 0){
        buffer[space] = digits[printed%base];
        space--;
        printed /= base;
      }

      return buffer;
}

int main(){
  char* test = "xyz";
  myprintf("%s", test);
}
