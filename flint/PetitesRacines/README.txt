"Calcul de petites racines de p(x)=0 mod N"- link https://github.com/AsionNguyen/Project-C/tree/main/flint/PetitesRacines
					par NGUYEN Thi Thu Quyen (thi-thu-quyen.nguyen@polytechnique.edu)
			    		et CHARTOUNY Maya (mayachartouny@hotmail.com)
------------------------------------------------------------------------------------------------------------
+ M2_rapport.pdf: la théorie du projet, il donne le link GitHub du code à la page 22.

+ src: 
	- Makefile
	- test7.c : main code             %après compilation donne test7

+ figures: usage de test7
	- test1.png
	- test2.png
	- test3.png 			%faux représentation par type + segementation fault 
					%par dépassement de capacité du type fmpz

------------------------------------------------------------------------------------------------------------
+ Le programme utilise la librairie FLINT (http://www.flintlib.org/) pour des structures polynomials, 
  matricielles et des algorithmes de factorisation et de réduction de base dans Z[X]. 
  Plus détails se trouvent dans "M2_rapport.pdf".

+ Les structures sont à entrées du type fmpz qui est un slong 32 bits de l'intervalle [-2^31, +2^31]. 

+ Soit p(x)= x^2 + 14x + 19, p(x) dans FLINT est : 3  19 14 1

+ Compilation:
	- make test7 		          %qui donne test7

+ Test	
	- ./test7 a b c d 		  %détails dans M2_rapport.pdf page 21-22			
