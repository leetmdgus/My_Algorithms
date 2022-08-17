package tree.binaryTreeWithNode.segment.rmq;

import java.util.ArrayList;
import java.util.Collections;

public class RMQ {
    int n;
    ArrayList<Integer> rangeMin;
    RMQ(ArrayList<Integer> array) {
        n = array.size();
        rangeMin = new ArrayList<>();
    }
}
