# include "fmpz_poly.h"
# include "fmpz_lll.h"

int main(){
    fmpz_lll_t fl;
    fmpz_poly_t x , y, z ;
    char* s="x";
    fmpz_mat_t M;
    fmpz_mat_t N;
    
    //fmpz* coeff;

    fmpz_lll_context_init_default(fl);
    fmpz_poly_init ( x );
    fmpz_poly_init ( y );
    fmpz_poly_init (z);
    //fmpz_poly_set_coeff_ui (x , 3 , 5);
    //fmpz_poly_set_coeff_si (x , 0 , -1);
    printf("%d \n", fmpz_poly_set_str(z,"3  1 1 1"));
    //coeff = fmpz_mat_entry(M,0,0)
    fmpz_poly_set_str(x,"3  -1 0 2");
    fmpz_poly_set_str(y,"3  3 5 6");

    //fmpz_poly_mul (y , x , x );
    fmpz_poly_print ( x ); printf ( "\n" );
    fmpz_poly_print ( y ); printf ( "\n" );

    fmpz_poly_print_pretty ( z,s ); printf ( "\n" );
    

    fmpz_mat_init(M,3,3); fmpz_mat_init(N,3,3);
    //fmpz_mat_zero(M);
    //fmpz_mat_print(M); printf ( "\n" );

    //*fmpz_mat_entry(M,0,0)=2;
    //fmpz_set_d(fmpz_mat_entry(M,0,0),3);
    //*fmpz_mat_entry(M,0,0)=*fmpz_poly_get_coeff_ptr(z, 1);
    //for (int i=0; i<6; i++){
    //    fmpz_set_d(fmpz_mat_entry(M,i,i),*fmpz_poly_get_coeff_ptr(z, i));
    //}
    for (int i=0; i<3; i++)
        fmpz_set_d(fmpz_mat_entry(M,0,i),*fmpz_poly_get_coeff_ptr(z, i));
    for (int i=0; i<3; i++)
        fmpz_set_d(fmpz_mat_entry(M,1,i),*fmpz_poly_get_coeff_ptr(x, i));
    for (int i=0; i<3; i++)
        fmpz_set_d(fmpz_mat_entry(M,2,i),*fmpz_poly_get_coeff_ptr(y, i));
    
    fmpz_mat_print(M); printf ( "\n" );

    fmpz_lll(M,N,fl);
    
    //fmpz_print(fmpz_mat_entry(M,0,0)); printf ( "\n" );

    fmpz_mat_print(M); printf ( "\n" );
    fmpz_mat_print(N); printf ( "\n" );
    
    fmpz_poly_clear ( x );
    fmpz_poly_clear ( y );
    fmpz_poly_clear ( z );

    fmpz_mat_clear(M);
    fmpz_mat_clear(N);
    //fmpz_clear(coeff);

}