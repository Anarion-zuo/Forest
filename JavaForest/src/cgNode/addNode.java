package cgNode;

public class addNode extends cgNode {
    public addNode(cgNode left, cgNode right){
        super(left, right, new addFunctor, new addDiffor, new addTrimor, 0);
    }
}