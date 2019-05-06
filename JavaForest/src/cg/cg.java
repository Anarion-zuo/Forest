package cg;

import cgNode.*;

public class cg {
    protected cgNode _root;

    static private double compute_node(cgNode node){
        return node.compute(node.left().get_val(), node.right().get_val());
    }

    public cg(cgNode root){
        _root = root;
    }

    public double compute(){return compute_node(_root);}
}
