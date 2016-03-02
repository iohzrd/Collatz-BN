/* Collatz-BN-Auto.c - Created by Adam Stohl - 2016 */

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
  mpz_t start;
  mpz_init_set_str (start, "100000000000000000000", 10);
  mpz_t end;
  mpz_init_set_str (end,   "1000000000000000000000", 10);

  unsigned long i;

  while(mpz_cmp(end, start) == 1)//(true)
  {
    i = 1;
    mpz_init_set(n, start);
    gmp_printf("testing # %Zd\n", n);

    while(mpz_cmp_ui(n, 1) == 1)
    {
      collatz_length(n);
      ++i;
    }

    printf("iterations before termination = %lu\n", i);
    mpz_add_ui(start, start, 1);
    gmp_printf("N terminated at = %Zd\n\n", n);
  }

  mpz_clear(n);
}
