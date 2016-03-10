class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    int next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        it = new Iterator(nums);
        nextIt = new Iterator(nums);
        if (nextIt->hasNext()) {
            nextValue = nextIt->next();
        }
    }

    int peek() {
        return nextValue; 
    }

    int next() {
        if (nextIt->hasNext()) {
            nextValue = nextIt->next();
        } else {
            nextValue = 0;
        }
        return it->next();
    }
    
    bool hasNext() const {
        return it->hasNext();
    }

private:
    Iterator *it;
    Iterator *nextIt;
    int nextValue = 0;
};
