#include<stdio.h>

struct complex
{
    int x;
    int y;
};

struct complex numbers[100];

void division(){
    get_numbers(2);
    int x ,y,z,l;
    struct complex ans;
    z = (numbers[1].x * numbers[1].x )+(numbers[1].y *numbers[1].y);
    ans.x = (numbers[0].x * numbers[1].x) + (numbers[0].y * numbers[1].y);
    ans.x/=z;
    ans.y = (numbers[0].y * numbers[1].x) - (numbers[0].x * numbers[1].y);
    ans.y/= z;
    printf("(%d + i%d)/(%d + i%d) = (%d + i%d)",numbers[0].x,numbers[0].y,numbers[1].x,numbers[1].y,ans.x,ans.y);
}

void menu(){
    printf("\n==========\n1.add\n2.subtract\n3.conjugate\n4.multiply\n5.division\n6.exit\nchoice:");
    int s;
    scanf("%d", &s);

    if(s == 1){
        add();
        menu();}
    else if(s == 2){
        subtract();
        menu();}
    else if(s == 3){
        conjugate();
        menu();}
    else if(s == 4){
        multiply();
        menu();}
    else if (s == 5){
        division();
        menu();
    }

    else if(s == 6){
        exit(0);
    }
    else{ printf("wrong input!");
        menu();}

}

void get_numbers(int n){
    for(int i=0 ; i<n ; i++){     //get n complext numbers from user
        printf("please enter a number like this:x y\n");
        scanf("%d %d", &numbers[i].x, &numbers[i].y);
    }
}

void add(){
    get_numbers(2);
    int x,y;
    x = numbers[0].x + numbers[1].x;
    y = numbers[0].y + numbers[1].y;
    printf("(%d + i%d) + (%d + i%d) = (%d + i%d)\n", numbers[0].x, numbers[0].y , numbers[1].x, numbers[1].y,x,y);
    numbers[2].x = x;
    numbers[2].y = y;
}

void subtract(){
    get_numbers(2);
    int x,y;
    x = numbers[0].x - numbers[1].x;
    y = numbers[0].y - numbers[1].y;
    printf("(%d + i%d) - (%d + i%d) = (%d + i%d)\n",  numbers[0].x, numbers[0].y , numbers[1].x, numbers[1].y,x,y);
    numbers[2].x = x;
    numbers[2].y = y;
}

void conjugate(){
    get_numbers(1);
    int x,y;
    x = numbers[0].x;
    y = numbers[0].y;
    printf("conjugate for (%d + i%d) is (%d - i%d)\n", numbers[0].x, numbers[0].y, x, y);
    numbers[2].x = x;
    numbers[2].y = -1*y;
}

void multiply(){
    get_numbers(2);
    int x,y;
    x = (numbers[0].x * numbers[1].x) - (numbers[0].y * numbers[1].y);
    y = (numbers[0].x * numbers[1].y) + (numbers[0].y * numbers[1].x);
    printf("(%d + i%d) * (%d+ i%d) = (%d + i%d)\n", numbers[0].x, numbers[0].y , numbers[1].x, numbers[1].y,x,y);
    numbers[2].x = x;
    numbers[2].y = y;
}


int main(){
    menu();
    return 0;
}
