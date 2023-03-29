#ifndef PYTHON_H
#define PYTHON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/**
 * C module that makes C users' life easier, in the pythonic way.
 * 
 * 2023
*/


//----------------------------------------------


/** Get lenght of an int betterarray object.
 * 
 * int *array = betterarray(15);
 * len(array) -> 15
*/
int len(int n[]);

/** Returns a fresh new betterarray object, which values are copied from another betterarray.*/
int* duplicate_array(int arr[]);

/** Returns the first index of a value in a betterarray object.
 * free_value: the value in the object to consider as unoccupied. When creating a new betterarray, all indexes are always set to 0.
 * 
 * direction: which direction should the array be searched. 
 * 0: counting up
 * 1: counting down
 * 
 * Returns -2 if the array doesn't contain the value at all.
*/
int first_occurence(int arr[], int value, int direction);

/** Returns a new betterarray object starting and ending at a specified index of another betterarray.
*
*from/to_idx - specify on which index should the cut start/end.
*to_idx == -1: Last element. Betterarray objects only.
*/
int* cut(int arr[], int from_idx, int to_idx);

/**Returns the larger number of the two float parametes.*/
int max(int a, int b);

/**Returns the smaller number of the two float parametes.*/
float min_f(float a, float b);

/**Returns the larger number of the two float parametes.*/
float max_f(float a, float b);

/**Returns an int number within a min/max range. Returns the threshold value instead if it exceeds.*/
int clamp(int min, int val, int max);

/**Returns a float number within a min/max range. Returns the threshold value instead if it exceeds.*/
float clamp_f(float min, float val, float max);

/** Fills an array/betterarray object with a certain value.
 * 
 * from/to_idx - where to start/end setting the array.
 * to_idx == -1: Fill to the last element. Betterarray objects only.*/
void set_array(int arr[], int from_idx, int to_idx, int val);

/** Prints a betterarray element using a format const string, in which >index< and >array[index]< are filled:
* 
*format_style 
*0: index, value
*1: value, index
*2: value
*
*from/to_idx - specify on which index should the printing start/end.
*to_idx == -1: Last element. Betterarray objects only.
*
*direction 
*0: counting up
*1: counting down
*/
void printf_array(const char *c, int arr[], int from_idx, int to_idx, int format_style, int direction);

/**An array structure from which you can get its length in C!
 * 
 * Usage:
 * int *array = betterarray(6);
 * array[5] = 8;
 * 
 * Default value for all elements is 0.
 * Do not assign -2147483647 to any element, as it is reserved for our purposes.
 * You don't need to pass the length parameter to your functions anymore, because you can simply get it back using the len() function.
*/
int* betterarray(int length){
    int* ptr;
    length++;
    ptr = (int*) malloc(length * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(-1);
        }
    else{
        //printf("Memory successfully allocated using malloc.\n");
        for(int l = 0; l < length - 1;l++){
            ptr[l] = 0;
        }
        ptr[length - 1] = -2147483647;
        //printf("\narray crated\n");
        return ptr;

}};

/** Get lenght of an int betterarray object.
 * 
 * int *array = betterarray(15);
 * len(array) -> 15
*/
int len(int arr[]){
    int counter = 0;
    while(arr[counter] != -2147483647){
        counter++;
    }
    return counter;
}

/** Merges two int betterarray objects, returning a new concatenated betterarray object.
*/
int* merge_arr(int a[], int b[]){
    int siza = len(a);
    int sizb = len(b);
    int* merged =  betterarray(siza+sizb);
    for(int i = 0; i < siza; i++){
        merged[i] = a[i];
    }
    // q sizea
    for(int i = 0; i < sizb; i++){
        merged[i+siza] = b[i];
    }
    return merged;
}

/**Generates a pseudo random number in a given range.*/
int randint(int from, int to){
    int randum = (rand() % (to - from + 1) + from);
    return randum;
};
void srandtimenull(){
    srand(time(0));
}
/*void print_arr(int arr[]){
    for(int i = 0; i < len(arr); i ++ ){
    printf("\n %d %s%d", i+1,". th element>>> ",arr[i]);
    };
printf("\nLOG: array printing done\n");
};*/

/*
void write_arr(int arr[],int from_index, int to_index){
    for(int g = from_index; g <= to_index; g++){
        int val;
        printf("\n");
        scanf("%d", &val);
        arr[g] = val;
    }
}*/


int* primes(int maximum){
    int* find = betterarray(maximum);

    set_array(find, 2, -1, 1);
    
    float sq = sqrt(maximum);
    for(int i = 2; i <= sq; i++){
            
        if(find[i] == 1) for(int f = i*2; f < maximum; f=f+i) find[f] = 0;
            
    }

    int* listed = betterarray(maximum);

    for(int i = 0; i < maximum; i++){
        if(find[i] == 1){
            listed[first_occurence(listed, 0, 0)] = i;
        }
    }

    int* final = cut(listed, 0, max(0, first_occurence(listed, 0, 0)-1));
    
    free(find); free(listed);
    return final;

}


/** Fills an array/betterarray object with a certain value.
 * 
 * from/to_idx - where to start/end setting the array.
 * to_idx == -1: Fill to the last element. Betterarray objects only.*/
void set_array(int arr[], int from_idx, int to_idx, int val)
{  
    if (to_idx == -1) {to_idx = len(arr)-1;}
  
  for (int i = from_idx; i<= to_idx; i++){
    arr[i] = val;
  }
}

/**Returns the smaller number of the two int parametes.*/
int min(int a, int b){
if (a < b) return a;
else return b;
}

/**Returns the larger number of the two float parametes.*/
int max(int a, int b){
if (a > b) return a;
else return b;
}

/**Returns the smaller number of the two float parametes.*/
float min_f(float a, float b){
if (a < b) return a;
else return b;
}

/**Returns the larger number of the two float parametes.*/
float max_f(float a, float b){
if (a > b) return a;
else return b;
}

/**Returns an int number within a min/max range. Returns the threshold value instead if it exceeds.*/
int clamp(int min, int val, int max){
 if (val < min) return min;
 else if (val > max) return max;
 else return val;
}

/**Returns a float number within a min/max range. Returns the threshold value instead if it exceeds.*/
float clamp_f(float min, float val, float max){
 if (val < min) return min;
 else if (val > max) return max;
 else return val;
}

/**Scans for input to assign to a array/betterarray object.
 * 
 * const char c: Text to print before the input. Use %d for the >index< value. 
 * Should be something along the lines of "Enter the %d. element: "
 * 
 * from/to_idx - where to start/end setting the array. 
 * to_idx == -1: Fill to the last element. Betterarray objects only.
*/
void scanf_array(const char* c, int arr[], int from_idx, int to_idx){
    if (to_idx == -1) {to_idx = len(arr)-1;}
    for (int i=from_idx; i <= to_idx; i++){
        printf(c, i);
        scanf("%d", &arr[i]);
  }



}

/** Prints a betterarray element using a format const string, in which >index< and >array[index]< are filled:
* 
*format_style 
*0: index, value
*1: value, index
*2: value
*
*from/to_idx - specify on which index should the printing start/end.
*to_idx == -1: Last element. Betterarray objects only.
*
*direction 
*0: counting up
*1: counting down
*/
void printf_array(const char *c, int arr[], int from_idx, int to_idx, int format_style, int direction)
{   
    if (to_idx == -1) {to_idx = len(arr)-1;}
    if (direction == 0){

        for (int i=from_idx; i <= to_idx; i++){
            if (format_style == 0) printf(c, i, arr[i]);
            if (format_style == 1) printf(c, arr[i], i);
            if (format_style == 2) printf(c, arr[i]);
        }
    }
    else{
         for (int i=to_idx; i >= from_idx; i--){
            if (format_style == 1) printf(c, i, arr[i]);
            if (format_style == 1) printf(c, arr[i], i);
            if (format_style == 2) printf(c, arr[i]);
        }
    }
}

/**Returns the average value of the sum of all elements in a betterarray object.*/
float avg_array(int arr[]){
    int sum = 0;
    int length = len(arr);
    for (int i = 0; i < length; i++){
        sum = sum + arr[i];
    }
    return sum/length;
}

/** Returns 1 if the value is present within the betterarray object.*/
int in(int arr[], int value){
    for (int i = 0; i<len(arr); i++){
        if (arr[i] == value) return 1;
    }

    return 0;
}

int* sort(int arr[], int direction){
    int* new = duplicate_array(arr);
    int podminka = 1;
    while (podminka == 1){
        podminka = 0;
        for(int l = 0; l < len(arr)-1; l++){

            if((new[l] > new[l+1] && direction == 0) || (new[l] < new[l+1] && direction != 0)){
                podminka = 1;
                int holder = new[l]; //3
                new[l] = new[l+1]; //3
                new[l+1] = holder;
            }

        }

    }
    //printf("\nsorting done");
    return new;
}

/** Returns a new betterarray object starting and ending at a specified index of another betterarray.
*
*from/to_idx - specify on which index should the cut start/end.
*to_idx == -1: Last element. Betterarray objects only.
*/
int* cut(int arr[], int from_idx, int to_idx){
    if (to_idx == -1) {to_idx = len(arr)-1;}
    int* new = betterarray(to_idx - from_idx +1);

    for (int i = from_idx; i <= to_idx; i++){

        new[i - from_idx] = arr[i];
    }
    return new;

}

/** Returns a fresh new betterarray object, which values are copied from another betterarray.*/
int* duplicate_array(int arr[]){
    int length = len(arr);
    int* new = betterarray(length);

    for (int i = 0; i < length; i++) new[i] = arr[i];

    return new;

}

/** Returns the first index of a value in a betterarray object.
 * free_value: the value in the object to consider as unoccupied. When creating a new betterarray, all indexes are always set to 0.
 * 
 * direction: which direction should the array be searched. 
 * 0: counting up
 * 1: counting down
 * 
 * Returns -2 if the array doesn't contain the value at all.
*/
int first_occurence(int arr[], int value, int direction){
    int length = len(arr);
    if (direction == 0){
        for (int i = 0; i < length; i++){
            if (arr[i] == value) return i;
        }
    }
    else{
        for (int i = length-1; i >= 0; i--){
            if (arr[i] == value) return i;
        }
    }
    return -2;
}


#endif
