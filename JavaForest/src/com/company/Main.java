package com.company;
import cgNode.*;
import cg.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
        cg a = new cg(new varNode(null, false, 1));
        dcg b = a.diff();
    }
}
