# Priority Tree

> From DSA 2021: Problem 5 - Alice's Bookshelf

## Problem Statement

- **A Bookshelf**

    |Position|1|2|3|4|5|...|n|
    |---|---|---|---|---|---|---|---|
    |Priority|-1|0|0|3|4|...|1|


- **A book**
    ```julia
    struct Book{
        position
        priority
    }
    ```

- **Priority** 
  - **not unique**
  - When queuing books with **same priority**
    **extract the one with least position**.
- **Position**
  - Start from `1`
  - Insert `0` means insertion at start.

## Operation

- `1 p k`: **insert** a `book(priority=p,position=k)`. 
  - When `k=0`, insert at start
- `2 k`: **Delete** the `k-th` book.
- `3 l r p`: **Increase priorities** by `p` between `[l,r]`
- `4 l r`: Query the **largest priority**  between `[l,r]`
- `5 l r`: Reverse the positions between `[l,r]`
- `6`: Remove the largest priority


## Strategy


### Insert

**Description**


For insert node at `book(pos=18, prio=20)`
<center>
<img height=250 src="https://img-blog.csdn.net/20151103185313376?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast">
</center>



**Algorithm**

1. Search and Create `pos=18` (BST serach). [`n_new`]
2. Correct Heap
   - **Case 1**: `n_new.key` < `n_new.parent.key`
     - Do nothing
   - **Case 2**: `n_new.key` > `n_new.parent.key` and `n_new` is on the right
     - `LeftRotate(n_new.parent)` to pick `n_new` up
     - Repeat 2.
   - **Case 3**: invert left right in **Case 3**  



**Complexity**



### Delete

**Description**
**Algorithm**
**Complexity**



### Increase Priority

**Description**


**Algorithm**


**Complexity**



### Query largest

**Description**
- Query the largest priority between the positions `l` and `r`.
    ```c
    Query(l, r)
    ```

**Algorithm**

1. Search first element in [l,r]
   ```c
   node search_node_in_region(root, l, r)
   ```



**Complexity**

### Reverse order
**Description**
**Algorithm**
**Complexity**



## Helper functions

#### Get first position
- Leftist position under root `x`
    ```cpp
    node FirstPosition(x)
        while x.left != NULL
            x = x.left
        return x
    end
    ```

#### Search Position

- Record **Number of nodes under node x**

#### Search Highest Priority

- Search node with key=`x` within `[lp, hp]` with **highest level**. Return `NULL` if not item found.
    ```cpp
    node TreeSearchDomain(x, lp, hp)
        if x == NULL
            return x
        else if isBelong(x,lp,hp)
            return x
        else if x > max(lp,hp)
            return TreeSearchDomain(x.right, lp,hp)
        else 
            return TreeSearchDomain(x.left, lp,hp)
    end
    ```
- Usage
  - Query the largest books between position `l` and `r`
- Time
  - `O(log n)`
- Ref: Binary search in BST




---

## Note

### Invet Binary Tree

```python
class Solution:
    def invertTree(self, root):
        if root is None:
            return None
        root.left, root.right = \
            self.invertTree(root.right), self.invertTree(root.left)
        return root
```

1. [LeetCode](https://leetcode.com/problems/invert-binary-tree/solution/)

### Treap Data Structure

> A treap is a binary tree that maintains simultaneously the property of binary search tree (BST) and heap.


**Ref:** 
1. [medium](https://medium.com/carpanese/a-visual-introduction-to-treap-data-structure-part-1-6196d6cc12ee)
2. [Treap. Wiki](https://en.wikipedia.org/wiki/Treap)
3. [Treap. CP-Aglorithms](https://cp-algorithms.com/data_structures/treap.html)
4. [Treap. ITREAD](https://www.itread01.com/content/1545721233.html)


## Reference

- Invert BST: https://afteracademy.com/blog/invert-a-binary-tree
- Cartesian heaps:https://cp-algorithms.com/data_structures/treap.html

### Treap and Implicity Treap
1. [Treap (Cartesian tree). CP-Algorithm](https://cp-algorithms.com/data_structures/treap.html#toc-tgt-1)
2. [Treaps : One Tree to Rule ’em all ..!! Part-1](https://tanujkhattar.wordpress.com/2016/01/10/treaps-one-tree-to-rule-em-all-part-1/)
3. [Treaps : One Tree to Rule ’em all ..!! Part-2](https://tanujkhattar.wordpress.com/2016/01/10/treaps-one-tree-to-rule-em-all-part-2/)
4. [Episode 30 - Treaps. YouTube](https://youtu.be/erKlLEXLKyY?t=1785)
5. [A Visual Introduction to Treap Data Structure (Part I: The Basics). Medium](https://medium.com/carpanese/a-visual-introduction-to-treap-data-structure-part-1-6196d6cc12ee)