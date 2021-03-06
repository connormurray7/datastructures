"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python implementation of a Hash map with chaining.
"""


class HashMap:
    """Python implementation of a Hash map with chaining.

    There is the possibility of collisions, in which case the
    class chains together nodes

    Attributes:
        load_factor: maximum ratio until the list doubles in size.
        buckets: list as the underlying data structure.
        size: how many elements currently in the set.
        max_size: size of the container.
    """
    class Node:
        """Used to chain data together"""
        def __init__(self, data):
            self.data = data
            self.next = None

    def __init__(self, init_size=16, hash_function=None, load_factor=0.75):
        self.load_factor = load_factor
        self.size = 0
        self.max_size = init_size
        self.buckets = [None]*init_size
        if hash_function is None:
            self.hash = lambda x: x % self.max_size
        else:
            self.hash = hash_function

    def __str__(self):
        """String representation of set"""
        vals = []
        for bucket in self.buckets:
            if bucket is not None:
                vals.append(bucket)
        out_str = ' '.join([str(v) for v in vals])
        return "Hashset [" + out_str + "]"

    def __getitem__(self, key):
        """Overloads operator [] for amortized O(1) access, O(n) worst case"""
        return self.get(key)

    def __setitem__(self, key, val):
        """Overloads operator [] for amortized O(1) insertion, O(n) worst case"""
        self.add(key, val)

    def grow(self):
        """Doubles size of container, O(n)"""
        self.max_size *= 2
        tmp = self.buckets
        self.buckets = [None]*self.max_size

        for node in tmp:
            self.buckets.add(node.key, node.val)

    def add(self, key, val):
        """Amortized O(1) addition to dict, if container too full, calls grow"""
        if self.size/self.max_size > self.load_factor:
            self.grow()
        bucket = self.hash(key)
        if self.buckets[bucket] is not None:
            node = self.buckets[bucket]
            while node:
                last = node
                node = node.next  # Get to the end of the chain
            last.next = self.Node((key, val))
        else:
            self.buckets[bucket] = self.Node((key, val))
        self.size += 1

    def remove(self, key):
        """Amortized O(1) removal of key-val pair, O(n) worst case """
        bucket = self.hash(key)
        node = self.buckets[bucket]
        if node is not None:
            while node:
                prev = node
                if node.data[0] == key:
                    self.buckets[bucket] = None
                    self.size -= 1
                    if node != prev:  # first iteration
                        prev.next = node.next
                node = node.next

    def get(self, key):
        """Amortized O(1) retrieval of key-val pair, O(n) worst case """
        bucket = self.hash(key)
        if self.buckets[bucket] is None:
            return None
        node = self.buckets[bucket]
        while node:
            if node.data[0] == key:
                return node.data[1]
            node = node.next
        return None
