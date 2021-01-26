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
    //declaration
    fmpz_lll_t fl;
    fmpz_poly_t p, r, x, y;                          
    fmpz_poly_t* q;                     //array q[i]             
    q = (fmpz_poly_t*)malloc(30 * sizeof(fmpz_poly_t*));
    fmpz_mat_t M,U;
    //fmpz_t N;
    fmpz_poly_factor_t fac;             //array factors[] of r
       
    //initialisation
    fmpz_lll_context_init_default(fl);
    fmpz_poly_init(p);
    fmpz_poly_init(r);
    fmpz_poly_init(x);
    fmpz_poly_init(y);
    
    //fmpz_init_set(N, 35);
    fmpz_poly_factor_init(fac);
    
    //setting
    char* s="x";
    fmpz_poly_set_str(p,"3  19 11 1");
    printf("p:  ");fmpz_poly_print_pretty(p,s); printf("\n");
    fmpz_poly_set_str(x,"2  0 1");
    

    //choice
    slong h=2;                          //to choose
    slong k=p->length -1;               //degree of p
    slong hk=h*k;

    

    
    slong i, j, v, u, N=99;//45;//35;
    //int CHECK=1;
    //long X= (long) (1/sqrt(2)*pow(N,(float) (h-1)/(hk-1))*pow(hk,(float) -1/(hk-1))); 
    long X=4;
    printf("hk  h   k   N   %ld %ld %ld %ld\n",hk,h,k,N);
    printf("X   %ld\n",X);

    //fill M
    fmpz_mat_init(M,hk,hk); fmpz_mat_init(U,hk,hk);
    fmpz_mat_zero(M);

    for (i=0; i<hk; i++){
        v=(int) i/k;
        u= i- k*v;
        
        //calcule q[i]=N^{h-1-v}.x^u.p^v
        fmpz_poly_init(q[i]);
        fmpz_poly_pow(q[i], p, v);
        fmpz_poly_pow(y, x, u);
        //fmpz_pow_ui(N, N, h-1-v);
        fmpz_poly_mul(q[i], q[i], y);
        fmpz_poly_scalar_mul_ui(q[i], q[i], pow(N, h-1-v));

        //fmpz_poly_print_pretty(q[i],s); printf("\n");

        //fill M
        for (j=0; j<=i; j++){
            *fmpz_mat_entry(M,i,j)=q[i]->coeffs[j]*pow(X,j);
        }
    }

    //*fmpz_mat_entry(M,0,0)=p->coeffs[0];
    //p->coeffs[0]=1;                               accessible
    //fmpz_poly_print_pretty(p,s); printf("\n");
    
    printf("M:  "); fmpz_mat_print(M); printf ("\n");
    fmpz_lll(M,U,fl);
    printf("M:  "); fmpz_mat_print(M); printf ("\n");
    printf("U:  "); fmpz_mat_print(U); printf ("\n");
    
    for (i=0; i<hk; i++){
        fmpz_poly_set_coeff_si(r,i,*fmpz_mat_entry(M,0,i)/pow(X,i));
    }
    
    printf("r:  "); fmpz_poly_print_pretty(r,s); printf("\n");
    fmpz_poly_factor(fac, r);

    
    //fmpz_poly_factor_print(fac);
    for (i=0; i<fac->num; i++){
        if (fac->p[i].length ==2 && fac->p[i].coeffs[1]==1)
            printf("%ld\n", -fac->p[i].coeffs[0]);
        //else{
            //CHECK=0;
            //break;
        //}    
    }
    //if (CHECK==0 && i==fac->num -1) printf("No integer roots\n");

    fmpz_poly_clear(p);
    fmpz_poly_clear(r);
    fmpz_poly_clear(x);
    fmpz_poly_clear(y);

    for (i=0; i<hk; i++)
        fmpz_poly_clear(q[i]);

    free(q);

    fmpz_mat_clear(M); fmpz_mat_clear(U);
    fmpz_poly_factor_clear(fac);
}