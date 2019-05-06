package cgNode;

public class constNode extends cgNode {
    @Override
    public boolean is_n_node(double n){
        return nequals(_val, n);
    }

    @Override
    public boolean equals(Object node){
        if (node instanceof constNode){
            return _val == ((constNode) node)._val;
        }
        return false;
    }

    @Override
    public boolean is_identical(cgNode node){
        if (!(node instanceof constNode)){
            return false;
        }
        return _val == node._val;
    }

    public constNode(cgNode parent, boolean lr, double val){
        super(parent, lr, null, null, val);
    }

    @Override
    public cgNode copy(cgNode parent){
        return new constNode(parent, _left_or_right, _val);
    }

    @Override
    public cgNode diffor() {
        _val = 0;
        return this;
    }

    @Override
    public cgNode trim() {
        return this;
    }

    @Override
    public boolean is_const() {
        return true;
    }
}
