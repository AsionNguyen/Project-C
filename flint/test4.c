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


# include "fmpz_poly.h"
# include "fmpz_lll.h"
#include "fmpz_poly_factor.h"

int main(){
    fmpz_poly_t p;
    fmpz_mat_t M;
    fmpz_poly_factor_t fac;
    char* s="x";
    slong i;
    int CHECK=1;
    
    //Initialisation
    fmpz_poly_init(p);
    fmpz_mat_init(M,3,3);
    fmpz_poly_factor_init(fac);
    
    //Setting
    fmpz_poly_set_str(p,"3  1 3 2");
    fmpz_mat_zero(M);
    
    //Entry manipulation
    *fmpz_mat_entry(M,0,0)=p->coeffs[0];
    //p->coeffs[0]=1;                               accessible
    fmpz_poly_print_pretty(p,s); printf("\n");
    fmpz_mat_print(M); printf ("\n");

    fmpz_poly_factor(fac, p);

    //fmpz_poly_factor_print(fac);
    for (i=0; i<fac->num; i++){
        if (fac->p[i].length ==2 && fac->p[i].coeffs[1]==1)
            printf("%ld\n", -fac->p[i].coeffs[0]);
        else{
            CHECK=0;
            break;
        }    
    }
    if (CHECK==0) printf("No integer roots\n");
    
    //Clearing
    fmpz_poly_clear(p);
    fmpz_mat_clear(M);
    fmpz_poly_factor_clear(fac);
}
