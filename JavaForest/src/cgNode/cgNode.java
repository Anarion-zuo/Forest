package cgNode;

import org.jetbrains.annotations.NotNull;

public class cgNode {
    protected double _val;
    protected cgNode _left;
    protected cgNode _right;
    protected cgNode _parent;
    protected boolean _left_or_right;

    static boolean nequals(double n1, double n2){
        final double epsilon = 1e-14D;
        return Math.abs(n1 - n2) < epsilon;
    }

    // only for constNode, others return false
    protected boolean is_n_node(double n){
        return false;
    }

    @Override //leaf nodes should be comparing _val
    public boolean equals(Object node){
        if (node instanceof cgNode){
            return _left == ((cgNode) node)._left && _right == ((cgNode) node)._right;
        }
        return false;
    }

    protected boolean is_identical(cgNode node){  //leaf nodes should be comparing _val or address
        return _left.is_identical(node._left) && _right.is_identical(node._right);
    }

    public cgNode(cgNode parent, boolean lr, cgNode left, cgNode right, double val){
        _val = val;
        _left = left;
        _right = right;
        _parent = parent;
        _left_or_right = lr;
    }

    public cgNode(cgNode node){
        _val = node._val;
        _left = node._left;
        _right = node._right;
        _parent = node._parent;
        _left_or_right = node._left_or_right;
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

    public cgNode change_this(cgNode node){
        if (_left_or_right){
            _parent._right = node;
        }else{
            _parent._left = node;
        }
        node._left_or_right = _left_or_right;
        node._parent = _parent;
        return node;
    }

    public cgNode copy(cgNode parent){
        return new cgNode(this);
    }

    public void add_child(cgNode node, boolean lr){
        if (lr){
            _right = new
        }
    }

    public double get_val(){return _val;}
    public void set_val(double n){_val = n;}
    public cgNode get_parent(){return _parent;}
    public boolean get_left_right(){return _left_or_right;}

    public cgNode left(){return _left;}
    public cgNode right(){return _right;}
    public boolean is_var(){return false;}
    public boolean is_const(){return false;}
}
