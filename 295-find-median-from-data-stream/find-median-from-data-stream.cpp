class MedianFinder {
public:
    //left max-heap bnao  aur right min-heap bnao
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }

        //humesha left max-heap ki size right min-heap se ek badi hi rahegi always...ya fir dono ki size equal ho jaayegi
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()>1)){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }

        else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()){
            //even number of ele
            double mean = (left_max_heap.top()+ right_min_heap.top())/2.0;
            return mean;
        }
        else return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */