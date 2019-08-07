package com.Graph.NumberNodes;

import com.Graph.GraphNode;

import java.util.HashMap;

public class Variable {
    protected double _val;

    static HashMap<Variable, Variable> _diff_map;

    public Variable(double val){
        _val = val;
    }

    public double get_val(){
        return _val;
    }

    public void set_val(double val){
        _val = val;
    }

    public Variable diff(){
        Variable d = _diff_map.get(this);
        if (d == null){
            d = new Variable(0);
            _diff_map.put(this, d);
        }
        return d;
    }
}
