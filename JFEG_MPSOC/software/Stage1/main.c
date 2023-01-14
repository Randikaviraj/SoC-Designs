#include <stdio.h>
//#include <xtensa/tie/portqueue3i1o.h>
#include "altera_avalon_fifo_regs.h"
#include "altera_avalon_fifo_util.h"
#include "datatype.h"

/* Level shifting to get 8 bit SIGNED values for the data  */
void levelshift (void)
{
	INT16 i,j;

	while(1){
		for(j=0;j<64;j++){
					//xt_iss_profile_disable();
			//i = (INT16)RECV1();
			i = (INT16)altera_avalon_fifo_read_fifo(0x3854,0x38a0);
					//xt_iss_profile_enable();
			//printf(stderr,"Received from FIFO1 %d\n",j);
			i -= 128;
			//SEND(i);
			altera_avalon_fifo_write_fifo(0x3848,0x3800,i);
		}
		
		for(j=0;j<64;j++){
					//xt_iss_profile_disable();
			//i = (INT16)RECV2();
			i = (INT16)altera_avalon_fifo_read_fifo(0x3850,0x3860);
					//xt_iss_profile_enable();
			//fprintf(stderr,"Received from FIFO2 %d\n",j);
			i -= 128;
			//SEND(i);
			altera_avalon_fifo_write_fifo(0x3848,0x3800,i);
		}
		
		for(j=0;j<64;j++){
					//xt_iss_profile_disable();
			//i = (INT16)RECV3();
			i = (INT16)altera_avalon_fifo_read_fifo(0x384c,0x3880);
					//xt_iss_profile_enable();
			//fprintf(stderr,"Received from FIFO3 %d\n",j);
			i -= 128;
			//SEND(i);
			altera_avalon_fifo_write_fifo(0x3848,0x3800,i);
		}
		#pragma flush	//changed by haris - moved it up the dummy instruction
						//resulted in correct number of iterations for this pipeline stage
		
		 //break;
	}
}

int main (void)
{
	levelshift ();
	
	return 0;
}
