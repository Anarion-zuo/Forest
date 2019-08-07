package com.Graph.SingleOpNodes;

import com.Graph.GraphNode;

public class ExpNode extends SingleOpNode {
    public ExpNode(GraphNode parent, GraphNode child) {
        super(parent, child);
    }

    @Override
    public Object clone() {
        return new ExpNode(null, (GraphNode) _child.clone());
    }

    @Override
    public void compute() {
        _child.compute();
        _val = Math.exp(_child.get_val());
    }

    @Override
    public void diff() {

    }

    @Override
    public void trim() {

    }
}
