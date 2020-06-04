#include <stdio.h>
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}
int main(){

		unsigned a  = 0;
		float b = 1.0;
		unsigned positive[400];
		unsigned negative[300];
		for (int i = 0 ; i <=128; i++){
			b = 1.0;
			int k = 0;
			while(k <i){
				b*=2.0;
				k++;
			}
			unsigned d = f2u(b);
			positive[i] = d;
			printf("%u,",d);
			//printf("%f\n", b);	
			//printf("%u\n", d);
		}
		printf("\n");
		for ( int i = -1 ; i >= -159; i--){
			b = 1.0;
			int k = 0;
			while ( k > i){
				b*=0.5;
				k--;
			}
			unsigned d = f2u(b);
			int index = -i;
			negative[index] = d;
			printf("%u,", d);
		}
		printf("\n");
		return 0;
}
