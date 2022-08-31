package heap;

public class MaxHeap extends AbstractHeap<Integer> {
    public MaxHeap() {
        super();
    }

    @Override
    protected boolean compare(Integer data1, Integer data2) {
        return data1 > data2;
    }
}
