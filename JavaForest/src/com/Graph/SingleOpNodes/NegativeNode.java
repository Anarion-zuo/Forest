package com.Graph.SingleOpNodes;

import com.Graph.GraphNode;

public class NegativeNode extends SingleOpNode {
    public NegativeNode(GraphNode parent, GraphNode child) {
        super(parent, child);
    }

    @Override
    public Object clone() {
        return new NegativeNode(null, (GraphNode) _child.clone());
    }

    @Override
    public void compute() {
        _child.compute();
        _val = -_child.get_val();
    }

    @Override
    public void diff() {
        _child.compute();
    }

    @Override
    public void trim() {

    }
}
