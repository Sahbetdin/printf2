#include "test_header.h"

int main()
{
    char *tmp;

    tmp = ft_strdup("2524.23");
    printf("%d\n", ft_atoi(tmp));
    free(tmp);
    printf("%7.3f", 5.542);
//    printf("%  0 9.3f", 56.54562);
//    printf("%               0.50%");

  //  tmp = ft_strchr("diuoxXfFeEgGaAcspn%", 'd');
//    printf("%p", tmp);

    return (0);
}