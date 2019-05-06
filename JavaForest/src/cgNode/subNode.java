package cgNode;

public class subNode extends cgNode {
    public subNode(cgNode parent, boolean lr, cgNode left, cgNode right){
        super(parent, lr, left, right, 0);
    }

    @Override
    public cgNode copy(cgNode parent){
        cgNode newnode = new subNode(parent, _left_or_right, null, null);
        newnode._left = _left.copy(newnode);
        newnode._right = _right.copy(newnode);
        return newnode;
    }

    @Override
    public double compute(double n1, double n2) {
        return n1 - n2;
    }

    @Override
    public cgNode diffor() {
        _left = _left.diffor();
        _right = _right.diffor();
        return this;
    }

    @Override
    public cgNode trim() {
        _left = _left.trim();
        _right = _right.trim();

        if (_left.is_n_node(0)){
            _left = new constNode(this, false, 0);
        }else if (_right.is_n_node(0)){
            return change_this(_left);
        }else if (_left.is_identical(_right)){
            return change_this(new constNode(_parent, _left_or_right, 0));
        }
        return this;
    }
}