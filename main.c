#include "array.h" 
#include <stdlib.h>
#include <stdio.h>



//outputs the array in its  entirety
void output_array(Array *a){//points to Array structure
    for(int i=0; i<a->size; i++){//if size of array is 5 it goes 0,1,2,3,4
        printf("%.2f,", a->data[i]);//prints the number in each array index
    }
    printf("\n");
   

}

//Shift All Elements to the left by 1 val at index 1 become val at index 0 and 0 goes to thend
void shift_array(Array *a){
    printf("\n");
    double num1=a->data[0];
    for(int i=0; i<a->size-1; i++){// cant do size becasue if it reaches the end lets say 5 and tries to get 6 theres nothing there so store val at 0 and manually set last num to first num
        a->data[i]=a->data[i+1];
    }
    a->data[a->size-1]=num1;

}



//average the two elements next to each other and store in new array from data struct in arrah.h
Array *average_adjacent(Array *a){
    Array *newArray = malloc(sizeof(Array));//declares a pointer called newArray
    newArray->size = a->size/2;//points to size like 8 annd divides by 2 so newArray is half the of the origianl array
    newArray->data = malloc(newArray->size * sizeof(double));//creates open space for numbers to the newArray, its till empty no numbers
    for(int i=0; i<newArray->size; i++){
        newArray->data[i]=((a->data[i*2] + a->data[i *2+1])/2);// finds data of old Array at 0 and adds it to data[1] and divides by 2 and stores in newArray data at i
    }
    return newArray;
}

int main(int argc, char *argv[]){
    int size;
    sscanf(argv[1], "%d", &size);// re scans the argv[1] which would be 1024 char and re reads as as an int and stores in size
    if(size<2){//checks to make sure size is above at least 2 or more
        printf("Please give me a larger size above 2.\n");
	return 1;
    }
    Array *a=malloc(sizeof(Array));//creates room for struct
    a->size = size;// makes the size in array struct = size a->size =6 for instance 
    a->data = malloc(size * sizeof(double));//creates the space for the numbers but doesnt fill 
   for(int i=0; i<size; i++){// fills data with numbers 1,2,3,4,5,6,7 etc.. for the size 
       a->data[i]=i+1;
   } 
   printf("Original Array\n"); 
   output_array(a);//calls output 
   printf("Shifted Array");//prints shifted array
   Array *newArray = average_adjacent(a);
   shift_array(a);
   output_array(a);   
   printf("Average Array\n");
   output_array(newArray);
   free(newArray->data);
   free(newArray);
   free(a->data);
   free(a);
   return 0;

      
}

























