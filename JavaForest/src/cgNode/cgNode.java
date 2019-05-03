package cgNode;

import Diffor.*;
import Functor.*;
import Trimor.*;

public class cgNode {
    protected double _val = 0;
    protected cgNode _left = null;
    protected cgNode _right = null;
    protected Functor _func = null;
    protected Diffor _diffor = null;
    protected Trimor _trimor = null;

    public cgNode(cgNode left, cgNode right, Functor func, Diffor diffor, Trimor trimor, double val){
        _val = val;
        _left = left;
        _right = right;
        _func = func;
        _diffor = diffor;
        _trimor = trimor;
    }

    public cgNode(cgNode node){
        _val = node._val;
        _left = node._left;
        _right = node._right;
        _func = node._func;
        _diffor = node._diffor;
        _trimor = node._trimor;
    }

    public cgNode trim(){
        return this;
    }

//    public cgNode clone(){
//
//    }
}
