#include "Basic_OP_Functors.h"

Functor* Add_Functor::p = new Add_Functor();
double Add_Functor::f(double n1, double n2) {
	return n1 + n2;
}

Functor* Add_Functor::get() {
	return p;
}

Functor* Sub_Functor::p = new Sub_Functor();
double Sub_Functor::f(double n1, double n2) {
	return n1 - n2;
}

Functor* Sub_Functor::get() {
	return p;
}