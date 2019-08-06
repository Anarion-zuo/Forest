package com.Graph;

import java.util.ArrayList;

abstract public class GraphNode implements Cloneable {
    protected ArrayList<GraphNode> _childs;
    protected GraphNode _parent;
    protected GraphNode _result = null;

    public GraphNode(GraphNode parent, ArrayList<GraphNode> childs) {
        _parent = parent;
        _childs = childs;
    }

    // calculation
    public abstract void compute();
    public abstract void diff();
    abstract public void trim();
}
