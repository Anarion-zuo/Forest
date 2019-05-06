package cgNode;

public class mulNode extends cgNode {
    public mulNode(cgNode parent, boolean lr, cgNode left, cgNode right){
        super(parent, lr, left, right, 0);
    }

    @Override
    public cgNode copy(cgNode parent){
        cgNode newnode = new mulNode(parent, _left_or_right, null, null);
        newnode._left = _left.copy(newnode);
        newnode._right = _right.copy(newnode);
        return newnode;
    }

    @Override
    public double compute(double n1, double n2) {
        return n1 * n2;
    }

    @Override
    public cgNode diffor() {
        cgNode res = new addNode(_parent, _left_or_right, null, null);
        cgNode rleft = new mulNode(res, false, null, null);
        cgNode rright = new mulNode(res, true, null, null);
        res._left = rleft;
        res._right = rright;
        rleft._left = _left.copy(rleft);
        rleft._right = _right.copy(rleft);
        rright._left = _left.copy(rright);
        rright._right = _right.copy(rright);
        rleft._left = rleft._left.diffor();
        rright._right = rright._right.diffor();
        return change_this(res);
    }

    @Override
    public cgNode trim() {
        _left = _left.trim();
        _right = _right.trim();

        if (_left.is_n_node(0)){
            return change_this(new constNode(_parent, _left_or_right, 0));
        }else if (_right.is_n_node(0)){
            return change_this(new constNode(_parent, _left_or_right, 0));
        }else if (_left.is_identical(_right)){
            cgNode newnode = new expNode(_parent, _left_or_right, _left, new constNode(null, true, 0));
            newnode._right = newnode;
            return change_this(newnode);
        }

        return this;
    }
}
