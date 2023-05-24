package Trees;

public class AVLTree {
    private int key, height;
    private AVLTree left, right;

    public static final AVLTree NIL = new AVLTree();

    public AVLTree(int key) {
        this.key = key;
        left = right = NIL;
    }

    public AVLTree() {
        left = right = this;
        height = -1;
    }

    public int size() {
        if (this == NIL)
            return 0;
        return 1 + left.size() + right.size();
    }

    public String toString() {
        if (this == NIL)
            return "";
        return left + " " + key + " " + right;
    }

    public AVLTree(int key, AVLTree left, AVLTree right) {
        this.key = key;
        this.left = left;
        this.right = right;
        height = 1 + Math.max(left.height, right.height);
    }

    public boolean add(int key) {
        int oldSize = size();
        grow(key);
        return size() > oldSize;
    }

    public AVLTree grow(int key) {
        if (this == NIL)
            return new AVLTree(key);
        if (key == this.key)
            return this;
        if (key < this.key)
            left = left.grow(key);
        else
            right = right.grow(key);
        rebalance();
        height = 1 + Math.max(left.height, right.height);
        return this;
    }

    public AVLTree rebalance() {
        if (right.height > left.height + 1) {
            if (right.left.height > right.right.height) {
                right.rotateRight();
            }
            rotateLeft();
        } else if (left.height > right.height + 1) {
            if (left.right.height > left.left.height) {
                left.rotateLeft();
            }
            rotateRight();
        }
        return this;
    }

    public AVLTree rotateRight() {
        left = new AVLTree(key, left, right.left);
        key = right.key;
        right = right.right;
        return this;
    }

    public AVLTree rotateLeft() {
        right = new AVLTree(key, left.right, right);
        key = left.key;
        left = left.left;
        return this;
    }

    public boolean remove(int key) {
        int oldSize = size();
        shrink(key);
        return size() < oldSize;
    }

    public AVLTree shrink(int key) {
        if (this == NIL)
            return NIL;
        if (key == this.key) {
            if (left == NIL && right == NIL)
                return NIL;
            if (left == NIL)
                return right;
            if (right == NIL)
                return left;
            this.key = right.min().key;
            right = right.removeMin();
        } else if (key < this.key) {
            left = left.shrink(key);
        } else {
            right = right.shrink(key);
        }
        rebalance();
        height = 1 + Math.max(left.height, right.height);
        return this;
    }

    public AVLTree removeMin() {
        if (left == NIL)
            return right;
        left = left.removeMin();
        rebalance();
        height = 1 + Math.max(left.height, right.height);
        return this;
    }

    public AVLTree min() {
        if (left == NIL)
            return this;
        return left.min();
    }
}
