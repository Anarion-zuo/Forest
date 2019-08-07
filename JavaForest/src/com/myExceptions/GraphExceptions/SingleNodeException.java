package com.myExceptions.GraphExceptions;

public class SingleNodeException extends RuntimeException {
    static final long serialVersionUID = 561618612;

    public SingleNodeException(){

    }

    @Override
    public String getMessage(){
        return "The operator node is supposed to handle a node returning a single value, instead of a vector.";
    }
}
