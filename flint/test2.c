# include "fmpz_poly.h"
# include "fmpz_lll.h"

int main(){
    fmpz_lll_t fl;
    fmpz_poly_t x , y, z, t ;
    char* s="x";
    fmpz_mat_t M;
    fmpz_mat_t N;
    int dim=4;
    //fmpz* coeff;

    fmpz_lll_context_init_default(fl);
    fmpz_poly_init ( x );
    fmpz_poly_init ( y );
    fmpz_poly_init (z);
    
    fmpz_poly_init (t);
    //fmpz_poly_set_coeff_ui (x , 3 , 5);
    //fmpz_poly_set_coeff_si (x , 0 , -1);
    printf("%d \n", fmpz_poly_set_str(z,"4  35 0 0 0"));
    //coeff = fmpz_mat_entry(M,0,0)
    fmpz_poly_set_str(x,"4  0 105 0 0");
    fmpz_poly_set_str(y,"4  19 42 9 0");
    fmpz_poly_set_str(t,"4  0 57 126 27");

    //fmpz_poly_mul (y , x , x );
    //fmpz_poly_print ( x ); printf ( "\n" );
    //fmpz_poly_print ( y ); printf ( "\n" );

    fmpz_poly_print_pretty ( z,s ); printf ( "\n" );
    fmpz_poly_print_pretty ( x,s ); printf ( "\n" );
    fmpz_poly_print_pretty ( y,s ); printf ( "\n" );
    fmpz_poly_print_pretty ( t,s ); printf ( "\n" );
    

    fmpz_mat_init(M,dim,dim); fmpz_mat_init(N,dim,dim);
    fmpz_mat_zero(M);
    //fmpz_mat_print(M); printf ( "\n" );

    //*fmpz_mat_entry(M,0,0)=2;
    //fmpz_set_d(fmpz_mat_entry(M,0,0),3);
    //*fmpz_mat_entry(M,0,0)=*fmpz_poly_get_coeff_ptr(z, 1);
    //for (int i=0; i<6; i++){
    //    fmpz_set_d(fmpz_mat_entry(M,i,i),*fmpz_poly_get_coeff_ptr(z, i));
    //}
    for (int i=0; i<1; i++)
        fmpz_set_d(fmpz_mat_entry(M,0,i),*fmpz_poly_get_coeff_ptr(z, i));
    for (int i=0; i<2; i++)
        fmpz_set_d(fmpz_mat_entry(M,1,i),*fmpz_poly_get_coeff_ptr(x, i));
    for (int i=0; i<3; i++)
        fmpz_set_d(fmpz_mat_entry(M,2,i),*fmpz_poly_get_coeff_ptr(y, i));
    for (int i=0; i<4; i++)
        fmpz_set_d(fmpz_mat_entry(M,3,i),*fmpz_poly_get_coeff_ptr(t, i));
    
    fmpz_mat_print(M); printf ( "\n" );

    fmpz_lll(M,N,fl);
    
    //fmpz_print(fmpz_mat_entry(M,0,0)); printf ( "\n" );

    fmpz_mat_print(M); printf ( "\n" );
    fmpz_mat_print(N); printf ( "\n" );
    
    fmpz_poly_clear ( x );
    fmpz_poly_clear ( y ); 
    fmpz_poly_clear ( z );
    fmpz_poly_clear (t);

    fmpz_mat_clear(M);
    fmpz_mat_clear(N);
    //fmpz_clear(coeff);

}