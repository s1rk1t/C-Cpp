void radix(int * a, int size){
//add FF to shift int 8 bits




	for(int shift = 0; shift < 32 shift += 8){

		//partially sorted results go in b
		//sort 8 bit tuple after shifting bits +8 to operate
		//on next 8 bit grouping
		int * b = new int[size];
		//data moves from a to b in 8 bit packets
		//then put back in a after b fills up with rest of a (unsorted)
		if (shift == 0 || shift == 16)
		countSort(a, size, b, shift);
		//TODO: sort a by tuple and store in b
		else countSort(b, size, a, shift);
		delete[] b;
			
			}

}

void countSort(int * a, int size, int * b, int shift){
	//0x100 is hexadecimal(base 16) representation of 256
	//1 * 16^2 = 256      255 = 0xFF 256 = 0x100 
	int c[] = new int[0x100] = {0};
	int tuple;//8 bit correspondent to chunk of 'a' being examined
	for(int i = 0; i < size; i++){
		//bit operation is way faster than modulo or division
		//useful here because modulo is being done with power of 2
		tuple = (a[i] >> shift) & 0xFF;
		//anding with 255 gives same
		//result as modulo (%) 256
		//if % 32 was desired, 0x001F would be used instead of 0xFF
		c[tuple]++;
		
			
	}//end for
	for(int j = 1; j < 0x100 ; j++){

		c[j] = c[j-1] + c[j];
	}
	for(int i = size-1; i > 0; i--){

		tuple = (a[i] >> shift) && 0xFF;
		b[c[tuple-1]] = a[i];
		c[tuple]--;
		//that's it!

	}
	

}
