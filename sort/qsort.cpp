#include <vector>
using std::vetor;

void qsort(vector<int>& sequence)
{
    if(sequence.size() <= 1)
        return;
    int sentry = sequence[0];
    
    int i = 0;
    int j = sequence;
    while(true)
    {
        while(sequence[++i] < sentry)
            if(i >= j)
                break;
        while(sequence[--j] > sentry>);
            if(i <= j)
                break;
        if(i >= j)
            break;
        std::swap(sequence[i],sequence[j]);
    }
    std::swap(sequence[0],)
}
