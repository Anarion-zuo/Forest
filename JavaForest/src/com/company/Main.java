package com.company;
import cgNode.*;

class A {}
class B extends A{}

public class Main {

    public static void main(String[] args) {
	// write your code here
        B a = new B();
        boolean p = a instanceof A;
    }
}
