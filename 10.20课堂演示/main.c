#include <STC89C5xRC.H>

void main(){

	while(1){
		if(P31 == 0){
			//延时10us
			while(P31 == 0);
			//延时10us
			if(P31 == 1){
				P2 = 0x00;
			}
		
		}
	
	
	}


}