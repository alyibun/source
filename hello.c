#include <stdio.h>

int main(){

    int i;
	/*
    for(i=0;i<10;i++){
        printf("hello world\n");
    }
	*/
	/*
	i=0;
	while(i<10){
		printf("%d hello world\n",i+1);
		i++;
	}
	*/
	i=0;
loop:
	if(10<=i){
		goto ext_loop;
	}
	printf("i=%d Hello World\n",i+1);
	i++;
	goto loop;
ext_loop:
	
    return 0;
}
