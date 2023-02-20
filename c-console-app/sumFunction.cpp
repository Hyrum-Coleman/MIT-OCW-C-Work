int sumValue = 0;

int sum(int* sumPtr, int sumLen)
{
    if (sumLen == 0) { return sumValue; }
    sumValue += *sumPtr;
    sumPtr++;
    sum(sumPtr, sumLen - 1);
}