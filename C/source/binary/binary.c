/* The following code uses bitwise operators to determine 
if an unsigned integer, x, is a power of two.  If x is a power of two, x is represented in binary
 with only a single bit; therefore, subtraction by one removes that bit and flips all the 
lower-order bits.  The bitwise and <http://www.cprogramming.com/tutorial/bitwise.html> 
 
then effectively checks to see if any bit is the 
same.  If not, then it's a power of two.*/
 
int powerOfTwo(unsigned int x)
{
    return !((x-1) & x);
}