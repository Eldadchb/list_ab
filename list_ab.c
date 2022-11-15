#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USER_INPUT_MSG "Hello and Welcome! Please insert as many charecters as you want. Once you're done, please type Ctrl+D. \n\n"
#define ERROR_MSG "ERROR - Allocation Faild"
#define ROW_SIZE 10

char *get_characters(char *, int *);
int print_characters(char *, int);

int main() {

    char *array;
    char *final_array;
    /* Size means the lenght of the array*/
    int size = 0;
    int *pointer_to_size;
    
    pointer_to_size = &size;  

    printf(USER_INPUT_MSG); 
    
    /* Allocation of memory */
    array = (char*)malloc(sizeof(char));
    
    /* Sets the array using get_characters function and gets back pointer to the final array */
    final_array = get_characters(array,pointer_to_size);
    
    /* Prints the array */
    print_characters(final_array, size);
    
    free(final_array);

    return 0;
}

char *get_characters(char *array, int *pointer_to_size){

    char *temp_pointer; 
    char current_input;
    
    int index = 0;
 
    current_input = getchar();
    
    while (current_input != EOF){

    	array[index] = current_input;

    	index++;
    	
    	current_input = getchar();
	/* Asks for more memory */
    	temp_pointer = (char*)realloc(array, (index+1)*sizeof(char));
	/* If faild, prints an ERROR message and breaks the loop */
    	if (temp_pointer == NULL){		
    		printf(ERROR_MSG);
    		break;
    		
    		}

    	else{
    		array = temp_pointer;
    		
    		}	
    }
    /* Sets size to the final lenght of the array */
    *pointer_to_size = index;
    
    return array;
}


int print_characters(char *array, int size){
    /* This function prints the characters that inserted by the user */
   
    int i;
    int current_len_of_row = 1;
    int alphanum_char = 0;
    
    printf("\n\nThe characters you inserted are:\n\n"); 
    
    for (i=0; i<size ; i++){
    	/* Checks if current char is alpha numeric, if yes, counts it*/
    	if(isalnum(array[i]) != 0){
    	
    		alphanum_char ++;
    	}
    	
    	printf("%c ", array[i]);
    	/* Counts how many chars already printed in order to print each row according to the reqierd size */
	current_len_of_row ++;
	
	if (current_len_of_row == ROW_SIZE){
	
		printf("\n");
		
		current_len_of_row = 1;
	}
    		
    }
    
    printf("\n\nThe sum of the Alpha numeric characters is: %d\n",alphanum_char);
    
    printf("\nThe sum of the total characters is: %d\n",size);
    
    return 0;
}
