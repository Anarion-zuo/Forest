package com.Graph.OpNodes;

import com.Graph.GraphNode;
import com.Graph.NumberNodes.ConstNode;
import com.myExceptions.GraphExceptions.SingleNodeException;

import java.util.ArrayList;

public class SummationNode extends GraphNode {

    public SummationNode(GraphNode parent, ArrayList<GraphNode> childs){
        super(parent, childs);
    }

    @Override
    public Object clone() {
        return new SummationNode(null, (ArrayList<GraphNode>) _childs.clone());
    }

    @Override
    public void compute() {
        for (GraphNode child : _childs) {
            child.compute();
//            if (!child.is_const()){
//                throw new SingleNodeException();
//            }
        }

        double res = 0;
        for (GraphNode child : _childs){
            res += child.get_val();
        }
        _val = res;
    }

    @Override
    public void diff(){
        for (GraphNode child : _childs){
            child.diff();
        }
    }

    @Override
    public void trim(){

    }
}
