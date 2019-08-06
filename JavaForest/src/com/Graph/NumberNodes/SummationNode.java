package com.Graph.NumberNodes;

import com.Graph.GraphNode;

import java.util.ArrayList;

public class SummationNode extends GraphNode {

    public SummationNode(GraphNode parent, ArrayList<GraphNode> childs){
        super(parent, childs);
    }

    @Override
    public void compute() {
        for (GraphNode it : _childs){
            it.compute();
            if (it.)
        }
    }

    @Override
    public void diff(){

    }

    @Override
    public void trim(){

    }
}
