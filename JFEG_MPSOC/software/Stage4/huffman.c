//#include <xtensa/tie/portqueue2i2o.h>
#include "altera_avalon_fifo_regs.h"
#include "altera_avalon_fifo_util.h"
#include <stdio.h>
#include "datatype.h"
//#include "jdatatype.h"
//#include "config.h"
//#include "prototype.h"
#include "huffdata.h"
#include "markdata.h"

#define PUTBITS	\
{	\
	bits_in_next_word = (INT16) (bitindex + numbits - 32);	\
	if (bits_in_next_word < 0)	\
	{	\
		lcode = (lcode << numbits) | data;	\
		bitindex += numbits;	\
	}	\
	else	\
	{	\
		lcode = (lcode << (32 - bitindex)) | (data >> bits_in_next_word);	\
		out = (UINT8)(lcode >> 24); \
		altera_avalon_fifo_write_fifo(0x3888,0x3840,out); \
		if (out == 0xff)	\
			altera_avalon_fifo_write_fifo(0x3888,0x3840,0);	\
		out = (UINT8)(lcode >> 16); \
		altera_avalon_fifo_write_fifo(0x3888,0x3840,out); \
		if (out == 0xff)	\
			altera_avalon_fifo_write_fifo(0x3888,0x3840,0);	\
		out = (UINT8)(lcode >> 8); \
		altera_avalon_fifo_write_fifo(0x3888,0x3840,out); \
		if (out == 0xff)	\
			altera_avalon_fifo_write_fifo(0x3888,0x3840,0);	\
		out = (UINT8) lcode; \
		altera_avalon_fifo_write_fifo(0x3888,0x3840,out); \
		if (out == 0xff)	\
			altera_avalon_fifo_write_fifo(0x3888,0x3840,0);	\
		lcode = data;	\
		bitindex = bits_in_next_word;	\
	}	\
}

// Header for JPEG Encoder

void write_markers (UINT32 image_width, UINT32 image_height)
{
	UINT16 i, header_length;
	UINT8 number_of_components;

	// Start of image marker
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xFF);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xD8);

	// Quantization table marker
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xFF);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xDB);

	// Quantization table length
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x00);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x84);

	// Pq, Tq
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x00);

	// Lqt table
	for (i=0; i<64; i++)
		altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8)altera_avalon_fifo_read_fifo(0x388c,0x3800)); //Lqt [i];

	// Pq, Tq
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x01);

	// Cqt table
	for (i=0; i<64; i++)
		altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8)altera_avalon_fifo_read_fifo(0x388c,0x3800)); //Cqt [i];

	// huffman table(DHT)
	for (i=0; i<210; i++)
	{
		altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) (markerdata [i] >> 8));
		altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) markerdata [i]);
	}

	//if (image_format == FOUR_ZERO_ZERO)
	//	number_of_components = 1;
	//else
		number_of_components = 3;

	// Frame header(SOF)

	// Start of frame marker
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xFF);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xC0);

	header_length = (UINT16) (8 + 3 * number_of_components);

	// Frame header length	
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) (header_length >> 8));
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) header_length);

	// Precision (P)
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x08);

	// image height
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) (image_height >> 8));
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) image_height);

	// image width
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) (image_width >> 8));
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) image_width);

	// Nf
	altera_avalon_fifo_write_fifo(0x3888,0x3840,number_of_components);

	//if (image_format == FOUR_ZERO_ZERO)
	//{
	//	*output_ptr++ = 0x01;
	//	*output_ptr++ = 0x11;
	//	*output_ptr++ = 0x00;
	//}
	//else
	//{
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x01);

		//if (image_format == FOUR_TWO_ZERO)
		//	*output_ptr++ = 0x22;
		//else if (image_format == FOUR_TWO_TWO)
		//	*output_ptr++ = 0x21;
		//else
			altera_avalon_fifo_write_fifo(0x3888,0x3840,0x11);

		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x00);

		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x02);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x11);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x01);

		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x03);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x11);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x01);
	//}

	// Scan header(SOF)

	// Start of scan marker
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xFF);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xDA);

	header_length = (UINT16) (6 + (number_of_components << 1));

	// Scan header length
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) (header_length >> 8));
	altera_avalon_fifo_write_fifo(0x3888,0x3840,(UINT8) header_length);

	// Ns
	altera_avalon_fifo_write_fifo(0x3888,0x3840,number_of_components);

	//if (image_format == FOUR_ZERO_ZERO)
	//{
	//	*output_ptr++ = 0x01;
	//	*output_ptr++ = 0x00;
	//}
	//else
	//{
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x01);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x00);

		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x02);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x11);

		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x03);
		altera_avalon_fifo_write_fifo(0x3888,0x3840,0x11);
	//}

	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x00);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x3F);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0x00);
	
}

UINT32 lcode = 0;
UINT16 bitindex = 0;
INT16 ldc1 = 0, ldc2 = 0, ldc3 = 0;

void huffman (UINT16 component)
{
	UINT16 i;
	UINT16 *DcCodeTable, *DcSizeTable, *AcCodeTable, *AcSizeTable;

	//static INT16 ldc1 = 0, ldc2 = 0, ldc3 = 0;

	INT16 *Temp_Ptr, Coeff, LastDc;
	UINT16 AbsCoeff, HuffCode, HuffSize, RunLength=0, DataSize=0, index;

	INT16 bits_in_next_word;
	UINT16 numbits;
	UINT32 data;
	
	UINT8 out;

	//Temp_Ptr = Temp;
	//Coeff = *Temp_Ptr++;
//xt_iss_profile_disable();
	Coeff = (INT16)altera_avalon_fifo_read_fifo(0x388c,0x3800);
//xt_iss_profile_enable();
	if (component == 1)
	{
		DcCodeTable = luminance_dc_code_table;
		DcSizeTable = luminance_dc_size_table;
		AcCodeTable = luminance_ac_code_table;
		AcSizeTable = luminance_ac_size_table;

		LastDc = ldc1;
		ldc1 = Coeff;
	}
	else
	{
		DcCodeTable = chrominance_dc_code_table;
		DcSizeTable = chrominance_dc_size_table;
		AcCodeTable = chrominance_ac_code_table;
		AcSizeTable = chrominance_ac_size_table;

		if (component == 2)
		{
			LastDc = ldc2;
			ldc2 = Coeff;
		}
		else
		{
			LastDc = ldc3;
			ldc3 = Coeff;
		}
	}

	Coeff -= LastDc;

	AbsCoeff = (Coeff < 0) ? -Coeff-- : Coeff;

	while (AbsCoeff != 0)
	{
		AbsCoeff >>= 1;
		DataSize++;
	}

	HuffCode = DcCodeTable [DataSize];
	HuffSize = DcSizeTable [DataSize];

	Coeff &= (1 << DataSize) - 1;
	data = (HuffCode << DataSize) | Coeff;
	numbits = HuffSize + DataSize;

	PUTBITS

	for (i=63; i>0; i--)
	{//xt_iss_profile_disable();
		//if ((Coeff = *Temp_Ptr++) != 0)
		if ((Coeff = (INT16)altera_avalon_fifo_read_fifo(0x388c,0x3800)) != 0)
		{//xt_iss_profile_enable();
			while (RunLength > 15)
			{
				RunLength -= 16;
				data = AcCodeTable [161];
				numbits = AcSizeTable [161];
				PUTBITS
			}

			AbsCoeff = (Coeff < 0) ? -Coeff-- : Coeff;

			if (AbsCoeff >> 8 == 0)
				DataSize = bitsize [AbsCoeff];
			else
				DataSize = bitsize [AbsCoeff >> 8] + 8;

			index = RunLength * 10 + DataSize;
			HuffCode = AcCodeTable [index];
			HuffSize = AcSizeTable [index];

			Coeff &= (1 << DataSize) - 1;
			data = (HuffCode << DataSize) | Coeff;
			numbits = HuffSize + DataSize;

			PUTBITS
			RunLength = 0;
		}
		else
			RunLength++;
	}
//xt_iss_profile_enable();
	if (RunLength != 0)
	{
		data = AcCodeTable [0];
		numbits = AcSizeTable [0];
		PUTBITS
	}

}

/* For bit Stuffing and EOI marker */
void close_bitstream (void)
{
	UINT16 i, count;
	UINT8 *ptr;

	UINT8 out;

	if (bitindex > 0)
	{
		lcode <<= (32 - bitindex);
		count = (bitindex + 7) >> 3;

		ptr = (UINT8 *) &lcode + 3;

		for (i=count; i>0; i--)
		{
			out = *ptr--;
			altera_avalon_fifo_write_fifo(0x3888,0x3840,out);
			if (out == 0xff)
				altera_avalon_fifo_write_fifo(0x3888,0x3840,0);
		}
	}

	// End of image marker
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xFF);
	altera_avalon_fifo_write_fifo(0x3888,0x3840,0xD9);

}

int main(void){
	//RESET_DONE();//xt_iss_profile_disable();

  while(1){

	lcode = 0;
	bitindex = 0;
	ldc1 = 0; ldc2 = 0; ldc3 = 0;

	// UINT32 width  = (UINT32)RECV1();
	// UINT32 height = (UINT32)RECV1();
	// UINT32 count  = (UINT32)RECV1();
	UINT32 width  = (UINT32)altera_avalon_fifo_read_fifo(0x3890,0x3820E);
	UINT32 height = (UINT32)altera_avalon_fifo_read_fifo(0x3890,0x3820E);
	UINT32 count  = (UINT32)altera_avalon_fifo_read_fifo(0x3890,0x3820E);
	//xt_iss_profile_enable();
	//fprintf(stderr,"total macroblocks: %d\n",count);
	write_markers (width,height);
	
	for(; count>0; count--){
		huffman (1);
		huffman (2);
		huffman (3);
	//	#pragma flush //added by haris
	
	}
	//fprintf(stderr,"Closing bitstream\n");
	close_bitstream();
	//#pragma flush
	//SET_DONE();
	altera_avalon_fifo_write_fifo(0x3888,0x3840,1);
	break;

  }

	printf("\n Finished !\n");
	return 0;
}
