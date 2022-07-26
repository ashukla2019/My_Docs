//Check if adjacent bits are set in the binary representation of a number:
//The expression n & (n << 1) or n & (n >> 1) returns true if n contains any 
//pair whose adjacent bits are 1
// Returns true if adjacent bits are set in a binary representation of `n`
bool check(int n) 
{
    return n & (n << 1);
}