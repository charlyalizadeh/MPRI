# Binary Search Tree

## Regular BST

A binary search tree is a tree data structure where each node has a key greater than all the nodes on its left side of the tree. As you can see on the *Fig: 1* the root has a key of *4* wich is greater than the key of its left child (*2*) and less than the key of its right child (*6*).
```
              ┏━━━┓
        ╭─────┨ 4 ┠─────╮
        │     ┗━━━┛     │
      ┏━┷━┓           ┏━┷━┓
    ╭─┨ 2 ┠─╮       ╭─┨ 6 ┠─╮
    │ ┗━━━┛ │       │ ┗━━━┛ │
  ┏━┷━┓   ┏━┷━┓   ┏━┷━┓   ┏━┷━┓
  ┃ 1 ┃   ┃ 3 ┃   ┃ 5 ┃   ┃ 7 ┃
  ┗━━━┛   ┗━━━┛   ┗━━━┛   ┗━━━┛
  Fig 1: example of a perfect binary search tree
```

## AVL Tree

An AVL Tree is a binary search tree which balanced itself when adding/deleting a node.

## Implementation

To implement a binary search tree we use a class with three fields: 
* `value`: contains the key/value of the node
* `left`: pointer to its left child
* `right`: pointer to its right child
