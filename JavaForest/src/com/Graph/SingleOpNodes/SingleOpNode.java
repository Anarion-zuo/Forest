package com.Graph.SingleOpNodes;

import com.Graph.GraphNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

abstract class SingleOpNode extends GraphNode {
    protected GraphNode _child;
    public SingleOpNode(GraphNode parent, GraphNode child) {
        super(parent, new ArrayList<>(Collections.singletonList(child)));
        _child = child;
    }
}
