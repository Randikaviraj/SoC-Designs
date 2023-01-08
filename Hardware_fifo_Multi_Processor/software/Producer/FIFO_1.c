/*
 * 	FIFO queue for shared memory communication between niosII processors
 *
 *  	DATE		: 18-08-2016
 *      AUTHOR	: Isuru Nawinne
*
*	Structure of the FIFO:
*	___________________________________________________________________________
*	| 	full	| 	empty	| 	count		|	|	|	|	|	|	|	|	|
*	| 	?	| 	?		| 	?		|	|	|	|	|	|	|	|	|
*	___________________________________________________________________________
*/


#include "FIFO_1.h"


void WRITE_FIFO_1(int *buffer)
{
	// Wait if the fifo is full

	// Write the data to FIFO

	// Update the write pointer

	// Update "count" in shared mem

	// Update the "full?" and "empty?" flags accordingly
	// Set the full flag if FIFO is now full
	// Reset the empty flag if FIFO now has 1 enrty

	/*
	while (IORD_32DIRECT(MEM_BASE,fullp)==1);
	IOWR_32DIRECT(MEM_BASE,writep,*buffer);
	int count = IORD_32DIRECT(MEM_BASE,countp);
	IOWR_32DIRECT(MEM_BASE,countp,count+1);

	if(IORD_32DIRECT(MEM_BASE,countp) == CAPACITY){
		IOWR_32DIRECT(MEM_BASE,fullp,1);
	}else{
		IOWR_32DIRECT(MEM_BASE,fullp,0);
	}

	if(IORD_32DIRECT(MEM_BASE,countp) > 0){
		IOWR_32DIRECT(MEM_BASE,emptyp,0);
	}
	
	writep = writep + UNIT_SIZE;
	if (writep == (CAPACITY*UNIT_SIZE)+STARTP)
	{
		writep = STARTP;
	}

	*/
	altera_avalon_fifo_write_fifo(IN_BASE,CONTROL_BASE,*buffer);
	
}


void READ_FIFO_1(int *buffer)
{
	// Wait if the fifo is empty

	// Read the data

	// Update the read pointer

	// Update "count" in shared mem

	// Update the "full?" and "empty?" flags accordingly
	// Set the empty flag if FIFO is now empty
	// Reset the full flag if FIFO now has 1 enrty less than capacity

	/*
	while (IORD_32DIRECT(MEM_BASE,emptyp) == 1);
	*buffer = IORD_32DIRECT(MEM_BASE,readpp);
	
	
	int count = IORD_32DIRECT(MEM_BASE,countp);
	IOWR_32DIRECT(MEM_BASE,countp,count - 1);

	if(IORD_32DIRECT(MEM_BASE,countp) == 0){
		IOWR_32DIRECT(MEM_BASE,emptyp,1);
	}else{
		IOWR_32DIRECT(MEM_BASE,emptyp,0);
	}

	if(IORD_32DIRECT(MEM_BASE,countp) < CAPACITY){
		IOWR_32DIRECT(MEM_BASE,fullp,0);
	}
	readpp = readpp + UNIT_SIZE;
	if (readpp == (CAPACITY*UNIT_SIZE)+STARTP)
	{
		readpp = STARTP;
	}
	
	*/
	*buffer = altera_avalon_fifo_read_fifo(OUT_BASE,CONTROL_BASE);
}



//Initialization
void FIFO_1_INIT()
{
	/*
	writep = STARTP; // Initially the FIFO is empty, so start writing at the first slot
	readpp  = STARTP;
	fullp   = 0; // SET THIS OFFSET (If there are previous FIFOs in shared memory, use Prev Fifo's STARTP + Prev Fifo's size)
	emptyp   = UNIT_SIZE;
	countp  =  2*UNIT_SIZE;

	// Assigning values for the flags.
	IOWR_32DIRECT(MEM_BASE, fullp, 0);
	IOWR_32DIRECT(MEM_BASE, emptyp, 1); // The fifo is empty at the start
	IOWR_32DIRECT(MEM_BASE, countp, 0); // The fifo is empty at the start

	*/
	altera_avalon_fifo_init(CONTROL_BASE,0x0,ALMOST_EMPTY,ALMOST_FULL);
}
