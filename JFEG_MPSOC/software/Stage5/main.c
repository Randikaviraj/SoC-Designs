// #include <xtensa/tie/portqueue3i.h>
#include "altera_avalon_fifo_regs.h"
#include "altera_avalon_fifo_util.h"
#include <stdio.h>
#include <time.h>
typedef char			INT8;
typedef unsigned char	UINT8;

int main(void){
	FILE *fptr;
	UINT8 out;
	INT8 filename[50];
	
	while(1){
		out = 0;
		//filename[out] = (INT8)RECV1();
		filename[out] = (INT8)altera_avalon_fifo_read_fifo(0x386c,0x3800);
		if (filename[out]=='\0')
			exit(0);
		while(filename[out]!='\0'){
			out++;
			//filename[out] = (INT8)RECV1();
			filename[out] = (INT8)altera_avalon_fifo_read_fifo(0x386c,0x3800);
		}
		filename[out++] = '.';
		filename[out++] = 'j';
		filename[out++] = 'p';
		filename[out++] = 'g';
		filename[out]   = '\0';

		fptr = fopen (filename, "wb");
		fprintf(stderr,"\nOutput file: %s\n",filename); //Output file added by haris
		
		while(1){
            //out = (UINT8)RECV2();
			out = (UINT8)altera_avalon_fifo_read_fifo(0x3868,0x3840);
            fputc(out, fptr);
            if (out == 0xFF){
                //out = (UINT8)RECV2();
				out = (UINT8)altera_avalon_fifo_read_fifo(0x3868,0x3840);
                fputc(out, fptr);
				//printf("\nWriting: %d\n",out);
                if(out == 0xD9)
                    break;
            }
        //  #pragma flush // added by haris
//			if (!IS_FIFO2EMPTY()){
//				out = (UINT8)RECV2();
//				fputc(out, fptr);
//			}else if(!IS_FIFO3EMPTY()){
//				RECV3();
//				break;
//			}
		}
		
		fclose (fptr);
		printf("\n Done ! %d\n", clock());
		break;
	}

	return 0;
}
