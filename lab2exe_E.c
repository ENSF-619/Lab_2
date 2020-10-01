/*
 * lab2exe_E.c
 * Implementation file for complex number module
 *
 * ENSF 619 Fall 2020 Lab 2 Exercise E
 */

#include "lab2exe_E.h"

struct cplx
cplx_add(struct cplx z1, struct cplx z2)
{
  struct cplx result;

  result.real = z1.real + z2.real;
  result.imag = z1.imag + z2.imag;
  return result;
}
void
cplx_subtract(struct cplx z1, struct cplx z2, struct cplx* difference) {
	struct cplx result;
	difference->real= z1.real - z2.real;
	difference->imag = z1.imag - z2.imag;
}
void
cplx_multiply(const struct cplx* pz1,const struct cplx* pz2,struct cplx* product)
{
	product->real = (pz1->real * pz2->real) - (pz1->imag * pz2->imag);
	product->imag = (pz1->real * pz2->imag) + (pz1->imag * pz2->real);
}