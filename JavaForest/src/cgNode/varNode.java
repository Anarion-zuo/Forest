package cgNode;

import java.util.HashMap;
import java.util.Map;

public class varNode extends cgNode {
    @Override
    public boolean is_n_node(double n){
        return nequals(_val, n);
    }
    static private Map<cgNode, varNode> dvars_map = new HashMap<cgNode, varNode>();
    static public void clear_map(){dvars_map.clear();}
    static public Map<cgNode, varNode> get_map(){return new HashMap<cgNode, varNode>(dvars_map);}

    @Override
    public boolean equals(Object node){
        return this == node;
    }

    @Override
    public boolean is_identical(cgNode node){
        return this == node;
    }

    public varNode(cgNode parent, boolean lr, double val){
        super(parent, lr, null, null, val);
    }

    @Override
    public cgNode copy(cgNode parent){
        return this;
    }

    @Override
    public cgNode diffor() {
        varNode res = new varNode(_parent, _left_or_right, 0);
        dvars_map.put(this, res);
        return res;
    }

    @Override
    public cgNode trim() {
        return this;
    }

    @Override
    public boolean is_var() {
        return true;
    }
}
