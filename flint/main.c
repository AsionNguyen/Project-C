# include "fmpz_poly.h"

int main(){
    fmpz_poly_t x , y ;
    fmpz_poly_init ( x );
    fmpz_poly_init ( y );
    fmpz_poly_set_coeff_ui (x , 3 , 5);
    fmpz_poly_set_coeff_si (x , 0 , -1);
    fmpz_poly_mul (y , x , x );
    fmpz_poly_print ( x ); printf ( "\n" );
    fmpz_poly_print ( y ); printf ( "\n" );
    fmpz_poly_clear ( x );
    fmpz_poly_clear ( y );
}