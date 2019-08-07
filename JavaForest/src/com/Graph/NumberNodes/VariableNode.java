package com.Graph.NumberNodes;

import com.Graph.GraphNode;

public class VariableNode extends GraphNode {
    protected Variable _var;

    public VariableNode(GraphNode parent, Variable var){
        super(parent, null);
        _var = var;
    }

    @Override
    public Object clone() {
        return new VariableNode(null, _var);
    }

    @Override
    public void compute() {
        _val = _var.get_val();
    }

    @Override
    public void diff() {

    }

    @Override
    public void trim() {

    }
}
