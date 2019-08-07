package com.Graph.NumberNodes;

import com.Graph.GraphNode;

public class ConstNode extends GraphNode {
    protected double _val = 0;

    public ConstNode(GraphNode parent, double val){
        super(parent, null);
        _val = val;
    }

    @Override
    public Object clone() {
        return new ConstNode(null, _val);
    }

    @Override
    public void compute() {

    }

    @Override
    public void diff() {
        _val = 0;
    }

    @Override
    public void trim() {

    }
}
