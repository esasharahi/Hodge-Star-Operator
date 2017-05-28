#include<stdio.h>
/*
 * esasharaahi@gmail.com
 * Asume that the Riemannian metric is (locally) orrthomormal (No important really).
 * In such case, Letting 'set_len' as Manidold dimension, 'subset_len' as form dimension
 * and array 'form_arr[]' as bases presented in the form, 
 * come to calculate *(form); whereas '*' denote the Hodge star isomorphism. 
 * Default examle is \( *(\mathrm{d}x^2 \wedge \mathrm{d}x^3 \wedge \mathrm{d}x^4) =
 *  - \mathrm{d}x^1 \wedge \mathrm{d}x^5 \).
 * Great thanks form Mehrdad Dolatkhah (Expert in C & C++); find him: http://sunjustice.blog.ir//
*/
int main()
{
	int set_len = 5, subset_len = 3; 
	int form_arr[100] = {2, 3, 4};
    int i = 0, j = 0, k = 0, tmp, reserver, sign = 1;
    int vol[set_len] = {0}, united[100];
    int complement = set_len - subset_len;
    int complement_arr[complement];
    
	for (i = 0; i < subset_len; i++) {
	vol[form_arr[i] - 1] = 1;
		}
	for (int i = 1; i < set_len + 1; i++) {
		if (!vol[i - 1])
		complement_arr[j++] = i;
		}

    for(i = 0; i<subset_len; i++){
        united[k] = form_arr[i];
        k++;
		}
    
    for(i = 0; i<complement; i++){
        tmp = 1;
        for (j=0; j<subset_len; j++) {
            if (complement_arr[i] == form_arr[j]) {
                tmp = 0;
                break;
				}
			}
        
        if (tmp) {
            united[k] = complement_arr[i];
            k++;
			}
		}  
        for (int i = 0; i < set_len; i++) {
        for (int j = i + 1; j < set_len; j++) {
			if (united[i] > united[j]) {
                reserver =  united[i];
                united[i] = united[j];
                united[j] = reserver;
                sign *= -1;
				}
			}
		}
		
	printf("Bases: ");
    for (int i = 0; i < complement; i++) {
		printf("%d ", complement_arr[i]);
		}
	printf("\nSign: ");
	printf("%d", sign);
    return 0;
}
