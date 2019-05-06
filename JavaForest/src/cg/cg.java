package cg;

import cgNode.*;

import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class cg {
    protected cgNode _root;
    protected Set<cgNode> vars = new HashSet<cgNode>();

    private void note_var(cgNode node){
        if (node.is_var()){
            vars.add(node);
            return;
        }
        if (node.is_const()){
            return;
        }
        note_var(node.left());
        note_var(node.right());
    }

    protected void refresh_varset(){
        vars.clear();
        note_var(_root);
    }

    static private double compute_node(cgNode node){
        return node.compute(node.left().get_val(), node.right().get_val());
    }

    public cg(cgNode root){
        _root = root;
        refresh_varset();
        _root.trim();
    }

    public cg(dcg g) {
        _root = g._root;
        refresh_varset();
        _root.trim();
    }

    public cg copy(){
        return new cg(_root.copy(null));
    }

    public double compute(){return compute_node(_root);}
    public dcg diff(){
        cgNode rroot = _root.copy(null);
        rroot = rroot.diffor();
        dcg res = new dcg(rroot, varNode.get_map());
        varNode.clear_map();
        return res;
    }
}
