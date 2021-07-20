class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.buckets = [[]] * 1000
        

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        index = key % 1000
        if key not in self.buckets[index]:
            self.buckets[index].append(key)
        

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        index = key % 1000
        if key in self.buckets[index]:
            self.buckets[index].remove(key)

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        index = key % 1000
        return key in self.buckets[index]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
