package com.Graph;

import java.util.ArrayList;

abstract public class GraphNode implements Cloneable {
    protected ArrayList<GraphNode> _childs;
    protected GraphNode _parent;
//    protected GraphNode _result = null;
    protected double _val = 0;

    public GraphNode(GraphNode parent, ArrayList<GraphNode> childs) {
        _parent = parent;
        _childs = childs;
    }

    @Override
    abstract public Object clone();

    // calculations
    public abstract void compute();
    public abstract void diff();
    abstract public void trim();

    // checks
    public boolean is_const(){
        return false;
    }
    public boolean is_var(){
        return false;
    }
    public boolean is_num(){
        return false;
    }

    // get set
    public double get_val(){
        return _val;
    }
    public void set_val(double val){
        _val = val;
    }

    public GraphNode get_child(int index){
        return _childs.get(index);
    }

    public void set_child(int index, GraphNode child){
        _childs.add(index, child);
    }

    public GraphNode get_parent(){
        return _parent;
    }

    public ArrayList<GraphNode> get_childs(){
        return _childs;
    }

    public int get_position(){
        ArrayList childs = _parent.get_childs();
        for (int i = 0; i < childs.size(); ++i){
            if (childs.get(i) == this){
                return i;
            }
        }
        return childs.size();
    }

    // statics

    static public void change_to(GraphNode oldnode, GraphNode newnode){
        int pos = oldnode.get_position();
        GraphNode parent = oldnode.get_parent();
        parent.set_child(pos, newnode);
    }

}
