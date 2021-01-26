/* test object (poly, mat)  entry-manipulation
   test factoring algo, thus finding integer roots
   ----------------------------------------------------
   used structures
   - fmpz_poly_t{
        fmpz* coeffs 
        slong length
        ...
     }
   - fmpz_mat_t{
        fmpz **entry
        ...
     }
   - fmpz_poly_factor_t{
        slong num
        fmpz_poly_t *p
        slong exp
        ...
     }
*/

#include "fmpz_poly.h"
#include "fmpz_lll.h"
#include "fmpz_poly_factor.h"

int main(){
   fmpz_poly_t p;
   fmpz_poly_init(p);
   fmpz_poly_set_str(p,"3  19 14 1");

   char* s="x";
   fmpz_poly_print_pretty(p,s); printf("\n");
    
   slong h=3;                          //to choose
   slong k=p->length -1;               //degree of p
   slong hk=h*k;
    
   printf("hk  %ld\n",hk);

    
   slong i, j, v, u, N=35;
   //int CHECK=1;
   long X= (long) (1/sqrt(2)*pow(N,(float) (h-1)/(hk-1))*pow(hk,(float) -1/(hk-1))); 
   printf("X   %ld\n",X);

   fmpz_poly_clear(p);
}