#include <stdio.h>

volatile unsigned int *req = (unsigned int *) 0x80000000;
volatile unsigned int *ack = (unsigned int *) 0x80000004;

void sync1(){
    *req = 1; while (*ack == 0) ;
}


void sync0(){
    *req = 0; while (*ack == 1) ;
}



int main(){
    volatile  unsigned  int *di = (unsigned int *) 0x80000008;
    volatile  unsigned  int *ot = (unsigned int *) 0x8000000C;


int pulse[120]={-4,-2,0,-4,-6,-4,-2,-4,-6,-6,-4,-4,-6,-6,-2,6,12,8,0,-16,-38,-60,-84,-90,-66,
                       -32,-4,2,-4,8,12,12,10,6,6,6,4,0,0,0,0,0,-2,-4,0,0,0,-2,-2,0,0,-2,-2,-2,-2,0,
                       -2,-4,-2,0,-2,-4,-4,2,0,0,-2,-4,-2,0,0,-2,-4,-2,0,0,-4,-4,-2,-2,-4,-6,-6,-4,-4,
                       8,-10,-8,-6,-6,-8,-12,-10,-8,-8,-10,-12,-10,-8,-8,-10,-10,-8,-6,-6,-8,-8,-4,-2,
                       -4,-4,-4,0,0,-2,-4,-2,-2,0,-4};
int i = 0;
for(i=0; i<120;i++){
	*di = pulse[i];
	sync1();
	i++;
	*di = pulse[i];
	sync0();
}

    sync1();
}
