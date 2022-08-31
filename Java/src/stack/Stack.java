package stack;

public class Stack<T> {
    private T[] array;
    private int tail;
    private int size;
    private int capacity;
    public static final int DEFAULT_CAPACITY = 10;

    public Stack() {
        this(DEFAULT_CAPACITY);
    }
    public Stack(int capacity) {
        this.capacity = capacity;
        this.array =(T[]) new Object[capacity];
        this.tail = -1;
    }
    public void push(T data) {
        this.size++;
        if(isFull()) {
            expansionList();
        }
        this.array[++tail] = data;
    }
    public T peek() {
        if(isEmpty()) {
            return null;
        }
        return array[tail];
    }

    public T pop() {
        if(isEmpty()) {
            return null;
        }

        size--;
        T data = array[tail--];
        return data;
    }
    public boolean isEmpty() {
        return size == 0;
    }
    public boolean isFull() {
        return size == capacity;
    }

    private void expansionList() {
        T[] tmpArray = this.array;

        this.capacity *= 2;
        array = (T[]) new Object[capacity];

        this.array = copyArray(tmpArray, this.array);

    }
    private T[] copyArray(T[]array, T[]copiedArray) {
        for(int i = 0; i<array.length; i++) {
            copiedArray[i] = array[i];
        }
        return copiedArray;
    }

}
