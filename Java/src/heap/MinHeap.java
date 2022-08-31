package heap;

public class MinHeap extends AbstractHeap<Integer> {
    public MinHeap() {
        super();
    }

    @Override
    protected boolean compare(Integer data1, Integer data2) {
        return data1 > data2;
    }
}