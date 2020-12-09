#include <ctype.h>


size_t foo(const char *str)
{
    size_t count;
    
    count = 0;
    
    for(const char *tmp = str; *tmp; tmp++)
    {
        if(isupper(*tmp))
        {
            count++;
        }
    }
    
    return count;
}
