#include <stdio.h>
#include <gmp.h>
#include <mpfr.h>


int main(int argc, char const *argv[])
{

    mpfr_t a_sum, b_sum, a_k, temp, total, pi;
    mpfr_t C3_OVER_24;
    unsigned long k = 1; 

    mpfr_set_default_prec(400);

    //initialise with values for k=0 value of sums
    mpfr_init_set_ui(a_sum, 1, MPFR_RNDD);
    mpfr_init_set_ui(b_sum, 0, MPFR_RNDN);
    mpfr_init_set_ui(a_k, 1, MPFR_RNDN);
    mpfr_init_set_ui(total, 0, MPFR_RNDD);
    mpfr_init(pi);
    mpfr_init(temp);
    mpfr_init(C3_OVER_24);

    //set C3_OVER_24 to (640320^3)/24
    mpfr_ui_pow_ui(C3_OVER_24, 640320, 3, MPFR_RNDD);
    mpfr_div_ui(C3_OVER_24, C3_OVER_24, 24, MPFR_RNDD);

    while(1)
    {

        mpfr_mul_si(a_k, a_k, -((6*k-5)*(2*k-1)*(6*k-1)), MPFR_RNDN);
        mpfr_div_ui(a_k, a_k, k*k*k, MPFR_RNDD);
        mpfr_div(a_k, a_k, C3_OVER_24, MPFR_RNDN);
        mpfr_add(a_sum, a_sum, a_k, MPFR_RNDN);

        mpfr_mul_ui(temp, a_k, k, MPFR_RNDN);
        mpfr_add(b_sum, b_sum, temp, MPFR_RNDN);
        k++;

        //mpfr_out_str(stdout, 10, 0, C3_OVER_24, MPFR_RNDD);

        if (k==2000000/*reached specified precision?*/)
        {
            break;
        }
    }

    mpfr_mul_ui(total, a_sum, 13591409, MPFR_RNDN);
    mpfr_mul_ui(b_sum, b_sum, 545140134, MPFR_RNDN);
    mpfr_add(total, total, b_sum, MPFR_RNDN);

    mpfr_sqrt_ui(pi, 10005, MPFR_RNDN);
    mpfr_mul_ui(pi, pi, 426880, MPFR_RNDN);
    mpfr_div(pi, pi, total, MPFR_RNDN);

    printf("\n");
    mpfr_out_str(stdout, 10, 0, pi, MPFR_RNDN);
    printf("\n");

    return 0;
}