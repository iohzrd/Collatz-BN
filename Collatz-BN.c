/* Collatz-BN.c - Created by Adam Stohl - 2016 */

#include<stdio.h>
#include<stdbool.h>
#include<gmp.h>

mpz_t n;

static mpz_t *collatz_length()
{
  if (mpz_odd_p(n) == 0) //even
  {
  mpz_tdiv_q_ui(n, n, 2);
  }
  else if (mpz_even_p(n) == 0) //odd
  {
  mpz_mul_ui(n, n, 3);
  mpz_add_ui(n, n, 1);
  }

  return (void *)n;
}

int main()
{
  while(true)
  {
    unsigned long i = 1;

    printf("Test # ");
    gmp_scanf("%Zd", n);

    while(mpz_cmp_ui(n, 1) == 1)
    {
      collatz_length(n);
      ++i;
    }

    printf("iterations before termination = %lu\n", i);
    gmp_printf("N terminated at = %Zd\n", n);
  }

  mpz_clear(n);
}
