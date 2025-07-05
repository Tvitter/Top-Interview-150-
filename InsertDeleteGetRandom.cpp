class RandomizedSet {
public:
    unordered_map<int, bool> um;

    RandomizedSet() {
        // Constructor should initialize the object, no need to create a new one.
    }

    bool insert(int val) {
        if (um.find(val) == um.end()) {
            um[val] = true;
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        if (um.find(val) != um.end()) {
            um.erase(val);
            return true;
        } else {
            return false;
        }
    }

    int getRandom() {
        int N = um.size();
        int temp = rand() % N;
        auto it = um.begin();
        advance(it, temp);
        return it->first;
    }
};
/*1. unordered_map<int, bool> um
This is a hash map that stores numbers (int) as keys and true as values (we don’t really need the value, but it helps in checking if a number exists).

2. insert(val)
Checks if val does not exist in um (um.find(val) == um.end()).

If not present, adds val to um and returns true.

If already present, returns false (no duplicates allowed).

3. remove(val)
Checks if val exists in um (um.find(val) != um.end()).

If exists, removes it and returns true.

If doesn’t exist, returns false.

4. getRandom()
Gets a random number from the set with equal chance for all numbers.

um.size() → Total numbers in the set.

rand() % N → Picks a random index (0 to N-1).

um.begin() → Points to the first element.

advance(it, temp) → Moves the iterator temp steps forward.

Returns the number at that position (it->first).*/