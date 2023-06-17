class MyHashSet:
    def __init__(self, size):
        self.size = size
        self.slots = [None] * self.size

    def _hash(self, key):
        return key % self.size

    def _rehash(self, old_hash):
        return (old_hash + 1) % self.size

    def add(self, key):
        hash_value = self._hash(key)
        original_hash = hash_value

        while self.slots[hash_value] is not None:
            hash_value = self._rehash(hash_value)
            if hash_value == original_hash:
                print("Hash set is full. Unable to add key:", key)
                return

        self.slots[hash_value] = key
        print("Added key:", key)

    def remove(self, key):
        hash_value = self._hash(key)
        original_hash = hash_value

        while self.slots[hash_value] is not None:
            if self.slots[hash_value] == key:
                self.slots[hash_value] = None
                print("Removed key:", key)
                return
            hash_value = self._rehash(hash_value)
            if hash_value == original_hash:
                print("Key not found in the hash set:", key)
                return

        print("Key not found in the hash set:", key)

    def print_hash_set(self):
        for i, key in enumerate(self.slots):
            print("Slot", i, ":", key if key is not None else "()")


# Create a hash set with a specified size
hash_set = MyHashSet(10)

while True:
    print("Add a key")
    print("Remove a key")
    print("Print Hash Set")
    print("Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        key = int(input("Enter the key to add: "))
        hash_set.add(key)
    elif choice == "2":
        key = int(input("Enter the key to remove: "))
        hash_set.remove(key)
    elif choice == "3":
        hash_set.print_hash_set()
    elif choice == "4":
        print("Exiting")
        break
    else:
        print("Invalid  choice")
