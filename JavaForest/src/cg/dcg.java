package cg;
import cgNode.*;

import java.util.HashMap;
import java.util.Map;

public class dcg extends cg {
    protected Map<cgNode, varNode> _dvars;

    static private void var2const(cgNode node){
        if (node.is_var()) {
            if (node.get_val() == 0) {
                node.change_this(new constNode(node.get_parent(), node.get_left_right(), 0));
            }
            return;
        }
        if (node.is_const()){
            return;
        }
        var2const(node.left());
        var2const(node.right());
    }

    public dcg(cgNode node, Map<cgNode, varNode> dvars){
        super(node);
        _dvars = dvars;
    }

    public dcg copy(){
        cgNode r = _root.copy(null);
        return new dcg(r, new HashMap(_dvars));
    }

    public cg single_var_cg(cgNode var){ //first derivative
        dcg dg = copy();
        var2const(dg._root);
        cg g = new cg(dg._root);
        return g;
    }

    public double single_var_cg_compute(cgNode var){
        return single_var_cg(var).compute();
    }
}
