#include <stdio.h>

void read_input1(void){
    char input[256], name[256];
    int age;

    printf("What is your name, user?\n");
    fgets(input, 256, stdin);
    sscanf(input, "%s", name);

    printf("Hello, %s. How old are you?\n", name);

    while(1){
        fgets(input, 256, stdin);

        if(sscanf(input, "%d", &age) == 1) break;

        printf("I don't recognise that as an age - try again!\n");
    }

    printf("Well, %s, you look young for %d...\n", name, age);
}

void read_input(void){
    char input[256];
    int age;

    printf("What is your name, user?\n");
    scanf("%s", input);

    printf("Hello, %s. How old are you?\n", input);
    scanf("%d", &age);

    printf("Well, %s, you look young for %d...\n", input, age);
}

typedef unsigned char MYBYTE;
typedef enum{
    false,
    true
} MYBOOLEAN;

void type_test(void){
    MYBOOLEAN b_var;

    b_var = false;

    if(b_var == true){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
}

void run_all(void){
    //read_input1();
    type_test();
}

