package com.Graph.OpNodes;

import com.Graph.GraphNode;

import java.util.ArrayList;
import java.util.Arrays;

public class MultiplyNode extends GraphNode {
    protected GraphNode _left;
    protected GraphNode _right;

    public MultiplyNode(GraphNode parent, GraphNode left, GraphNode right){
        super(parent, new ArrayList<>(Arrays.asList(left, right)));
        _left = left;
        _right = right;
    }

    @Override
    public Object clone() {
        return new MultiplyNode(null, (GraphNode)_left.clone(), (GraphNode)_right.clone());
    }

    @Override
    public void compute() {
        _left.compute();
        _right.compute();
        _val = _left.get_val() * _right.get_val();
    }

    @Override
    public void diff() {
    }

    @Override
    public void trim() {

    }
}
