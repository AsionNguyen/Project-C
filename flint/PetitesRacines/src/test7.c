/* test object (poly, mat)  entry-manipulation
   test factoring algo, thus finding integer roots
   ----------------------------------------------------
   used structures
   - fmpz: slong of 32 bits [-2^31, 2^31]
   - fmpz_poly_t{
        fmpz* coeffs           
        slong length
        ...
     }
     input: length  a0 a1 a2 ... ak
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
#include "string.h"

void Usage(char *cmd){
    fprintf(stderr, "Usage : %s N h X option\n", cmd);   //option = defaut ou test
}

int main(int argc, char **argv){
    if (argc < 4){
        Usage(argv[0]);
        return 0;
    }

    
    //declaration
    fmpz_lll_t fl;                      //option of LLL 
    fmpz_poly_t p, r, x, y;             //polynomials          
    fmpz_poly_t* q;                     //array q[i]             
    q = (fmpz_poly_t*)malloc(100 * sizeof(fmpz_poly_t*));
    fmpz_mat_t M,U;
    fmpz_poly_factor_t fac;             //array factors[] of r 
    
    //initialisation
    fmpz_lll_context_init_default(fl);
    fmpz_poly_init(p);
    fmpz_poly_init(r);
    fmpz_poly_init(x);
    fmpz_poly_init(y);
    fmpz_poly_factor_init(fac);
    
    //setting
    if (strcmp(argv[4], "defaut")==0) 
        fmpz_poly_set_str(p,"3  19 14 1");
    else
        fmpz_poly_read(p);
    
    fmpz_poly_set_str(x,"2  0 1");
    
    char *eptr;
    slong N=strtol(argv[1], &eptr, 10);
    slong h=strtol(argv[2], &eptr, 10);
    slong k=p->length -1;
    slong hk=h*k;
    slong X=strtol(argv[3], &eptr, 10);
    //long X= (long) (1/sqrt(2)*pow(N,(float) (h-1)/(hk-1))*pow(hk,(float) -1/(hk-1)));
    
    //if X=0 take X=X(h) else X < N^{1/k}
    if (X==0)
        X= (long) (1/sqrt(2)*pow(N,(float) (h-1)/(hk-1))*pow(hk,(float) -1/(hk-1))); 
    if (X > pow(N,(float)1/k)){
        printf("Choose X < %ld\n", (slong) pow(N, (float)1/k)+1);
        return 0;
    }

    printf("hk  h   k   N   %lu %lu %lu %lu\n",hk,h,k,N);
    printf("X   %ld\n",X);

    char *s="x";
    printf("p:  ");fmpz_poly_print_pretty(p,s); printf("\n");
    //printf("%lu ok\n", fmpz_poly_evaluate_mod(p,3,N));
    slong i, j, v, u;
    
    //M
    fmpz_mat_init(M,hk,hk); 
    fmpz_mat_init(U,hk,hk);
    fmpz_mat_zero(M);

    for (i=0; i<hk; i++){
        v=(int) i/k;
        u= i- k*v;
        
        //calcule q[i]=N^{h-1-v}.x^u.p^v
        fmpz_poly_init(q[i]);
        fmpz_poly_pow(q[i], p, v);
        fmpz_poly_pow(y, x, u);
        fmpz_poly_mul(q[i], q[i], y);
        fmpz_poly_scalar_mul_ui(q[i], q[i], pow(N, h-1-v));

        printf("q%ld:  ",i); fmpz_poly_print_pretty(q[i],s); printf("\n");

        //fill M
        for (j=0; j<=i; j++){
            *fmpz_mat_entry(M,i,j)=q[i]->coeffs[j]*pow(X,j);
        }
    }
    
    //lll
    printf("M:  "); fmpz_mat_print(M); printf ("\n");
    fmpz_lll(M,U,fl);
    printf("M:  "); fmpz_mat_print(M); printf ("\n");
    //printf("U:  "); fmpz_mat_print(U); printf ("\n");

    //r
    for (i=0; i<hk; i++){
        fmpz_poly_set_coeff_si(r,i,*fmpz_mat_entry(M,0,i)/pow(X,i));
    }
    
    printf("r:  "); fmpz_poly_print_pretty(r,s); printf("\n");
    
    //factor r
    fmpz_poly_factor(fac, r);
    //fmpz_poly_factor_print(fac);
    for (i=0; i<fac->num; i++){
        if (fac->p[i].length ==2 && fac->p[i].coeffs[1]==1 && (fmpz_poly_evaluate_mod(p,-fac->p[i].coeffs[0],N)==0))
            printf("%ld\n", -fac->p[i].coeffs[0]);
    }
                 
    
    //clear
    fmpz_poly_clear(p);
    fmpz_poly_clear(r);
    fmpz_poly_clear(x);
    fmpz_poly_clear(y);

    for (i=0; i<hk; i++)
        fmpz_poly_clear(q[i]);

    free(q);

    fmpz_mat_clear(M); 
    fmpz_mat_clear(U);
    fmpz_poly_factor_clear(fac);
    return 0;
}