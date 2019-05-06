package cgNode;

import org.jetbrains.annotations.NotNull;

public class cgNode {
    protected double _val;
    protected cgNode _left;
    protected cgNode _right;
    protected cgNode _parent;

    public cgNode(){
        _right = null;
        _left = null;
        _val = 0;
    }

    public cgNode(cgNode parent, cgNode left, cgNode right, double val){
        _val = val;
        _left = left;
        _right = right;
        _parent = parent;
    }

    public cgNode(@NotNull cgNode node){
        _val = node._val;
        _left = node._left;
        _right = node._right;
        _parent = node._parent;
    }

    public double compute(double n1, double n2){
        return _val;
    }

    public cgNode trim(){
        return this;
    }

    public cgNode diffor(){
        return this;
    }

    public cgNode clone() throws CloneNotSupportedException {
        return new cgNode(this);
    }
}
