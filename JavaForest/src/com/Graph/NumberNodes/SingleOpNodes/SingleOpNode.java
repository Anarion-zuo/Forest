package com.Graph.NumberNodes.SingleOpNodes;

import com.Graph.GraphNode;

import java.util.ArrayList;

abstract class SingleOpNode extends GraphNode {
    protected GraphNode _child;
    public SingleOpNode(GraphNode parent, GraphNode child) {
        super(parent, new ArrayList<>());
        super._childs.add(child);
        _child = child;
    }
}
